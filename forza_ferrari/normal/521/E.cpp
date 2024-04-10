#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001<<1];
bool vis[200001];
vector<int> g[200001],ans;
vector<pair<int,int> > nt;
int n,m,dep[200001],d[200001],tot,h[200001],fa[200001][21];
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
inline int lca(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(register int d=dep[x]-dep[y],i=0;1<<i<=d;++i)
        if(d&(1<<i))
            x=fa[x][i];
    if(x==y)
        return x;
    for(register int i=20;~i;--i)
        if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
inline void solve(int x,int y)
{
    puts("YES");
    int cnt=0,u[3]={0},v[3]={0};
    bool tag=0;
    for(register int i=0;i<(int)nt.size();++i)
    {
        u[0]=nt[i].first,v[0]=nt[i].second;
        if(dep[u[0]]>dep[v[0]])
            u[0]^=v[0]^=u[0]^=v[0];
        if(lca(x,u[0])==u[0]&&lca(y,v[0])==y)
        {
            ++cnt;
            u[cnt]=u[0];
            v[cnt]=v[0];
        }
        if(cnt==2)
            break;
    }
    if(dep[u[1]]>dep[u[2]])
    {
        u[1]^=u[2]^=u[1]^=u[2];
        tag^=1;
    }
    if(dep[v[1]]>dep[v[2]])
    {
        v[1]^=v[2]^=v[1]^=v[2];
        tag^=1;
    }
    int LCA=lca(v[1],v[2]),node=LCA;
    ans.clear();
    ans.push_back(node);
    while(node!=u[2])
    {
        node=fa[node][0];
        ans.push_back(node);
    }
    reverse(ans.begin(),ans.end());
    printf("%d ",(int)ans.size());
    for(register int i=0;i<(int)ans.size();++i)
        printf("%d ",ans[i]);
    puts("");
    ans.clear();
    ans.push_back(u[2]);
    node=u[2];
    while(node!=u[1])
    {
        node=fa[node][0];
        ans.push_back(node);
    }
    node=v[1+tag];
    ans.push_back(node);
    while(node!=LCA)
    {
        node=fa[node][0];
        ans.push_back(node);
    }
    printf("%d ",(int)ans.size());
    for(register int i=0;i<(int)ans.size();++i)
        printf("%d ",ans[i]);
    puts("");
    ans.clear();
    ans.push_back(u[2]);
    node=v[2-tag];
    ans.push_back(node);
    while(node!=LCA)
    {
        node=fa[node][0];
        ans.push_back(node);
    }
    printf("%d ",(int)ans.size());
    for(register int i=0;i<(int)ans.size();++i)
        printf("%d ",ans[i]);
    puts("");
}
void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    vis[k]=1;
    fa[k][0]=f;
    for(register int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        if(vis[e[i].to])
        {
            ++d[k];
            --d[e[i].to];
            nt.push_back(make_pair(k,e[i].to));
        }
        else
            if(!dep[e[i].to])
            {
                g[k].push_back(e[i].to);
                dfs1(e[i].to,k,deep+1);
            }
    }
    vis[k]=0;
}
void dfs2(int k,int f)
{
    for(register int i=0;i<(int)g[k].size();++i)
    {
        dfs2(g[k][i],k);
        d[k]+=d[g[k][i]];
    }
    if(d[k]>=2)
    {
        solve(f,k);
        exit(0);
    }
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    for(register int i=1;i<=n;++i)
        if(!dep[i])
        {
            nt.clear();
            dfs1(i,0,1);
            dfs2(i,0);
        }
    puts("NO");
    return 0;
}