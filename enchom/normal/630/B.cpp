#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
typedef long double Double;

Double FastPow(Double k,Int p)
{
    if (p==0)
    return 1.0;

    Double P=FastPow(k,p/2);
    P=P*P;

    if (p%2==1)
    P=P*k;

    return P;
}

void EnchomSolve()
{
    Int n;
    Int k;
    Double ans;
    Double addon;

    scanf("%lld",&n);
    scanf("%lld",&k);

    addon=FastPow((Double)1.000000011,k);

    ans=(Double)n*(Double)addon;

    printf("%.8f\n",(double)ans);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}