#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

bool knoweachother[6][6];

int main()
{
    Int m;
    Int i,j,in;
    Int a,b;
    
    for (i=0;i<=5;i++)
    {
        for (j=0;j<=5;j++)
        {
            knoweachother[i][j]=false;
        }
    }
    
    scanf("%I64d",&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        
        knoweachother[a][b]=true;
        knoweachother[b][a]=true;
    }
    
    for (i=1;i<=5;i++)
    {
        for (j=i+1;j<=5;j++)
        {
            for (in=j+1;in<=5;in++)
            {
                if ( knoweachother[i][j]==knoweachother[i][in] && knoweachother[i][in]==knoweachother[j][in]  )
                {
                    printf("WIN\n");
                    return 0;
                }
            }
        }
    }
    
    printf("FAIL\n");
    return 0;
}