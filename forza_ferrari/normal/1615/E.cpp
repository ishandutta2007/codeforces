#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[200001<<2];
int n,m,tot,h[200001<<2],s[200001<<2],son[200001<<2],ans,sum;
multiset<int> dp[200001<<2];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs1(int k,int f)
{
    son[k]=-1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k);
        s[k]+=s[e[i].to];
        if(son[k]==-1||s[e[i].to]>s[son[k]])
            son[k]=e[i].to;
    }
    if(son[k]==-1)
    {
        s[k]=1;
        son[k]=k;
    }
    son[k]=son[son[k]];
}
inline void dfs2(int k,int f)
{
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs2(e[i].to,k);
    }
    for(int i=h[k];i;i=e[i].nxt)
        if(e[i].to!=f&&son[k]!=son[e[i].to])
            dp[son[k]].insert(dp[son[e[i].to]].begin(),dp[son[e[i].to]].end());
    if(son[k]==k)
        dp[son[k]].insert(0);
    int val=*dp[son[k]].begin()-1;
    dp[son[k]].erase(dp[son[k]].begin());
    dp[son[k]].insert(val);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    ans=-1ll<<60;
    sum=n;
    for(int i=1;i<n;++i)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int r=0;r<=m;++r)
    {
        int b=min(n>>1,sum),w=max(n-r-b,0ll);
        ans=max(ans,w*(r-b));
        if(dp[son[1]].empty())
            continue;
        sum+=*dp[son[1]].begin();
        dp[son[1]].erase(dp[son[1]].begin());
    }
    printf("%lld\n",ans);
    return 0;
}