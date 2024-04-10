#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int pts=10;
    Int ways=0;
    Int i;
    
    scanf("%I64d",&n);
    
    if (pts+1==n || pts+11==n)
    ways+=4;
    
    for (i=2;i<=10;i++)
    {
        if (pts+i==n)
        {
            ways+=4;
        }
    }
    if (pts+10==n)
    {
        ways+=11;
    }
    
    printf("%I64d\n",ways);
    return 0;
}