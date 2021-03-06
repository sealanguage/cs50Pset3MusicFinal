// Helper functions for music

#include <cs50.h>
#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numer = atoi(&fraction[0]);
    int denom = atoi(&fraction[2]);

    int frac = (8/denom) * numer;
    return frac;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter = 0;
    char accidental = 0;
    float octave = 0.0;

    if (strlen(note) == 3)
    {
        letter = note[0];
        accidental = note[1];
        octave = atoi(&note[2]);
    }

    if (strlen(note) == 2)
    {
        letter = note[0];
        octave = atoi(&note[1]);
    }

    // find the hz value for each octave
    int octcount = 0;
    float hz = 0.0;

    if (octave == 4.0)
    {
        octcount = (octave - 4.0);
        hz = 440.00 * pow(2, octcount);
    }

     // do the math if octave is > 4 -- 440 x 2 for each number more than 4; / 2 for each counter less than 4
    // gets octave and letter, does math to get setps from A4, does not calculate pow of 2 to 440.

    else if (octave > 4.0)
    {
        octcount = (octave - 4.0);
        hz = 440.00 * pow(2, octcount);
    }

    else if (octave < 4.0)
    {
        octcount = 4.0 - octave;
        hz = 440.00 / pow(2, octcount);
    }


    // for each note, take octave hz x 2 x/12 to get hz; return hz

    float hertz = 0.0;
    float numerator = 0.0;
    float themath = pow(2.0, (numerator/12));


   switch (letter)
    {
        case 'C':
        // code to be executed if n is equal to C;
        {
            printf("C octave before = %.2f, hz = %.2f\n", octave, hz);
            float power = pow(2, (3.0/12));
            hertz = hz * power;
            printf("C octcount after = %.2d, hertz = %.2f\n", octcount, hertz);
            break;
        }

        case 'D':
        // code to be executed if n is equal to D;
        {
            printf("D octave before = %.2f, hz = %.2f\n", octave, hz);
            float power = pow(2, (5.0/12));
            hertz = hz * power;
            printf("D octcount after = %.2d, hertz = %.2f\n", octcount, hertz);
            break;
        }

        case 'E':
        // code to be executed if n is equal to E;
        {
            printf("E octave before = %.2f, hz = %.2f\n", octave, hz);
            float power = pow(2, (7.0/12));
            hertz = hz * power;
            printf("E octcount after = %.2d, hertz = %.2f\n", octcount, hertz);
            break;
        }

        case 'F':
        // code to be executed if n is equal to F;
        {
            printf("F octave before = %.2f, hz = %.2f\n", octave, hz);
            float power = pow(2, (8.0/12));
            hertz = hz * power;
            printf("F octcount after = %.2d, hertz = %.2f\n", octcount, hertz);
            break;
        }

        case 'G':
        // code to be executed if n is equal to G;
        {
            printf("G octave before = %.2f, hz = %.2f\n", octave, hz);
            float power = pow(2, (10.0/12));
            hertz = hz * power;
            printf("g octcount after = %.2d, hertz = %.2f\n", octcount, hertz);
            break;
        }

        case 'A':
        // code to be executed if n is equal to A;
        {
            printf("A octave before = %.2f, hz = %.2f\n", octave, hz);
            numerator = 12.0;
            hertz = hz * themath;
            printf("A octcount after = %.2d, hertzz = %.2f\n", octcount, hertz);
            printf("A case A hertz = %.2f\n", hz);
            break;
        }


        case 'B':
        // code to be executed if n is equal to B;
        {
            printf("B octave before = %.2f, hz = %.2f\n", octave, hz);
            float power = pow(2, (2.0/12));
            hertz = hz * power;
            printf("B octcount after = %.2d, hertz = %.2f\n", octcount, hertz);
            break;
        }

    }



    switch (accidental)
    {
        case '#':
        // code to be executed if n is equal to #;
        {
        // printf("> # octave before = %.2f, hz = %.2f\n", octave, hz);
            if (octave > 4)
            {
                float power = pow(2, (1.0/12));
                hertz = hertz * power;
                printf("> # octcount after = %.2d, hertzz = %.2f\n", octcount, hertz);
                // printf("> # case # hertz = %.2f\n", hz);
                break;
            }
            else if (octave < 4)
            {
                float power = pow(2, (1.0/12));
                hertz = hertz / power;
                printf("< # octcount after = %.2d, hertzz = %.2f\n", octcount, hertz);
                // printf("< # case A hertz = %.2f\n", hz);
                break;
            }
        }


        case 'b':
        // code to be executed if n is equal to b;
        {
            printf("B octave before = %.2f, hz = %.2f\n", octave, hz);
            float power = pow(2, (1.0/12));
            hertz = (hertz / power);
            printf("B octcount after = %.2d, hertz = %.2f\n", octcount, hertz);
            break;
        }


        default:
        // code to be executed if n is equal to constant2;
        {
            printf("default octave before = %.2f, hz = %.2f\n", octave, hz);
            break;
        }
    }

    int finalhertz = round(hertz);
    return finalhertz;
}



// Determines whether a string represents a rest
bool is_rest(string s)
{
    if  (strcmp(s, "") == 0)
    //if (strcmp (s, second string) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}




