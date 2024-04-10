#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long Int;

Int a[101];
Int pairs[101];
Int pL=0;

int main()
{
    Int n;
    Int i;
    Int frames;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    
    sort(a+1,a+1+n);
    
    
    for (i=1;i<n;)
    {
        if (a[i]==a[i+1])
        {
            pL++;
            pairs[pL]=a[i];
            i=i+2;
        }
        else
        i++;
    }
    frames=pL/2;
    printf("%I64d\n",frames);
    return 0;
}