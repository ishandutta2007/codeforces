#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct s
{
    Int start;
    Int end;
};

s seq[100001];
Int sL=0;
Int TheMaxEnd[100001];

bool SortEm(s a,s b)
{
    if (a.start<b.start)
    return true;
    else if (a.start>b.start)
    return false;
    else
    {
        return (a.end<b.end);
    }
}

int main()
{
    Int n;
    Int a,b;
    Int i;
    Int ctr=0;
    Int l,r,mid;
    Int ans,maxend;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        
        sL++;
        seq[sL].start=a;
        seq[sL].end=b;
    }
    sort(seq+1,seq+1+n,SortEm);
    TheMaxEnd[1]=seq[1].end;
    for (i=2;i<=n;i++)
    {
        if (seq[i].end>TheMaxEnd[i-1])
        TheMaxEnd[i]=seq[i].end;
        else
        TheMaxEnd[i]=TheMaxEnd[i-1];
    }
    for (i=1;i<=n;i++)
    {
        l=1;
        r=i-1;
        ans=0;
        while(l<=r)
        {
            mid=(l+r)/2;
            if (seq[mid].start<seq[i].start)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if (ans==0)
        continue;
        
        maxend=TheMaxEnd[ans];
        
        if (maxend>seq[i].end)
        {
            ctr++;
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}