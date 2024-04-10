#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int n,m,q,cnt,bin[200001],dfn[200001],low[200001],tot,col[200001],sum[200001][2],dep[200001],fa[200001][21];
bool vis[200001],flag;
vector<int> v[200001],g[200001],root;
stack<int> t;
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
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
inline void tarjan(int k,int f)
{
    vis[k]=1;
    dfn[k]=low[k]=++cnt;
    t.emplace(k);
    bool tag=1;
    for(int i:v[k])
    {
        if(i==f&&tag)
        {
            tag=0;
            continue;
        }
        if(!dfn[i])
        {
            tarjan(i,k);
            low[k]=min(low[k],low[i]);
        }
        else
            if(vis[i])
                low[k]=min(low[k],dfn[i]);
    }
    if(dfn[k]==low[k])
    {
        vis[k]=0;
        col[k]=++tot;
        while(!t.empty()&&t.top()!=k)
        {
            vis[t.top()]=0;
            col[t.top()]=tot;
            t.pop();
        }
        if(!t.empty())
            t.pop();
    }
}
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k][0]=f;
    for(int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(int i:g[k])
    {
        if(i==f)
            continue;
        dfs1(i,k,deep+1);
    }
}
inline void dfs2(int k,int f)
{
    for(int i:g[k])
    {
        if(i==f)
            continue;
        dfs2(i,k);
        sum[k][0]+=sum[i][0];
        sum[k][1]+=sum[i][1];
    }
    if(sum[k][0]&&sum[k][1])
        flag=0;
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(int d=dep[x]-dep[y],i=0;1<<i<=d;++i)
        if(d>>i&1)
            x=fa[x][i];
    if(x==y)
        return x;
    for(int i=20;~i;--i)
        if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
int main()
{
    n=read(),m=read(),q=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
        link(x,y);
    }
    for(int i=1;i<=n;++i)
        if(!dfn[i])
            tarjan(i,0);
    for(int i=1;i<=n;++i)
        for(int j:v[i])
            if(col[i]^col[j])
                g[col[i]].emplace_back(col[j]);
    for(int i=1;i<=n;++i)
        if(!dep[i])
        {
            root.emplace_back(i);
            dfs1(i,0,1);
        }
    while(q--)
    {
        int x=read(),y=read();
        if(anc(x)^anc(y))
        {
            cout<<"NO\n";
            return 0;
        }
        x=col[x],y=col[y];
        int lca=LCA(x,y);
        if(x==y)
            continue;
        ++sum[x][0];
        --sum[lca][0];
        ++sum[y][1];
        --sum[lca][1];
    }
    flag=1;
    for(int i:root)
        dfs2(i,0);
    cout<<(flag? "YES":"NO")<<'\n';
    return 0;
}