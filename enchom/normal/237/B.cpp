#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct Xswap
{
    Int x,y,p,q;
};

Xswap swaps[10001];
Int sL=0;
Int c[101];
Int table[101][101];

int main()
{
    Int n;
    Int i,j,in,ja;
    Int current,d;
    bool flag;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&c[i]);
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=c[i];j++)
        {
            scanf("%I64d",&table[i][j]);
        }
    }
    
    current=1;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=c[i];j++)
        {
            if (table[i][j]==current)
            {
                current++;
                continue;
            }
            
            flag=false;
            for (in=1;in<=n;in++)
            {
                for (ja=1;ja<=c[in];ja++)
                {
                    if (table[in][ja]==current)
                    {
                        sL++;
                        swaps[sL].x=i;
                        swaps[sL].y=j;
                        swaps[sL].p=in;
                        swaps[sL].q=ja;
                        
                        d=table[i][j];
                        table[i][j]=table[in][ja];
                        table[in][ja]=d;
                        
                        flag=true;
                        break;
                    }
                }
                if (flag)
                break;
            }
            current++;
        }
    }
    printf("%I64d\n",sL);
    for (i=1;i<=sL;i++)
    {
        printf("%I64d %I64d %I64d %I64d\n",swaps[i].x,swaps[i].y,swaps[i].p,swaps[i].q);
    }
    return 0;
}