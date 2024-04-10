#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[100001];
int n,m,mod,tot,h[601],g[601][601],d[601][2],cnt1,cnt2,dp[601][601];
int s[601],t[601];
bool vis[601];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int solve(int n)
{
    int ans=1;
    bool tag=0;
    for(register int i=1;i<=n;++i)
    {
        for(register int j=i+1;j<=n;++j)
            if(!g[i][i]&&g[j][i])
            {
                swap(g[i],g[j]);
                tag^=1;
                break;
            }
        ans=1ll*ans*g[i][i]%mod;
        int d=pw(g[i][i],mod-2);
        for(register int j=i;j<=n;++j)
            g[i][j]=1ll*g[i][j]*d%mod;
        for(register int j=i+1;j<=n;++j)
        {
            d=g[j][i];
            for(register int k=i;k<=n;++k)
                g[j][k]=(g[j][k]-1ll*d*g[i][k]%mod+mod)%mod;
        }
    }
    return tag? (mod-ans)%mod:ans;
}
void dfs(int k)
{
    vis[k]=1;
    if(t[k])
    {
        dp[k][k]=1;
        return;
    }
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(!vis[e[i].to])
            dfs(e[i].to);
        for(register int j=1;j<=n;++j)
            dp[k][j]=(dp[k][j]+dp[e[i].to][j])%mod;
    }
}
signed main()
{
    n=read(),m=read(),mod=read();
    while(m--)
    {
        int x=read(),y=read();
        add(x,y);
        ++d[x][1],++d[y][0];
    }
    for(register int i=1;i<=n;++i)
        dp[i][i]=1;
    for(register int i=1;i<=n;++i)
    {
        if(!d[i][0])
            s[i]=++cnt1;
        if(!d[i][1])
            t[i]=++cnt2;
    }
    for(register int i=1;i<=n;++i)
        if(s[i])
            dfs(i);
    for(register int i=1;i<=n;++i)
        if(s[i])
            for(register int j=1;j<=n;++j)
                if(t[j])
                    g[s[i]][t[j]]=dp[i][j];
    printf("%lld\n",solve(cnt1));
    return 0;
}