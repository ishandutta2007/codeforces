#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    int test;
    int n,k1,k2;
    int i,j;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d %d",&n,&k1,&k2);

        int v1 = 0, v2 = 0;

        for (i=1;i<=k1;i++)
        {
            int a;

            scanf("%d",&a);
            v1 = max(a, v1);
        }

        for (i=1;i<=k2;i++)
        {
            int a;

            scanf("%d",&a);

            v2 = max(a, v2);
        }

        if (v1 > v2)
            printf("YES\n");
        else
            printf("NO\n");
    }
}