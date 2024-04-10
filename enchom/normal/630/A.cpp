#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1LL;

    Int P=FastPow(k,p/2);
    P=(P*P)%100LL;

    if (p%2==1)
    P=(P*k)%100LL;

    return P;
}

void EnchomSolve()
{
    Int n;
    Int k;

    scanf("%lld",&n);

    k=FastPow(5,n);

    if (k<10)
    printf("0");
    printf("%lld\n",k);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}