#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

bool tied[101][101];
bool TFO[101];
Int gonnakick[101];
Int gkL=0;

int main()
{
    Int i,j;
    Int n,m;
    Int tiedto=0;
    Int a,b;
    Int groups=0;
    
    for (i=0;i<=100;i++)
    {
        TFO[i]=false;
        for (j=0;j<=100;j++)
        {
            tied[i][j]=false;
        }
    }
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        tied[a][b]=true;
        tied[b][a]=true;
    }
    while(1)
    {
        gkL=0;
        for (i=1;i<=n;i++)
        {
            if (TFO[i])
            continue;
            
            tiedto=0;
            for (j=1;j<=n;j++)
            {
                if (tied[i][j] && !TFO[j])
                tiedto++;
            }
            if (tiedto==1)
            {
                gkL++;
                gonnakick[gkL]=i;
            }
        }
        if (gkL==0)
        break;
        
        groups++;
        for (i=1;i<=gkL;i++)
        {
            TFO[gonnakick[i]]=true;
        }
    }
    printf("%I64d\n",groups);
    return 0;
}