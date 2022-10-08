#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char table[101][101];
bool TFO[101][101];

int main()
{
    Int i,j,in;
    Int n,m;
    
    for (i=0;i<=100;i++)
    {
        for (j=0;j<=100;j++)
        {
            TFO[i][j]=false;
        }
    }
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>table[i][j];
        }
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (!TFO[i][j])
            {
                for (in=1;in<=n;in++)
                {
                    if (table[in][j]==table[i][j] && i!=in)
                    {
                        TFO[i][j]=true;
                        TFO[in][j]=true;
                    }
                }
                for (in=1;in<=m;in++)
                {
                    if (table[i][in]==table[i][j] && j!=in)
                    {
                        TFO[i][j]=true;
                        TFO[i][in]=true;
                    }
                }
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (!TFO[i][j])
            printf("%c",table[i][j]);
        }
    }
    printf("\n");
    return 0;
}