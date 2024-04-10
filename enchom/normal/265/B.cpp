#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int heights[100001];
Int n;

int main()
{
    Int i;
    Int LissH=0;
    Int secs=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&heights[i]);
    }
    
    for (i=1;i<=n;i++)
    {
        secs=secs+(heights[i]-LissH);
        secs++;
        LissH=heights[i];
        
        
        if (i!=n)
        {
            if (heights[i+1]>=heights[i])
            {
                secs++;
                continue;
            }
            else
            {
                secs=secs+(heights[i]-heights[i+1]);
                LissH=heights[i+1];
                secs++;
                continue;
            }
        }
    }
    
    printf("%I64d\n",secs);
    return 0;
}