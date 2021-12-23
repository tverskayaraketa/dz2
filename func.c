#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"


void ex_1(char* Str)
{
    int First_1 = 0, First_2, Last_1 = -1, Last_2 = 1, i = 0, FirstWord_Len, LastWord_Len, Count, Len;
    char NStr;

    while (Str[i] == ' ')
    {
        i++;
        First_1++;
    }

    while (Str[i] != ' ')
    {
        i++;
        Last_1++;
    }

    while (Str[i] != '\0')
    {
        i++;
        Last_2++;
    }

    while (Str[i] != ' ')
        i--;

    First_2 = i + 1;

    Len = strlen(Str) - 1;

    FirstWord_Len = Last_1 - First_1 + 1;
    LastWord_Len = Last_2 - First_2 + 2;

    for (i = 0; i < FirstWord_Len / 2; i++)
    {
        NStr = Str[i + First_1];
        Str[i + First_1] = Str[Last_1 - i];
        Str[Last_1 - i] = NStr;
    }
    for (i = 0; i < LastWord_Len / 2; i++)
    {
        NStr = Str[i + First_2];
        Str[i + First_2] = Str[Last_2 - i];
        Str[Last_2 - i] = NStr;
    }
    for (i = 0; i < Len / 2 + 1; i++)
    {
        NStr = Str[i];
        Str[i] = Str[Len - i];
        Str[Len - i] = NStr;
    }

    Last_1 = Len - Last_1 - 1;
    First_2=Len - First_2 +1;
    Count = Last_1 - First_2 + 1;

    for (i = 0; i < Count / 2; i++)
    {
        NStr = Str[i + First_2];
        Str[i + First_2] = Str[Last_1 - i];
        Str[Last_1 - i] = NStr;
    }
}

struct Humans
{
    char Surname[64];
    char Name[64];
    char Otchestvo[64];
    char Gender[16];
    char Post[64];
    char Birthday[12];
};

void ex_2()
{
    int N = 0;
    printf("Enter number of humans");
    scanf("%d", &N);

    struct Humans* arr = (struct Humans*)malloc(N * sizeof(struct Humans));

    for (int i = 0; i < N; i++)
    {
        printf("enter all info (Surname, Name, Patronymic, Gender, Post, Birthday)");
        scanf("%s", &arr[i].Surname);
        scanf("%s", &arr[i].Name);
        scanf("%s", &arr[i].Otchestvo);
        scanf("%s", &arr[i].Gender);
        scanf("%s", &arr[i].Post);
        scanf("%s", &arr[i].Birthday);
    }
    Engineers(N, arr);

}
void Engineers(int Number, struct Humans* hum)
{
    for (int i = 0; i < Number; i++)
    {
        if (hum[i].Post == "Engineer") {
            int age = 0;
            for (int j = 0; j < 4; j++)
            {
                age = (age * 10) + (int)hum[i].Birthday[6 + j];
            }
            if (hum[i].Gender == "Man" && (2021 - age) >= 65) {
                printf("%s %s %s is %s %s, born %s", hum[i].Surname, hum[i].Name, hum[i].Otchestvo, hum[i].Gender, hum[i].Post, hum[i].Birthday);
            }
            if (hum[i].Gender == "Woman" && (2021 - age) >= 60) {
                printf("%s %s %s is %s %s, born %s", hum[i].Surname, hum[i].Name, hum[i].Otchestvo, hum[i].Gender, hum[i].Post, hum[i].Birthday);
            }
        }
            
    }
}
