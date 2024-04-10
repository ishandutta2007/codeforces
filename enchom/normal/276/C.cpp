#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct point
{
    Int ind;
    Int val;
};

Int nums[500001];
point qs[500001];
Int L=0;
Int spots[500001];

bool SortQueries(point a,point b)
{
    return (a.ind<b.ind);
}

Int totalsum;

int main()
{
    Int n,q;
    Int i;
    Int l,r;
    Int uk;
    Int value=0;
    
    for (i=0;i<=500000;i++)
    spots[i]=0;
    
    scanf("%I64d %I64d",&n,&q);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    
    for (i=1;i<=q;i++)
    {
        scanf("%I64d %I64d",&l,&r);
        
        L++;
        qs[L].val=1;
        qs[L].ind=l;
        
        L++;
        qs[L].val=-1;
        qs[L].ind=r+1;
    }
    
    sort(qs+1,qs+1+L,SortQueries);
    
    uk=1;
    for (i=1;i<=n;i++)
    {
        while(uk<=L && qs[uk].ind==i)
        {
            value=value+qs[uk].val;
            uk++;
        }
        
        spots[i]=value;
    }
    
    sort(spots+1,spots+1+n);
    sort(nums+1,nums+1+n);
    
    totalsum=0;
    for (i=n;i>=1;i--)
    {
        totalsum=totalsum+spots[i]*nums[i];
    }
    
    printf("%I64d\n",totalsum);
    
    return 0;
}