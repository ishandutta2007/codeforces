#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

Int a[101];

int main()
{
    Int n;
    Int i;
    Int clicks=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    
    for (i=1;i<=n;i++)
    {
        clicks=clicks+( (i-1)*(a[i]-1)+a[i] );
    }
    printf("%I64d\n",clicks);
    return 0;
}