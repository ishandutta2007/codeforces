#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int main()
{
    int n;
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        llong x;

        scanf("%lld",&x);

        if (x <= 14)
        {
            printf("NO\n");
            continue;
        }

        llong rem = x % 14LL;

        if (rem >= 1 && rem <= 6)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}