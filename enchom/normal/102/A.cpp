#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long Int;

Int cost[101];
bool match[101][101];

int main()
{
    Int n,m;
    Int i,j,in;
    Int a,b;
    Int mincost=999999999;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&cost[i]);
    }
    for (i=0;i<=100;i++)
    {
        for (j=0;j<=100;j++)
        {
            match[i][j]=false;
        }
    }
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        match[a][b]=true;
        match[b][a]=true;
    }
    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            for (in=j+1;in<=n;in++)
            {
                if (match[i][j] && match[j][in] && match[in][i])
                {
                    if (mincost>cost[i]+cost[j]+cost[in])
                    mincost=cost[i]+cost[j]+cost[in];
                }
            }
        }
    }
    if (mincost==999999999)
    {
        printf("-1\n");
    }
    else
    {
        printf("%I64d\n",mincost);
    }
    return 0;
}