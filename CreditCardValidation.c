#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNumber = 0;
    long cardNumberRef = 0;
    int length = 0;
    int digit = 0;
    int sum1 = 0;
    int sum2 = 0;
    int totalSum = 0;

    //Promtp user for credit card number
    cardNumber = get_long("Number: \n");

    cardNumberRef = cardNumber;


    //Calculate Luhn's algorithm
    for (int i = 0; cardNumberRef > 0; i++)
    {
        digit = cardNumberRef % 10;
        cardNumberRef = (cardNumberRef - digit) / 10;

        if (i % 2 == 0)
        {
            sum1 = sum1 + digit;
        }

        if (i % 2 != 0)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                int unit = digit % 10;
                int decimal = (digit - unit) / 10;
                digit = unit + decimal;
            }
            sum2 = sum2 + digit;
        }

        length = i + 1;
    }

    totalSum = sum1 + sum2;

    //If checksum works, check brand
    if (totalSum % 10 == 0)
    {
        if (length == 15 && cardNumber / 10000000000000 == 34)
        {
            printf("AMEX\n");
        }
        else if (length == 15 && cardNumber / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else if (length == 16 && cardNumber / 100000000000000 == 51)
        {
            printf("MASTERCARD\n");
        }
        else if (length == 16 && cardNumber / 100000000000000 == 52)
        {
            printf("MASTERCARD\n");
        }
        else if (length == 16 && cardNumber / 100000000000000 == 53)
        {
            printf("MASTERCARD\n");
        }
        else if (length == 16 && cardNumber / 100000000000000 == 54)
        {
            printf("MASTERCARD\n");
        }
        else if (length == 16 && cardNumber / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (length == 13 && cardNumber / 1000000000000 == 4)
        {
            printf("VISA\n");
        }
        else if (length == 16 && cardNumber / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}