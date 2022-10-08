#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

Int ABS(Int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

void EnchomSolve()
{
    Int k;
    Int dev,bestdev,bestmoves;
    Int i;

    scanf("%lld",&k);

    if (k<0)
    k+=(ABS(k)/360LL)*360LL;
    while(k<0)
    k+=360LL;

    k%=360LL;

    if (k<0)
    k=-k;
    else
    k=360LL-k;

    bestmoves=0;
    bestdev=MIN(k,360LL-k);

    for (i=1;i<=3;i++)
    {
        k+=90LL;
        k%=360LL;

        dev=MIN(k,360LL-k);

        if (dev<bestdev)
        {
            bestdev=dev;
            bestmoves=i;
        }
    }

    printf("%lld\n",bestmoves);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}