#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n,k;
    Int i;

    scanf("%I64d %I64d",&n,&k);

    if ( (n*(n-1))/2<=k )
    {
        printf("no solution\n");
    }
    else
    {
        for (i=0;i<n;i++)
        {
            printf("%lld %lld\n",i,i*n);
        }
    }
}