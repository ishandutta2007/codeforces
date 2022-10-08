#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int nums[100001];

int main()
{
    Int n,k;
    Int i,j;
    Int sum=0,books=0,beg;
    Int maxbooks=0;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    
    beg=0;
    sum=0;
    books=0;
    for (i=1;i<=n;i++)
    {
        if (sum==0)
        {
            if (nums[i]<=k)
            {
                beg=i;
                books=1;
                sum=nums[i];
                
                if (maxbooks<books)
                maxbooks=books;
            }
        }
        else
        {
            
            while(nums[i]+sum>k && sum>0)
            {
                sum=sum-nums[beg];
                beg++;
                books--;
            }
            
            if (nums[i]+sum<=k)
            {
                books++;
                sum+=nums[i];
                
                if (maxbooks<books)
                maxbooks=books;
            }
            
        }
    }
    
    printf("%I64d\n",maxbooks);
    
    return 0;
}