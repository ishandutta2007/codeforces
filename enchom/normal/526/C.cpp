#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int C;
Int H1,H2,W1,W2;

bool SeenRem[1011];

Int Special()
{
    Int k=C/W1;
    Int joy=k*H1;
    Int leftover=C-k*W1;
    Int k2;
    Int bestjoy;

    k2=leftover/W2;
    joy+=k2*H2;

    leftover=C-k*W1-k2*W2;

    bestjoy=joy;

    if (W1>1000)
    {
        while(k>1)
        {
            k--;

            leftover=C-k*W1;
            k2=leftover/W2;
            leftover=C-k*W1-k2*W2;
            joy=k*H1+k2*H2;

            if (joy>bestjoy)
            bestjoy=joy;
        }
    }
    else
    {
        memset(SeenRem,false,sizeof(SeenRem));

        while(!SeenRem[leftover] && k>1)
        {
            SeenRem[leftover]=true;

            k--;

            leftover=C-k*W1;
            k2=leftover/W2;
            leftover=C-k*W1-k2*W2;
            joy=k*H1+k2*H2;

            if (joy>bestjoy)
            bestjoy=joy;
        }
    }

    return bestjoy;
}

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    Int v1,v2,v3,v4;
    Int d;

    scanf("%I64d %I64d %I64d %I64d %I64d",&C,&H1,&H2,&W1,&W2);

    v1=(C/W1)*H1;
    v2=(C/W2)*H2;

    v3=Special();

    d=W1;
    W1=W2;
    W2=d;

    d=H1;
    H1=H2;
    H2=d;

    v4=Special();

    printf("%lld\n",MAX(MAX(v1,v2),MAX(v3,v4)));

    return 0;
}