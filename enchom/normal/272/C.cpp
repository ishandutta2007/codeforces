#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct IntervalNode
{
    Int RMQ;
    Int IntrvL,IntrvR;
    bool update;
    Int UpdateTo;
};

///131072-262143

Int nums[200001];
IntervalNode IntervalTree[262144];

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

Int GetRMQ(Int ver,Int intervalz)
{
    Int MAXNUM;
    
    if (IntervalTree[ver].update)
    {
        IntervalTree[ver].update=false;
        IntervalTree[ver].RMQ=IntervalTree[ver].UpdateTo;
        
        if (ver<=131071)
        {
            IntervalTree[2*ver].update=true;
            IntervalTree[2*ver].UpdateTo=IntervalTree[ver].UpdateTo;
            IntervalTree[2*ver+1].update=true;
            IntervalTree[2*ver+1].UpdateTo=IntervalTree[ver].UpdateTo;
        }
    }
    
    if (IntervalTree[ver].IntrvL>intervalz)
    return -1;
    
    if (IntervalTree[ver].IntrvR<=intervalz) ///Full
    {
        MAXNUM=IntervalTree[ver].RMQ;
    }
    else ///Partly
    {
        MAXNUM=MAX(GetRMQ(ver*2,intervalz),GetRMQ(ver*2+1,intervalz));
        
        IntervalTree[ver].RMQ=MAX( IntervalTree[ver*2].RMQ,IntervalTree[ver*2+1].RMQ );
    }
    
    return MAXNUM;
}

void Update(Int ver,Int intervalz,Int value)
{
    if (IntervalTree[ver].update)
    {
        IntervalTree[ver].update=false;
        IntervalTree[ver].RMQ=IntervalTree[ver].UpdateTo;
        
        if (ver<=131071)
        {
            IntervalTree[2*ver].update=true;
            IntervalTree[2*ver].UpdateTo=IntervalTree[ver].UpdateTo;
            IntervalTree[2*ver+1].update=true;
            IntervalTree[2*ver+1].UpdateTo=IntervalTree[ver].UpdateTo;
        }
    }
    
    if (IntervalTree[ver].IntrvL>intervalz)
    return;
    
    if (IntervalTree[ver].IntrvR<=intervalz) ///Fully
    {
        IntervalTree[ver].update=false;
        IntervalTree[ver].RMQ=value;
        
        if (ver<=131071)
        {
            IntervalTree[ver*2].update=true;
            IntervalTree[ver*2+1].update=true;
            IntervalTree[ver*2].UpdateTo=value;
            IntervalTree[ver*2+1].UpdateTo=value;
        }
    }
    else ///Partly
    {
        Update(ver*2,intervalz,value);
        Update(ver*2+1,intervalz,value);
        
        IntervalTree[ver].RMQ=MAX( IntervalTree[ver*2].RMQ,IntervalTree[ver*2+1].RMQ );
    }
}

int main()
{
    Int n;
    Int i;
    Int m;
    Int w,h;
    Int heig;
    
    scanf("%I64d",&n);
    
    for (i=0;i<=200000;i++)
    nums[i]=0;
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    
    for (i=131072;i<=262143;i++)
    {
        IntervalTree[i].IntrvL=i-131071;
        IntervalTree[i].IntrvR=i-131071;
        IntervalTree[i].RMQ=nums[i-131071];
        IntervalTree[i].update=false;
    }
    for (i=131071;i>=1;i--)
    {
        IntervalTree[i].IntrvL=IntervalTree[2*i].IntrvL;
        IntervalTree[i].IntrvR=IntervalTree[2*i+1].IntrvR;
        IntervalTree[i].RMQ=MAX(IntervalTree[2*i].RMQ,IntervalTree[2*i+1].RMQ);
        IntervalTree[i].update=false;
    }
    
    scanf("%I64d",&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&w,&h);
        
        heig=GetRMQ(1,w);
        
        Update(1,w,heig+h);
        
        printf("%I64d\n",heig);
    }
    return 0;
}