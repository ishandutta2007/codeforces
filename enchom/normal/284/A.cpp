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

Int F(Int k) ///Euler's totlier function
{
    Int i;
    Int ctr=0;

    for (i=1;i<=k-1;i++)
    {
        if (gcd(i,k)==1)
        ctr++;
    }

    return ctr;
}

int main()
{
    Int n;

    scanf("%I64d",&n);

    if (n==2)
    {
        printf("1\n");
        return 0;
    }

    printf("%I64d\n",F( F(n) ));

    return 0;
}