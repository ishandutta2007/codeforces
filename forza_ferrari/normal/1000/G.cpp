#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
struct edge
{
    int node,val1,val2;
    edge(int node_,int val1_,int val2_):
        node(node_),val1(val1_),val2(val2_){}
};
vector<edge> v[300001];
//0~1 dp0~1 2 3 4
int n,m,a[300001],dp[300001][3],sum[300001][3],dep[300001],fa[300001],s[300001],son[300001],top[300001],dfn[300001],cnt;
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
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k]=f;
    s[k]=1;
    dp[k][0]=a[k];
    for(auto i:v[k])
    {
        if(i.node==f)
            continue;
        dfs1(i.node,k,deep+1);
        s[k]+=s[i.node];
        if(s[i.node]>s[son[k]])
            son[k]=i.node;
        dp[k][0]+=max(dp[i.node][0]-i.val1-i.val2,0ll);
    }
    for(auto i:v[k])
    {
        if(i.node==f)
            continue;
        dp[i.node][1]=dp[k][0]-max(dp[i.node][0]-i.val1-i.val2,0ll);
    }
}
inline void dfs2(int k,int f,int t,int val1,int val2)
{
    top[k]=t;
    dfn[k]=++cnt;
    if(k==1)
        dp[k][2]=dp[k][0];
    else
        dp[k][2]=dp[k][0]+max(dp[f][2]-max(dp[k][0]-val1-val2,0ll)-val1-val2,0ll);
    sum[cnt][0]=sum[cnt-1][0]+dp[k][1];
    sum[cnt][1]=sum[cnt-1][1]+val1;
    sum[cnt][2]=sum[cnt-1][2]+val2;
    if(!son[k])
        return;
    for(auto i:v[k])
        if(i.node==son[k])
        {
            dfs2(son[k],k,t,i.val1,i.val2);
            break;
        }
    for(auto i:v[k])
    {
        if(i.node==son[k]||i.node==fa[k])
            continue;
        dfs2(i.node,k,i.node,i.val1,i.val2);
    }
}
inline int LCA(int x,int y)
{
    while(top[x]^top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            x^=y^=x^=y;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])
        x^=y^=x^=y;
    return x;
}
inline int find(int x,int y)
{
    while(top[x]^top[y])
    {
        if(fa[top[y]]==x)
            return top[y];
        y=fa[top[y]];
    }
    return son[x];
}
//0 dp1 1 2
inline int q(int x,int y)
{
    if(x==y)
        return dp[x][2];
    int lca=LCA(x,y),res=0;
    if(lca==x)
    {
        int node=find(x,y);
        res=dp[y][0]+(dp[x][2]-max(dp[node][0]-sum[dfn[node]][1]+sum[dfn[node]-1][1]-sum[dfn[node]][2]+sum[dfn[node]-1][2],0ll))-dp[node][1];
        while(top[x]^top[y])
        {
            res-=sum[dfn[y]][1]-sum[dfn[top[y]]-1][1];
            res+=sum[dfn[y]][0]-sum[dfn[top[y]]-1][0];
            y=fa[top[y]];
        }
        res-=sum[dfn[y]][1]-sum[dfn[x]][1];
        res+=sum[dfn[y]][0]-sum[dfn[x]][0];
        return res;
    }
    if(lca==y)
    {
        int node=find(y,x);
        res=dp[x][0]+(dp[y][2]-max(dp[node][0]-sum[dfn[node]][1]+sum[dfn[node]-1][1]-sum[dfn[node]][2]+sum[dfn[node]-1][2],0ll))-dp[node][1];
        while(top[x]^top[y])
        {
            res-=sum[dfn[x]][2]-sum[dfn[top[x]]-1][2];
            res+=sum[dfn[x]][0]-sum[dfn[top[x]]-1][0];
            x=fa[top[x]];
        }
        res-=sum[dfn[x]][2]-sum[dfn[y]][2];
        res+=sum[dfn[x]][0]-sum[dfn[y]][0];
        return res;
    }
    int node1=find(lca,x),node2=find(lca,y);
    res=dp[x][0]+dp[y][0]+(dp[lca][2]-max(dp[node1][0]-sum[dfn[node1]][1]+sum[dfn[node1]-1][1]-sum[dfn[node1]][2]+sum[dfn[node1]-1][2],0ll)-max(dp[node2][0]-sum[dfn[node2]][1]+sum[dfn[node2]-1][1]-sum[dfn[node2]][2]+sum[dfn[node2]-1][2],0ll))-dp[node1][1]-dp[node2][1];
    while(top[x]^top[lca])
    {
        res-=sum[dfn[x]][2]-sum[dfn[top[x]]-1][2];
        res+=sum[dfn[x]][0]-sum[dfn[top[x]]-1][0];
        x=fa[top[x]];
    }
    res-=sum[dfn[x]][2]-sum[dfn[lca]][2];
    res+=sum[dfn[x]][0]-sum[dfn[lca]][0];
    while(top[lca]^top[y])
    {
        res-=sum[dfn[y]][1]-sum[dfn[top[y]]-1][1];
        res+=sum[dfn[y]][0]-sum[dfn[top[y]]-1][0];
        y=fa[top[y]];
    }
    res-=sum[dfn[y]][1]-sum[dfn[lca]][1];
    res+=sum[dfn[y]][0]-sum[dfn[lca]][0];
    return res;
}
signed main()
{
    //freopen("strawberry.in","r",stdin);
    //freopen("strawberry.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read(),w=read();
        v[x].emplace_back(y,w,w);
        v[y].emplace_back(x,w,w);
    }
    dfs1(1,0,1);
    dfs2(1,0,1,0,0);
    while(m--)
    {
        int x=read(),y=read();
        cout<<q(x,y)<<'\n';
    }
    return 0;
}