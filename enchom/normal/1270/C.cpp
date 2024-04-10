#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int t;
int n;

int main()
{
    int i,j;
    int test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        llong sum = 0, xr = 0;
        for (i=1;i<=n;i++)
        {
            llong num;

            scanf("%lld",&num);

            sum += num;
            xr ^= num;
        }

        printf("2\n%lld %lld\n",xr,sum + xr);
    }

    return 0;
}