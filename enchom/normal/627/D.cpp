#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int INF=999999999;
int n,k;
int val[200111];
vector<int> Graph[200111];

int Sz[200111];

int rate[200111];
int Rates[200111];

int FreeRate[200111];
int BadBros[200111];

int bigK;

int GetSz(int ver,int dad)
{
    int i;

    Sz[ver]=1;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        Sz[ver]+=GetSz(Graph[ver][i],ver);
    }

    return Sz[ver];
}

int GetRates(int ver,int dad)
{
    int i;

    Rates[ver]=rate[ver];

    if (rate[ver]==0)
    FreeRate[ver]=-INF;
    else
    FreeRate[ver]=rate[ver];

    BadBros[ver]=0;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        Rates[ver]+=GetRates(Graph[ver][i],ver);

        if (Rates[ Graph[ver][i] ]==Sz[ Graph[ver][i] ])
        {
            FreeRate[ver]+=Rates[ Graph[ver][i] ];
        }
        else
        {
            BadBros[ver]++;
        }
    }

    return Rates[ver];
}

int LongestDown[200111];
int MaxVal;

int GetDown(int ver,int dad)
{
    int i;
    int themax=0,themax2=0;
    int val;

    LongestDown[ver]=FreeRate[ver];

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        val=GetDown(Graph[ver][i],ver);

        if (val>themax)
        {
            themax2=themax;
            themax=val;
        }
        else if (val>themax2)
        {
            themax2=val;
        }
    }

    if (MaxVal<FreeRate[ver]+themax+themax2)
    {
        MaxVal=FreeRate[ver]+themax+themax2;
    }

    LongestDown[ver]+=themax;

    return LongestDown[ver];
}

bool Okay(int k)
{
    int i;

    for (i=1;i<=n;i++)
    {
        if (val[i]>=k)
        rate[i]=1;
        else
        rate[i]=0;
    }

    GetRates(1,0);

    for (i=2;i<=n;i++)
    {
        if (Rates[1]-Rates[i] == Sz[1]-Sz[i])
        {
            FreeRate[i]+=Rates[1]-Rates[i];
        }
        else
        {
            BadBros[i]++;
        }
    }

    for (i=1;i<=n;i++)
    {
        if (FreeRate[i]>=bigK)
        {
            return true;
        }
    }

    for (i=1;i<=n;i++)
    {
        if (FreeRate[i]>=0 && BadBros[i]==1)
        {
            FreeRate[i]=-INF;
        }
    }

    MaxVal=0;
    GetDown(1,0);

    if (MaxVal>=bigK)
    return true;
    else
    return false;
}

int main()
{
    int i;
    int a,b;
    int l,r,mid,best;

    scanf("%d %d",&n,&k);

    bigK=k;

    for (i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
    }

    for (i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    GetSz(1,0);

    l=1;
    r=1000000;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Okay(mid))
        {
            l=mid+1;
            best=mid;
        }
        else
        {
            r=mid-1;
        }
    }

    printf("%d\n",best);

    return 0;
}