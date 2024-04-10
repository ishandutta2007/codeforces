#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int arr[101];

int main()
{
    Int n;
    Int i;
    Int themin=999999999,themax=-1;
    Int foundmax,foundmin;
    Int d;
    Int secs=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&arr[i]);
    }
    for (i=1;i<=n;i++)
    {
        if (themin>arr[i])
        themin=arr[i];
        
        if (themax<arr[i])
        themax=arr[i];
    }
    for (i=1;i<=n;i++)
    {
        if (arr[i]==themax)
        {
            foundmax=i;
            break;
        }
    }
    for (i=foundmax;i>=2;i--)
    {
        d=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=d;
        
        secs++;
    }
    for (i=n;i>=1;i--)
    {
        if (arr[i]==themin)
        {
            foundmin=i;
            break;
        }
    }
    for (i=foundmin;i<=n-1;i++)
    {
        d=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=d;
        
        secs++;
    }
    printf("%I64d\n",secs);
    return 0;
}