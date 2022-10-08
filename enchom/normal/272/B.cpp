#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int nums[100001];
Int ONES[51];

Int HowManyOnes(Int k)
{
    Int ctr=0;
    
    while(k>0)
    {
        if (k%2==1)
        ctr++;
        
        k=k/2;
    }
    return ctr;
}

int main()
{
    Int n;
    Int i;
    Int total=0;
    
    for (i=0;i<=50;i++)
    ONES[i]=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
        
        ONES[ HowManyOnes(nums[i]) ]++;
    }
    
    for (i=1;i<=50;i++)
    {
        total=total+( ONES[i]*(ONES[i]-1) )/2;
    }
    
    printf("%I64d\n",total);
    
    return 0;
}