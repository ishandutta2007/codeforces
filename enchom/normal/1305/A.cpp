#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[200111];
int b[200111];

int main()
{
    int t,test;
    int i,j;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);

        for (i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(b+1,b+1+n);

        for (i=1;i<=n;i++)
        {
            printf("%d",a[i]);
            if (i != n)
                printf(" ");
        }
        printf("\n");
        for (i=1;i<=n;i++)
        {
            printf("%d",b[i]);
            if (i != n)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}