#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL

Int a,b;

int main()
{
    Int seq;
    Int i;
    Int ans=0;

    scanf("%I64d %I64d",&a,&b);

    seq=( a*(a+1) )/2;
    seq%=MOD;

    for (i=1;i<=b-1;i++)
    {
        ans+=seq*( (i*b)%MOD );
        ans+=i*a;

        ans%=MOD;
    }

    printf("%I64d\n",ans);

    return 0;
}