#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

int main()
{
    Int a,b,n;
    Int i,j;
    Int ctr=0;
    
    scanf("%I64d %I64d %I64d",&n,&a,&b);
    
    for (i=a;i<=n-1;i++)
    {
        for (j=0;j<=b;j++)
        {
            if (i+j!=n-1)
            continue;
            else
            ctr++;
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}