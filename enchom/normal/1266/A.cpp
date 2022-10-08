#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char str[211];
int n;
int t;

int main()
{
    int i,j;

    scanf("%d",&t);

    for (int test=1;test<=t;test++)
    {
        scanf("%s",str+1);
        n = strlen(str+1);

        int digsum = 0;
        bool haseven = false;
        bool has0 = false;

        int i;

        for (i=1;i<=n;i++)
        {
            digsum += (str[i] - '0');

            if (!has0 && str[i] == '0')
                has0 = true;
            else if ( (str[i] - '0') % 2 == 0 )
                haseven = true;
        }

        if (has0 && haseven && digsum % 3 == 0)
            printf("red\n");
        else
            printf("cyan\n");
    }

    return 0;
}