#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

llong a[200111];
llong b[200111];
int n;

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
    }

    llong mv = 0;

    for (i=1;i<=n;i++)
    {
        a[i] = b[i] + mv;
        mv = max(mv, a[i]);
    }

    for (i=1;i<=n;i++)
    {
        printf("%lld",a[i]);
        if (i != n)
            printf(" ");
    }
    printf("\n");

    return 0;
}