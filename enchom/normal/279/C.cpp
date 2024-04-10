#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct intrv
{
    Int l,r;
};

intrv holes[100001];
Int hL=0;
Int nums[100001];

bool SortHoles(intrv a,intrv b)
{
    if (a.l<b.l)
    return true;
    else if (a.l>b.l)
    return false;
    else
    {
        return (a.r<b.r);
    }
}

int main()
{
    Int n,m;
    Int i,j;
    bool holing=false;
    Int L,R;
    Int l,r,mid;
    Int ind1,ind2;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    
    for (i=2;i<=n;i++)
    {
        if (holing)
        {
            if (nums[i]==nums[i-1])
            continue;
            else if (nums[i]<nums[i-1])
            {
                holes[hL].l=i-1;
            }
            else
            {
                holes[hL].r=i;
                holing=false;
            }
        }
        else
        {
            if (nums[i]<nums[i-1])
            {
                holing=true;
                hL++;
                holes[hL].l=i-1;
            }
        }
    }
    
    if (holing)
    hL--;
    
    sort(holes+1,holes+1+hL,SortHoles);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&L,&R);
        
        l=1;
        r=hL;
        ind1=-1;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if ( holes[mid].l>=L )
            {
                ind1=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        if (ind1==-1)
        {
            printf("Yes\n");
            continue;
        }
        
        l=1;
        r=hL;
        ind2=-1;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if ( holes[mid].l<=R )
            {
                ind2=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        if (ind2==-1)
        {
            printf("Yes\n");
            continue;
        }
        
        if (ind2-ind1+1>1)
        {
            printf("No\n");
        }
        else if (ind2-ind1+1==1)
        {
            if (holes[ind1].r<=R)
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
        else
        {
            printf("Yes\n");
        }
    }
    
    return 0;
}