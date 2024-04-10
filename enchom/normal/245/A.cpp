#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int succeed[3];
Int total[3];

int main()
{
    Int n;
    Int i,t,x,y;
    
    scanf("%I64d",&n);
    
    succeed[1]=0;
    succeed[2]=0;
    total[1]=0;
    total[2]=0;
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d %I64d",&t,&x,&y);
        
        succeed[t]+=x;
        total[t]+=10;
    }
    
    if (succeed[1]>=total[1]/2)
    {
        printf("LIVE\n");
    }
    else
    {
        printf("DEAD\n");
    }
    
    if (succeed[2]>=total[2]/2)
    {
        printf("LIVE\n");
    }
    else
    {
        printf("DEAD\n");
    }
}