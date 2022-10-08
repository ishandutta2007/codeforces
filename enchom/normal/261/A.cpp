#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int items[100001];
Int lowestoffert=999999999;
Int price=0;

int main()
{
    Int i;
    Int n,m;
    Int cart=0;
    Int freeleft=0;
    Int a;
    
    scanf("%I64d",&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&a);
        if (lowestoffert>a)
        lowestoffert=a;
    }
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&items[i]);
    }
    
    sort(items+1,items+1+n);
    
    for (i=n;i>=1;i--)
    {
        if (freeleft>0)
        {
            freeleft--;
            continue;
        }
        price=price+items[i];
        cart++;
        if (cart==lowestoffert)
        {
            freeleft=2;
            cart=0;
        }
    }
    printf("%I64d\n",price);
    return 0;
}