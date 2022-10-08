#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ITa[600111];
Int ITb[600111];
int LEAFOFFSET=1;
int n,k;
int a,b;
int q;

Int pSumA(int ind)
{
    if (ind==0)
    return 0;

    ind+=LEAFOFFSET;

    Int sum=ITa[ind];

    while(ind>1)
    {
        if (ind%2==1)
        sum+=ITa[ind-1];

        ind/=2;
    }

    return sum;
}

Int SumA(int L,int R)
{
    if (L>R)
    return 0;

    return pSumA(R)-pSumA(L-1);
}

///

Int pSumB(int ind)
{
    if (ind==0)
    return 0;

    ind+=LEAFOFFSET;

    Int sum=ITb[ind];

    while(ind>1)
    {
        if (ind%2==1)
        sum+=ITb[ind-1];

        ind/=2;
    }

    return sum;
}

Int SumB(int L,int R)
{
    if (L>R)
    return 0;

    return pSumB(R)-pSumB(L-1);
}

///

void UpdA(int ind,int val)
{
    ind+=LEAFOFFSET;

    ITa[ind]+=val;
    if (ITa[ind]>a)
    ITa[ind]=a;

    ind/=2;

    while(ind>0)
    {
        ITa[ind]=ITa[2*ind]+ITa[2*ind+1];
        ind/=2;
    }

    return;
}

void UpdB(int ind,int val)
{
    ind+=LEAFOFFSET;

    ITb[ind]+=val;
    if (ITb[ind]>b)
    ITb[ind]=b;

    ind/=2;

    while(ind>0)
    {
        ITb[ind]=ITb[2*ind]+ITb[2*ind+1];
        ind/=2;
    }

    return;
}

int main()
{
    int i,j;
    int cm,p,val,d;
    Int ans;

    scanf("%d %d %d %d %d",&n,&k,&a,&b,&q);

    LEAFOFFSET=1;
    while(LEAFOFFSET<n)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    for (i=1;i<=q;i++)
    {
        scanf("%d",&cm);

        if (cm==1)
        {
            scanf("%d %d",&d,&val);

            UpdA(d,val);
            UpdB(d,val);
        }
        else
        {
            scanf("%d",&p);

            ans=SumB(1,p-1)+SumA(p+k,n);

            printf("%lld\n",ans);
        }
    }

    return 0;
}