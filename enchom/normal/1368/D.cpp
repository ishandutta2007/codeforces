#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n;
llong a[200111];
int bitctr[22];


int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);

        for (j=0;j<20;j++)
        {
            if ( ( a[i] & (1LL<<j) ) > 0 )
                bitctr[j]++;
        }
    }

    llong ans = 0;
    for (i=n;i>=1;i--)
    {
        llong num = 0;
        for (j=0;j<20;j++)
        {
            if (bitctr[j] > 0)
            {
                bitctr[j]--;

                num |= (1LL << j);
            }
        }

        ans += num * num;
    }

    printf("%lld\n", ans);
}