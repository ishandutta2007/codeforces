#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;

bool arr[1001];
Int team[1001][1001];
Int tL;
Int n;

bool AllTrues()
{
    Int i;
    
    for (i=1;i<=n;i++)
    {
        if (!arr[i])
        return false;
    }
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Int i,j;
    Int lastline;
    Int k=0;
    Int beenansatruenigga=0;
    bool first;
    
    scanf("%I64d",&n);
    
    if (n==2)
    {
        printf("1\n1 1\n");
        return 0;
    }
    
    for (i=1;i<=n;i++)
    {
        arr[i]=false;
    }
    
    arr[n]=true;
    arr[n/2]=true;
    
    while( 1 )
    {
        k++;
        tL=0;
        first=true;
        lastline=0;
        
        for (i=1;i<=n;i++)
        {
            if (first)
            {
                tL++;
                team[k][tL]=i;
            }
            
            if (arr[i])
            {
                if (first)
                first=false;
                else
                first=true;
                
                arr[ (i+lastline)/2 ]=true;
                lastline=i;
            }
        }
        team[k][0]=tL;
        
        if ( AllTrues() )
        {
            beenansatruenigga++;
            if (beenansatruenigga>=2)
            {
                break;
            }
        }
    }
    
    printf("%I64d\n",k);
    
    for (i=1;i<=k;i++)
    {
        printf("%I64d",team[i][0]);
        for (j=1;j<=team[i][0];j++)
        {
            printf(" %I64d",team[i][j]);
        }
        printf("\n");
    }
    return 0;
}