#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[300001<<1];
int t,n,tot,h[300001],dfn[300001][2],val[300001],cnt,pre[300001],nxt[300001],maxn[300001],ans[300001],dp[300001][2];
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
inline void dfs1(int k,int f,int deep)
{
    dfn[k][0]=++cnt;
    val[cnt]=deep;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k,deep+1);
    }
    dfn[k][1]=cnt;
}
inline void dfs2(int k,int f)
{
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs2(e[i].to,k);
        ans[k]=max(ans[k],max(maxn[k]+maxn[e[i].to]+1,ans[e[i].to]));
        maxn[k]=max(maxn[k],maxn[e[i].to]+1);
    }
    int p1=(ans[k]+1)>>1,p2=max(pre[dfn[k][0]-1],nxt[dfn[k][1]+1]);
    if(p1>=p2)
        dp[1][0]=min(dp[1][0],p1);
    else
    {
        dp[p2-p1][0]=min(dp[p2-p1][0],p1);
        dp[p2-p1][1]=min(dp[p2-p1][1],p2);
    }
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<n;++i)
        {
            dp[i][0]=dp[i][1]=1e9;
            int x=read(),y=read();
            add(x,y);
            add(y,x);
        }
        dp[n][0]=dp[n][1]=0x3f3f3f3f;
        dfs1(1,0,0);
        pre[0]=nxt[n+1]=0;
        for(int i=1;i<=n;++i)
            pre[i]=max(pre[i-1],val[i]);
        for(int i=n;i>=1;--i)
            nxt[i]=max(nxt[i+1],val[i]);
        dfs2(1,0);
        for(int i=2;i<=n;++i)
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        for(int i=n-1;i>=1;--i)
            dp[i][1]=min(dp[i][1],dp[i+1][1]);
        for(int i=1;i<=n;++i)
            cout<<min(min(dp[i][0]+i,dp[i][1]),pre[n])<<" ";
        cout<<'\n';
        tot=cnt=0;
        for(int i=1;i<=n;++i)
            val[i]=h[i]=maxn[i]=pre[i]=nxt[i]=ans[i]=dfn[i][0]=dfn[i][1]=0;
    }
    return 0;
}