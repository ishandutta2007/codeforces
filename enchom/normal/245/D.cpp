#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int bits[101][33];
Int table[101][101];
Int binarytable[101][101][33];

void Binary(Int x,Int y)
{
    Int num=table[x][y];
    Int i;
    
    for (i=32;i>=1;i--)
    {
        binarytable[x][y][i]=num%2;
        num=num/2;
    }
    return;
}

Int Decimal(Int k)
{
    Int num=0;
    Int i;
    
    for (i=32;i>=1;i--)
    {
        if ( bits[k][i]==1 )
        {
            num=num+(1<<32-i);
        }
    }
    return num;
}

int main()
{
    Int i,j,in,ja;
    Int n;
    bool changed;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%I64d",&table[i][j]);
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=32;j++)
        bits[i][j]=2;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i!=j)
            {
                Binary(i,j);
            }
        }
    }
    
    do
    {
        changed=false;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (i!=j)
                {
                    for (in=1;in<=32;in++)
                    {
                        if ( bits[i][in]==2 || bits[j][in]==2 )
                        {
                            if ( binarytable[i][j][in]==1 )
                            {
                                bits[i][in]=1;
                                bits[j][in]=1;
                                changed=true;
                            }
                            else
                            {
                                if ( bits[i][in]==1 )
                                {
                                    bits[j][in]=0;
                                    changed=true;
                                }
                                else if ( bits[j][in]==1 )
                                {
                                    bits[i][in]=0;
                                    changed=true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(changed);
    
    for (i=1;i<=n;i++)
    {
        for (in=1;in<=32;in++)
        {
            if (bits[i][in]==2)
            {
                bits[i][in]=0;
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("%I64d",Decimal(i));
        if (i==n)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}