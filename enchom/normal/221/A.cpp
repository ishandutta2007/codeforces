#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int i;
    
    scanf("%I64d",&n);
    
    printf("%I64d",n);
    if (n!=1)
    printf(" ");
    
    for (i=1;i<=n-1;i++)
    {
        printf("%I64d",i);
        if (i!=n-1)
        printf(" ");
    }
    printf("\n");
    return 0;
}