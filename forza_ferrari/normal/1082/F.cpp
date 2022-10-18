#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
int tot,n,m,dep[501],ch[501][15],cnt[501],dp[501][501][15];
inline void insert()
{
    string s;
    int node=0,w;
    cin>>s>>w;
    for(auto i:s)
    {
        if(!ch[node][i-'0'])
        {
            ch[node][i-'0']=++tot;
            dep[tot]=dep[node]+1;
        }
        node=ch[node][i-'0'];
    }
    cnt[node]+=w;
}
inline void dfs(int k)
{
    for(int i=0;i<=tot;++i)
        for(int j=0;j<=m;++j)
            dp[k][i][j]=1e9;
    for(int i=0;i<=dep[k];++i)
        dp[k][i][i==dep[k]]=1ll*cnt[k]*(dep[k]-i);
    int tmp[501][11];
    for(int i=0;i<10;++i)
        if(ch[k][i])
        {
            dfs(ch[k][i]);
            for(int x=0;x<=dep[k];++x)
                for(int y=0;y<=m;++y)
                {
                    tmp[x][y]=dp[k][x][y];
                    dp[k][x][y]=1e9;
                }
            for(int j=0;j<=dep[k];++j)
                for(int x=0;x<=m;++x)
                    for(int y=0;x+y<=m;++y)
                        dp[k][j][x+y]=min(dp[k][j][x+y],tmp[j][x]+min(dp[ch[k][i]][j][y],dp[ch[k][i]][dep[ch[k][i]]][y]));
        }
}
signed main()
{
    cin>>n>>m;
    ++m;
    for(int i=1;i<=n;++i)
        insert();
    dfs(0);
    int ans=1e9;
    for(int i=0;i<=m;++i)
        ans=min(ans,dp[0][0][i]);
    cout<<ans<<'\n';
    return 0;
}