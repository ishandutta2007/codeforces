#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

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
    Int n;
    Int n1,n2;
    Int lastdig;

    scanf("%I64d",&n);

    if (n>=0)
    {
        printf("%I64d\n",n);
        return 0;
    }

    n=n*-1;

    n1=n/10;
    lastdig=n%10;
    n2=(n/100)*10+lastdig;

    printf("%I64d\n",MIN(n1,n2)*-1);

    return 0;
}