#include <iostream>
#include <stdio.h>
using namespace std;

bool Prime[100111];
int n;

int main()
{
    int i,j;

    scanf("%d",&n);

    n++;

    if (n<=3)
    {
        printf("1\n");

        for (i=2;i<=n;i++)
        {
            printf("1");

            if (i!=n)
            printf(" ");
        }

        printf("\n");

        return 0;
    }

    for (i=2;i<=n;i++)
    {
        Prime[i]=true;
    }

    for (i=2;i<=n;i++)
    {
        if (Prime[i])
        {
            for (j=i+i;j<=n;j+=i)
            {
                Prime[j]=false;
            }
        }
    }

    printf("2\n");

    for (i=2;i<=n;i++)
    {
        if (Prime[i])
        printf("1");
        else
        printf("2");

        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}