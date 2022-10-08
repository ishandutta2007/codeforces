#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

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
    Int n1,n2;
    Int a,b,c,d;
    Int nod;

    scanf("%I64d %I64d %I64d %I64d",&a,&b,&c,&d);

    n1=b*c;
    n2=a*d;

    if (n1>n2)
    {
        d=n1;
        n1=n2;
        n2=d;
    }

    n1=n2-n1;

    nod=gcd(n1,n2);

    n1/=nod;
    n2/=nod;

    printf("%I64d/%I64d\n",n1,n2);

    return 0;
}