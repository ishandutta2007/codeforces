#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int done[5001];

int main()
{
    Int n,i;
    Int a;
    Int ctr=0;
    
    scanf("%I64d",&n);
    
    for (i=0;i<=5000;i++)
    done[i]=false;
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        done[a]=true;
    }
    for (i=1;i<=n;i++)
    {
        if (!done[i])
        ctr++;
    }
    printf("%I64d\n",ctr);
    return 0;
}