#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXVAL 100001

int IT[500001];
int LEAFOFFSET=1;

int n;
int a[200001];

int BestEnd[200001];
int BestBeg[200001];
int TotalBest[200001];

int TYPE[200001];

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int Query_Rec(int ver,int L,int R,int l,int r)
{
    if (L>r || R<l)
    {
        return 0;
    }
    else if (L>=l && R<=r)
    {
        return IT[ver];
    }
    else
    {
        return MAX(Query_Rec(2*ver,L,(L+R)/2,l,r) , Query_Rec(2*ver+1,(L+R)/2+1,R,l,r));
    }
}

int Query(int l,int r)
{
    if (l>r)
    return 0;

    return Query_Rec(1,1,LEAFOFFSET+1,l,r);
}

void Update(int ind,int val)
{
    ind+=LEAFOFFSET;
    IT[ind]=MAX(IT[ind],val);
    ind/=2;

    while(ind>0)
    {
        IT[ind]=MAX(IT[2*ind],IT[2*ind+1]);
        ind/=2;
    }

    return;
}

int main()
{
    //freopen("test.txt","r",stdin);

    int i;
    int LIS=0;
    int val;

    scanf("%d",&n);

    while(LEAFOFFSET<MAXVAL)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    memset(IT,0,sizeof(IT));

    for (i=1;i<=n;i++)
    {
        BestEnd[i]=Query(1,a[i]-1)+1;

        Update(a[i],BestEnd[i]);
    }

    memset(IT,0,sizeof(IT));

    for (i=n;i>=1;i--)
    {
        BestBeg[i]=Query(a[i]+1,MAXVAL)+1;

        Update(a[i],BestBeg[i]);
    }

    for (i=1;i<=n;i++)
    {
        TotalBest[i]=BestBeg[i]+BestEnd[i]-1;

        if (TotalBest[i]>LIS)
        {
            LIS=TotalBest[i];
        }
    }

    for (i=1;i<=n;i++)
    {
        if (TotalBest[i]<LIS)
        {
            TYPE[i]=1;
        }
        else
        {
            TYPE[i]=3;
        }
    }

    memset(IT,0,sizeof(IT));

    for (i=1;i<=n;i++)
    {
        val=Query(a[i],MAXVAL);

        if (val==LIS && TYPE[i]==3)
        {
            TYPE[i]=2;
        }

        Update(a[i],TotalBest[i]);
    }

    memset(IT,0,sizeof(IT));

    for (i=n;i>=1;i--)
    {
        val=Query(1,a[i]);

        if (val==LIS && TYPE[i]==3)
        {
            TYPE[i]=2;
        }

        Update(a[i],TotalBest[i]);
    }

    for (i=1;i<=n;i++)
    {
        printf("%d",TYPE[i]);
    }
    printf("\n");

    return 0;
}