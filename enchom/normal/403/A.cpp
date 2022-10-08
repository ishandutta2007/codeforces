#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int,int> edges[1001];
int n,p;
int t;
int L;
pair<int,int> a[1001];
int L2;

int main()
{
    int test;
    int i,j;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&n,&p);

        L=0;
        L2=0;

        for (i=1;i<=n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                L++;
                edges[L].first=i;
                edges[L].second=j;
            }
        }

        sort(edges+1,edges+1+L);

        for (i=1;i<=2*n;i++)
        {
            printf("%d %d\n",edges[i].first,edges[i].second);
        }

        for (i=2*n+1;i<=L;i++)
        {
            L2++;
            a[L2]=edges[i];
        }

        if (L2>0)
        {
            random_shuffle(a+1,a+1+L2);
        }

        for (i=1;i<=p;i++)
        {
            printf("%d %d\n",a[i].first,a[i].second);
        }
    }

    return 0;
}