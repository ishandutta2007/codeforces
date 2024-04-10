#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
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
    Int n,m,x,y,a,b;
    Int nod;
    Int minmulti1,minmulti2,minmulti;
    Int cx,cy;
    Int bx,by,tx,ty;
    Int change;

    scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&n,&m,&x,&y,&a,&b);

    nod=gcd(a,b);

    a=a/nod;
    b=b/nod;

    minmulti1=n/a;
    minmulti2=m/b;

    minmulti=MIN(minmulti1,minmulti2);

    a=a*minmulti;
    b=b*minmulti;

    cx=(a+1)/2;
    cy=(b+1)/2;

    bx=x-cx;
    by=y-cy;

    tx=x+(a-cx);
    ty=y+(b-cy);

    if (bx<0)
    {
        change=0-bx;
        bx=0;
        tx+=change;
    }
    if (tx>n)
    {
        change=tx-n;
        tx=n;
        bx-=change;
    }

    if (by<0)
    {
        change=0-by;
        by=0;
        ty+=change;
    }

    if (ty>m)
    {
        change=ty-m;
        ty=m;
        by-=change;
    }

    printf("%I64d %I64d %I64d %I64d\n",bx,by,tx,ty);

    return 0;
}