#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[301<<1];
int n,m,tot,h[301],dp[301][301],a[301],ans,g[301];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f)
{
    dp[k][0]=a[k];
    bool flag=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        int tmp=0;
        for(int j=m-1;j<n;++j)
            tmp=max(tmp,dp[e[i].to][j]);
        dp[k][0]+=tmp;
        if(flag)
        {
            for(int j=0;j<n;++j)
                dp[k][j+1]=dp[e[i].to][j];
            flag=0;
        }
        else
        {
            for(int j=1;j<=n;++j)
                g[j]=0;
            for(int j=1;j<=n;++j)
                for(int p=max(m-1-j,0);p<n;++p)
                    g[min(j,p+1)]=max(g[min(j,p+1)],dp[e[i].to][p]+dp[k][j]);
            for(int j=1;j<=n;++j)
                dp[k][j]=g[j];
        }
    }
}
int main()
{
    cin>>n>>m;
    ++m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    for(int i=0;i<=n;++i)
        ans=max(ans,dp[1][i]);
    cout<<ans<<endl;
    return 0;
}