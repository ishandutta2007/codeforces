#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

Int a[100001];
Int nums[100001];
Int nL=0;
Int PowerOf2[40];

int main()
{
    Int n;
    Int i;
    
    scanf("%I64d",&n);
    
    PowerOf2[0]=1;
    for (i=1;i<=39;i++)
    {
        PowerOf2[i]=PowerOf2[i-1]*2;
    }
    
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    nums[1]=a[1];
    nL=1;
    
    for (i=2;i<=n;i++)
    {
        if (a[i]!=a[i-1])
        {
            nL++;
            nums[nL]=a[i];
        }
    }
    
    for (i=1;i<=nL-1;i++)
    {
        if ( nums[i]*2>nums[i+1] )
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}