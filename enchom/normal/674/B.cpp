#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;
int a,b,c,d;
int nonused[1111];
int L=0;

int main()
{
    int i;

    scanf("%d %d",&n,&k);
    scanf("%d %d %d %d",&a,&b,&c,&d);

    if (k<n+1 || n==4)
    {
        printf("-1\n");
        return 0;
    }

    for (i=1;i<=n;i++)
    {
        if (i==a || i==b || i==c || i==d)
        continue;

        L++;
        nonused[L]=i;
    }

    printf("%d %d",a,c);

    for (i=1;i<=L;i++)
    {
        printf(" %d",nonused[i]);
    }

    printf(" %d %d\n",d,b);

    ///

    printf("%d %d",c,a);

    for (i=1;i<=L;i++)
    {
        printf(" %d",nonused[i]);
    }

    printf(" %d %d\n",b,d);

    return 0;
}