#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

int main()
{
    Int a1,a2,a3,a4;
    Int fours,sevens;
    Int i;

    scanf("%I64d %I64d %I64d %I64d",&a1,&a2,&a3,&a4);

    if ( ABS(a3-a4)>1 )
    {
        printf("-1\n");
        return 0;
    }

    if (a3>a4)
    {
        fours=a1-a3;
        sevens=a2-a3;

        if (fours<0 || sevens<0)
        {
            printf("-1\n");
            return 0;
        }

        for (i=1;i<=fours;i++)
        {
            printf("4");
        }
        for (i=1;i<=a3;i++)
        {
            printf("47");
        }
        for (i=1;i<=sevens;i++)
        {
            printf("7");
        }
    }
    else if (a4>a3)
    {
        fours=a1-a4;
        sevens=a2-a4;

        if (fours<0 || sevens<0)
        {
            printf("-1\n");
            return 0;
        }

        printf("74");

        for (i=1;i<=fours;i++)
        {
            printf("4");
        }

        for (i=1;i<=a4-2;i++)
        {
            printf("74");
        }
        printf("7");
        for (i=1;i<=sevens;i++)
        {
            printf("7");
        }
        printf("4");
    }
    else if (a3==a4)
    {
        fours=a1-a3-1;
        sevens=a2-a3;

        if (sevens<0)
        {
            printf("-1\n");
            return 0;
        }
        if (fours<0)
        {
            fours=a1-a3;
            sevens=a2-a3-1;

            if (fours<0 || sevens<0)
            {
                printf("-1\n");
                return 0;
            }

            printf("74");
            for (i=1;i<=fours;i++)
            {
                printf("4");
            }

            for (i=1;i<=a4-1;i++)
            {
                printf("74");
            }

            for (i=1;i<=sevens;i++)
            {
                printf("7");
            }
            printf("7");
        }
        else
        {
            printf("4");
            for (i=1;i<=fours;i++)
            {
                printf("4");
            }

            for (i=1;i<=a4-1;i++)
            {
                printf("74");
            }
            printf("7");
            for (i=1;i<=sevens;i++)
            {
                printf("7");
            }
            printf("4");
        }
    }

    printf("\n");

    return 0;
}