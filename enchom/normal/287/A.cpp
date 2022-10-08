#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int table[5][5];

bool Check()
{
    Int i,j;

    for (i=1;i<=3;i++)
    {
        for (j=1;j<=3;j++)
        {
            if (table[i][j]==table[i][j+1] && table[i][j+1]==table[i+1][j+1] && table[i+1][j+1]==table[i+1][j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Int i,j;
    char ch;

    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            scanf("%c",&ch);

            if (ch!='#' && ch!='.')
            {
                j--;
                continue;
            }

            if (ch=='#')
            table[i][j]=1;
            else
            table[i][j]=0;
        }
    }

    if (Check())
    {
        printf("YES\n");
        return 0;
    }

    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            table[i][j]=table[i][j]^1;
            if (Check())
            {
                printf("YES\n");
                return 0;
            }
            table[i][j]=table[i][j]^1;
        }
    }

    printf("NO\n");

    return 0;
}