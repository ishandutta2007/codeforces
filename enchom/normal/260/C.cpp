#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int IndexTree[262144];
Int nums[100001];
Int n,x;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

Int Fix(Int k)
{
    if (k>n)
    {
        k-=n;
    }
    return k;
}

Int SmallestNum(Int l,Int r)
{
    Int smallest=MIN(nums[l],nums[r]);
    Int s1,s2;
    if (l>r)
    {
        smallest=MIN( SmallestNum(1,r),SmallestNum(l,n) );
    }
    else
    {
        s1=131071+l;
        s2=131071+r;
        while(s1/2!=s2/2)
        {
            if (s1%2==0)
            {
                smallest=MIN(IndexTree[s1+1],smallest);
            }
            if (s2%2==1)
            {
                smallest=MIN(IndexTree[s2-1],smallest);
            }
            
            s1=s1/2;
            s2=s2/2;
        }
    }
    return smallest;
}

int main()
{
    Int i;
    Int found=-1;
    Int cut;
    Int mynum=0;
    
    for (i=0;i<=262143;i++)
    {
        IndexTree[i]=999999999999;
    }
    
    scanf("%I64d %I64d",&n,&x);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    for (i=131072;i<=131072+n-1;i++)
    {
        IndexTree[i]=nums[i-131071];
    }
    for (i=131071;i>=1;i--)
    {
        IndexTree[i]=MIN(IndexTree[i*2],IndexTree[i*2+1]);
    }
    for (i=1;i<=n;i++)
    {
        ///Lock on i
        if (i==x && nums[i]==0)
        continue;
        
        if ( SmallestNum(1,n)>=nums[i] )
        {
            if (i==x)
            {
                found=i;
                break;
            }
            else
            {
                if ( SmallestNum(Fix(i+1),x)>=nums[i]+1 )
                {
                    found=i;
                    break;
                }
            }
        }
    }
    cut=nums[found];
    for (i=1;i<=n;i++)
    {
        nums[i]-=cut;
        mynum+=cut;
    }
    
    i=found+1;
    if (x!=found)
    while(1)
    {
        i=Fix(i);
        
        nums[i]--;
        mynum++;
        
        if (i==x)
        break;
        
        i++;
    }
    nums[found]=mynum;
    for (i=1;i<=n;i++)
    {
        printf("%I64d",nums[i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");
    
    return 0;
}