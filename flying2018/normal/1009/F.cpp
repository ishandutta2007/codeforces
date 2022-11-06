#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 1000010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
int len[N],son[N],fa[N];
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
void dfs1(int u,int p)
{
    fa[u]=p;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs1(v,u);
        if(len[v]+1>len[u]) son[u]=v,len[u]=len[v]+1;
    }
}
vector<int>f[N];
int ans[N];
void dfs2(int u)
{
    if(!son[u]){f[u].push_back(1);return;}
    dfs2(son[u]);
    f[u].swap(f[son[u]]);
    f[u].push_back(1);
    ans[u]=ans[son[u]];
    if(f[u][ans[u]]==1) ans[u]=len[u];
    for(int o=head[u];o;o=nxt[o])
    {
        int v=to[o];
        if(v==fa[u] || v==son[u]) continue;
        dfs2(v);
        for(int i=len[v];i>=0;i--)
        {
            int j=i+len[u]-len[v]-1;
            f[u][j]+=f[v][i];
            if(f[u][j]>f[u][ans[u]] || (f[u][j]==f[u][ans[u]] && j>ans[u])) ans[u]=j;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),add(u,v),add(v,u);
    dfs1(1,0);
    dfs2(1);
    for(int i=1;i<=n;i++) printf("%d\n",len[i]-ans[i]);
    return 0;
}