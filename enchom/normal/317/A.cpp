#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int a,b,m;
    Int d;
    Int k=0;

    scanf("%I64d %I64d %I64d",&a,&b,&m);

    if (a>b)
    {
        d=a;
        a=b;
        b=d;
    }

    if (b>=m)
    {
        printf("0\n");
        return 0;
    }

    if (b<=0)
    {
        printf("-1\n");
        return 0;
    }

    if (a<0)
    {
        k=(0-a)/b;

        a=a+k*b;

        if (a<0)
        {
            k++;
            a+=b;
        }
    }

    while(b<m)
    {
        a=a+b;

        d=a;
        a=b;
        b=d;

        k++;
    }

    printf("%I64d\n",k);

    return 0;
}