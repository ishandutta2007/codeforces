#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int n,k,s,t;
pair<int,int> cars[200111];
int g[200111];
Int mustacc;

int distances[200111];
int L=0;

bool Okay(int capacity)
{
    int i;
    Int speed=0;

    for (i=1;i<=L;i++)
    {
        if (distances[i]>capacity)
        return false;

        if ((Int)capacity>=(Int)distances[i]*2LL)
        {
            speed+=(Int)distances[i];
        }
        else
        {
            speed+=(Int)(capacity-distances[i]);
        }
    }

    if (speed>=mustacc)
    return true;
    else
    return false;
}

int main()
{
    int i,j;
    int last=0;
    Int toadd;
    Int largest;
    int l,r,mid,best;
    int mincost;

    scanf("%d %d %d %d",&n,&k,&s,&t);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&cars[i].first,&cars[i].second);
    }

    for (i=1;i<=k;i++)
    {
        scanf("%d",&g[i]);
    }

    sort(g+1,g+1+k);

    g[0]=0;
    g[k+1]=s;
    for (i=1;i<=k+1;i++)
    {
        L++;
        distances[L]=g[i]-g[i-1];
    }

    mustacc=(Int)2*s-(Int)t;

    l=1;
    r=1000000000;
    best=-1;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Okay(mid))
        {
            best=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    if (best==-1)
    {
        printf("-1\n");
        return 0;
    }

    mincost=-1;
    for (i=1;i<=n;i++)
    {
        if (cars[i].second>=best)
        {
            if (mincost==-1 || mincost>cars[i].first)
            {
                mincost=cars[i].first;
            }
        }
    }

    if (mincost==-1)
    {
        printf("-1\n");
        return 0;
    }

    printf("%d\n",mincost);

    return 0;
}