#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n;
llong b[500111];
llong a[500111];

int main()
{
    int i;
    bool zero = true;
    int spot;
    int prv;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);

        if (b[i] != 0)
        {
            zero = false;
        }
    }

    if (zero)
    {
        printf("YES\n");
        for (i=1;i<=n;i++)
        {
            if (i != 1)
                printf(" ");
            printf("1");
        }
        printf("\n");

        return 0;
    }

    spot = -1;
    for (i=1;i<=n;i++)
    {
        int nxt = (i%n) + 1;

        if (b[i] < b[nxt])
        {
            spot = nxt;
            break;
        }
    }

    if (spot == -1)
    {
        printf("NO\n");
        return 0;
    }

    a[spot] = b[spot];
    prv = spot - 1;
    if (prv == 0)
        prv = n;
    a[prv] = 1000000000LL + a[spot];

    while(a[prv] % a[spot] != b[prv])
        a[prv]++;

    prv--;
    if (prv == 0)
        prv = n;

    while(prv != spot)
    {
        int nxt = (prv%n) + 1;

        a[prv] = a[nxt] + b[prv];

        prv--;
        if (prv == 0)
            prv = n;
    }

    printf("YES\n");
    for (i=1;i<=n;i++)
    {
        if (i != 1)
            printf(" ");
        printf("%lld",a[i]);
    }
    printf("\n");

    return 0;
}