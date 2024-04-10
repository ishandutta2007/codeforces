#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int fives=0,zeroes=0;
Int n;

int main()
{
    Int i;
    Int k;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&k);

        if (k==0)
        zeroes++;
        else
        fives++;
    }

    if (zeroes==0)
    {
        printf("-1\n");

        return 0;
    }

    while(fives%9!=0)
    fives--;

    for (i=1;i<=fives;i++)
    {
        printf("5");
    }

    if (fives==0)
    printf("0\n");
    else
    {
        for (i=1;i<=zeroes;i++)
        {
            printf("0");
        }
        printf("\n");
    }
}