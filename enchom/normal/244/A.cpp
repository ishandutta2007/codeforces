#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int TFO[901];

int main()
{
    Int n,k;
    Int i,j;
    Int a;
    Int ctr=0;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=0;i<=900;i++)
    TFO[i]=0;
    
    for (i=1;i<=k;i++)
    {
        scanf("%I64d",&a);
        
        TFO[a]=i;
    }
    
    for (i=1;i<=k;i++)
    {
        ctr=1;
        for (j=1;i<=n*k;j++)
        {
            if (ctr==n)
            break;
            
            if (TFO[j]==0)
            {
                TFO[j]=i;
                ctr++;
            }
        }
    }
    for (i=1;i<=k;i++)
    {
        for (j=1;j<=n*k;j++)
        {
            if (TFO[j]==i)
            printf("%I64d ",j);
        }
        printf("\n");
    }
    return 0;
}