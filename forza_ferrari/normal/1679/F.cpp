#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m,dp[50001][1<<10],g[1<<10][10];
bool vis[11][11];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        vis[x][y]=vis[y][x]=1;
    }
    for(int s=0;s<1<<10;++s)
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<i;++j)
                if((s>>j&1)&&vis[i][j])
                {
                    g[s][i]=-1;
                    break;
                }
            if(g[s][i]!=-1)
                for(int j=0;j<10;++j)
                    if(i==j||((s>>j&1)&&vis[i][j]))
                        g[s][i]|=1<<j;
        }
    dp[0][0]=1;
    for(int i=0;i<n;++i)
        for(int s=0;s<1<<10;++s)
            if(dp[i][s])
                for(int j=0;j<10;++j)
                    if(g[s][j]!=-1)
                        dp[i+1][g[s][j]]=(dp[i+1][g[s][j]]+dp[i][s])%mod;
    int ans=0;
    for(int s=0;s<1<<10;++s)
        ans=(ans+dp[n][s])%mod;
    cout<<ans<<'\n';
    return 0;
}