#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int nums[100001];
Int ournums[100001];
Int onL=0;

int main()
{
    Int n,k;
    Int i,j;
    Int l,r,mid;
    Int badnum;
    bool found;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    
    sort(nums+1,nums+1+n);
    
    for (i=1;i<=n;i++)
    {
        if (nums[i]%k!=0)
        {
            onL++;
            ournums[onL]=nums[i];
        }
        else
        {
            badnum=nums[i]/k;
            l=1;
            r=onL;
            
            found=false;
            while(l<=r)
            {
                mid=(l+r)/2;
                
                if (ournums[mid]==badnum)
                {
                    found=true;
                    break;
                }
                if (ournums[mid]>badnum)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            
            if (!found)
            {
                onL++;
                ournums[onL]=nums[i];
            }
        }
    }
    printf("%I64d\n",onL);
    return 0;
}