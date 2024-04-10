#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long Int;

Int arr[100001];
Int sums[100001];
Int OFFSET=1000000000;

int main()
{
    Int n,k;
    Int i;
    Int uk;
    Int need;
    Int maxtimes=0,num=0;
    Int l,r,mid;
    Int best;
    Int cost;
    Int example;
    Int times;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&arr[i]);
        arr[i]=arr[i]+OFFSET;
    }
    sort(arr+1,arr+1+n);
    sums[0]=0;
    
    for (i=1;i<=n;i++)
    {
        sums[i]=sums[i-1]+arr[i];
    }
    
    uk=1;
    while(uk<=n)
    {
        need=((uk-1)*arr[uk])-sums[uk-1];
        
        l=0;
        r=uk-1;
        
        best=uk-1;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            cost=need-( mid*arr[uk]-sums[mid] );
            
            if (cost<=k)
            {
                best=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        times=uk-1-best;
        
        example=arr[uk];
        while(uk<=n && arr[uk]==example)
        {
            times++;
            uk++;
        }
        if (times>maxtimes)
        {
            maxtimes=times;
            num=example;
        }
    }
    printf("%I64d %I64d\n",maxtimes,num-OFFSET);
    return 0;
}