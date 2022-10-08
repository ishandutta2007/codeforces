#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long Int;

char stones[51];

int main()
{
    Int n;
    Int i;
    Int ctr=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        cin>>stones[i];
    }
    
    for (i=2;i<=n;i++)
    {
        if (stones[i]==stones[i-1])
        ctr++;
    }
    printf("%I64d\n",ctr);
    return 0;
}