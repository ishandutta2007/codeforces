#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int profit[101];
Int n;
Int folders[101];
Int fL=0;
Int baddays=0;

int main()
{
    Int i;
    
    scanf("%I64d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&profit[i]);
    }
    
    for (i=0;i<=100;i++)
    folders[i]=0;
    
    fL=1;
    
    for (i=1;i<=n;i++)
    {
        if (profit[i]>=0)
        {
            folders[fL]++;
        }
        else
        {
            baddays++;
            if (baddays<3)
            {
                folders[fL]++;
            }
            else
            {
                baddays=1;
                fL++;
                folders[fL]++;
            }
        }
    }
    printf("%I64d\n",fL);
    for (i=1;i<=fL;i++)
    {
        printf("%I64d",folders[i]);
        if (i==fL)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}