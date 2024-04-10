#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

#define INF 999999999

Int k,n;
Int nums[1000001];
Int chosen[1000001];
bool safe[1000001];
Int ans=0;

pair<Int,Int> RMQ[3000001];
Int Sums[3000001];

Int LEAFOFFSET;

pair<Int,Int> MIN(pair<Int,Int> a,pair<Int,Int> b)
{
    if (a<b)
    return a;
    else
    return b;
}

pair<Int,Int> RMQ_rec(Int ver,Int L,Int R,Int l,Int r)
{
    if (R<l || L>r)
    return make_pair(INF,0);
    else if (L>=l && R<=r)
    {
        return RMQ[ver];
    }
    else
    {
        return MIN( RMQ_rec(ver*2,L,(L+R)/2,l,r) , RMQ_rec(ver*2+1,(L+R)/2+1,R,l,r) );
    }
}

Int GetRMQ(Int l,Int r)
{
    pair<Int,Int> themin=RMQ_rec(1,1,LEAFOFFSET+1,l,r);
    return themin.second;
}

Int PreSum(Int k)
{
    if (k==0)
    return 0;

    Int ind=LEAFOFFSET+k;
    Int sum=Sums[ind];

    while(ind>1)
    {
        if (ind%2==1)
        {
            sum+=Sums[ind-1];
        }

        ind/=2;
    }

    return sum;
}

Int GetSum(Int l,Int r)
{
    return PreSum(r)-PreSum(l-1);
}

void Change(Int x)
{
    Int ind=x+LEAFOFFSET;

    RMQ[ind]=make_pair(INF,0);
    Sums[ind]=0;

    ind/=2;

    while(ind>0)
    {
        RMQ[ind]=MIN(RMQ[ind*2],RMQ[ind*2+1]);
        Sums[ind]=Sums[ind*2]+Sums[ind*2+1];

        ind/=2;
    }

    return;
}


void Solve(Int l,Int r)
{
    if (l>r)
    return;

    Int min_num=GetRMQ(l,r);
    Int sum;

    if (min_num==0)
    return;

    if (safe[min_num])
    {
        Solve(l,min_num-1);
        Solve(min_num+1,r);
    }
    else
    {
        sum=GetSum(l,r);
        ans+=sum;

        Change(min_num);

        Solve(l,r);
    }
}

int main()
{
    Int i;
    Int uk1=1,uk2=1;

    scanf("%I64d %I64d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }

    for (i=1;i<=k;i++)
    {
        scanf("%I64d",&chosen[i]);
    }

    while(uk1<=n && uk2<=k)
    {
        if (nums[uk1]==chosen[uk2])
        {
            safe[uk1]=true;

            uk1++;
            uk2++;
        }
        else
        {
            uk1++;
        }
    }

    LEAFOFFSET=1;

    while(LEAFOFFSET<n)
    {
        LEAFOFFSET*=2;
    }
    LEAFOFFSET--;

    for (i=1;i<=2*LEAFOFFSET+1;i++)
    {
        RMQ[i].first=INF;
        RMQ[i].second=0;
        Sums[i]=0;
    }

    for (i=LEAFOFFSET+1;i<=LEAFOFFSET+n;i++)
    {
        RMQ[i].first=nums[i-LEAFOFFSET];
        RMQ[i].second=i-LEAFOFFSET;

        Sums[i]=1;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        Sums[i]=Sums[2*i]+Sums[2*i+1];

        RMQ[i]=MIN(RMQ[2*i],RMQ[2*i+1]);
    }

    Solve(1,n);

    printf("%I64d\n",ans);

    return 0;
}