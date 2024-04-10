#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long Int;

Int circles[101];

int main()
{
    Int n;
    Int i;
    Int timesP=0;
    double ans;
    Int start;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&circles[i]);
        circles[i]=circles[i]*circles[i];
    }
    sort(circles+1,circles+1+n);
    circles[0]=0;
    if (n%2==1)
    {
        start=1;
    }
    else
    {
        start=2;
    }
    
    for (i=start;i<=n;i=i+2)
    {
        timesP=timesP+(circles[i]-circles[i-1]);
    }
    ans=(double)timesP;
    ans=ans*3.141592653589793;
    printf("%4.8f\n",ans);
    return 0;
}