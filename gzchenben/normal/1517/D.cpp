#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,R[505][505],D[505][505],dp[505][505][21];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&D[i][j]);
        }
    }
    if(k%2==1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",-1);
            }
            printf("\n");
        }
        return 0;
    }
    k/=2;
    for(int i=1;i<=k;i++)
    {
        for(int x=1;x<=n;x++)
        {
            for(int y=1;y<=m;y++)
            {
                dp[x][y][i]=1000000000;
                if(x!=1) dp[x][y][i]=min(dp[x][y][i],dp[x-1][y][i-1]+2*D[x-1][y]);
                if(x!=n) dp[x][y][i]=min(dp[x][y][i],dp[x+1][y][i-1]+2*D[x][y]);
                if(y!=1) dp[x][y][i]=min(dp[x][y][i],dp[x][y-1][i-1]+2*R[x][y-1]);
                if(y!=m) dp[x][y][i]=min(dp[x][y][i],dp[x][y+1][i-1]+2*R[x][y]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ",dp[i][j][k]);
        }
        printf("\n");
    }
}