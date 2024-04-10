#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int main()
{
    Int a[5];
    Int i;
    Int ctr=0;
    
    scanf("%I64d %I64d %I64d %I64d",&a[1],&a[2],&a[3],&a[4]);
    
    sort(a+1,a+5);
    
    for (i=2;i<=4;i++)
    {
        if (a[i]==a[i-1])
        {
            ctr++;
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}