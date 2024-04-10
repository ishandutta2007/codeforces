#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int main()
{
    int t;
    int test;
    int i,j;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        llong a,b,n;

        scanf("%lld %lld %lld",&a,&b,&n);

        int ans = 0;

        while(a <= n && b <= n)
        {
            if (a < b)
            {
                a = a + b;
            }
            else
            {
                b = a + b;
            }
            ans++;
        }

        printf("%d\n",ans);
    }
}