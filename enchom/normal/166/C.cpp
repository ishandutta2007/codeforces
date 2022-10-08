#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef int Int;

Int a[501];

Int ABS(Int a)
{
    if (a<0)
    {
        return a*-1;
    }
    else
    {
        return a;
    }
}

Int MIN(Int a,Int b)
{
    if (a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    Int n,x;
    Int i;
    Int goal;
    Int moves,position;
    Int firstone,lastone;
    Int firstmoves,lastmoves;
    bool sawit=false;

    scanf("%d %d",&n,&x);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        if (a[i]==x)
        {
            sawit=true;
        }
    }

    if (!sawit)
    {
        n++;
        a[n]=x;
        moves=1;
    }
    else
    {
        moves=0;
    }

    sort(a+1,a+1+n);

    if (a[(n+1)/2]==x)
    {
        printf("%d\n",moves);
        return 0;
    }

    firstone=-1;
    for (i=1;i<=n;i++)
    {
        if (a[i]==x)
        {
            lastone=i;
            if (firstone==-1)
            firstone=i;
        }
    }

    firstmoves=moves;
    lastmoves=moves;

    firstmoves=firstmoves+ABS(n-2*firstone+1);

    if (firstone<(n+1)/2)
    {
        firstmoves--;
    }

    lastmoves=lastmoves+ABS(n-2*lastone+1);

    if (lastone<(n+1)/2)
    {
        lastmoves--;
    }

    moves=MIN(lastmoves,firstmoves);

    printf("%d\n",moves);

    return 0;
}