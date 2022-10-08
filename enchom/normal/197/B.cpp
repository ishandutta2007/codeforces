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

Int gcd(Int a,Int b)
{
    Int r;

    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int main()
{
    Int n,m;
    Int a0,b0;
    Int k;
    Int i,nod;
    bool signminus;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=n+1;i++)
    {
        scanf("%I64d",&k);

        if (i==1)
        a0=k;
    }

    for (i=1;i<=m+1;i++)
    {
        scanf("%I64d",&k);

        if (i==1)
        b0=k;
    }

    if (a0*b0>0)
    signminus=false;
    else
    signminus=true;

    if (n>m)
    {
        if (signminus)
        printf("-");

        printf("Infinity\n");
    }
    else if (n<m)
    {
        printf("0/1\n");
    }
    else
    {
        a0=ABS(a0);
        b0=ABS(b0);

        nod=gcd(a0,b0);
        a0=a0/nod;
        b0=b0/nod;

        if (signminus)
        printf("-");

        printf("%I64d/%I64d\n",a0,b0);
    }

    return 0;
}