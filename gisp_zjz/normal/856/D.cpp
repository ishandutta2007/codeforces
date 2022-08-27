#include<bits/stdc++.h>
#define maxn 500050

using namespace std;
struct edge{
    int x,y,z;
};
vector <int> h[maxn];
vector <edge> a[maxn];
int pre[maxn][20],l[maxn],r[maxn],n,k,uv,u,v,w,ans[maxn],sum[maxn],b[maxn],dep[maxn],p;

void dfs0(int u)
{
    l[u]=++p;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        dep[v]=dep[u]+1;dfs0(v);
    }
    r[u]=p;
}

void add_(int x,int y)
{
    while (x<maxn) b[x]+=y,x+=x&(-x);
}

int qry(int x)
{
    int rt=0; while (x) rt+=b[x],x-=x&(-x); return rt;
}

int pp(int u,int v)
{
    for (int i=19;i>=0;i--) if (v&(1<<i)) u=pre[u][i];
    return u;
}

int lca(int u,int v)
{
    if (dep[u]<dep[v]) swap(u,v);
    u=pp(u,dep[u]-dep[v]);
    if (u==v) return u;
    for (int i=19;i>=0;i--) if (pre[u][i]!=pre[v][i]) u=pre[u][i],v=pre[v][i];
    return pre[u][0];
}

int dfs(int u)
{
    for (int i=0;i<h[u].size();i++) dfs(h[u][i]),sum[u]+=ans[h[u][i]];
    ans[u]=sum[u];
    for (int i=0;i<a[u].size();i++)
    {
        edge e=a[u][i];
        ans[u]=max(ans[u],qry(l[e.x])+qry(l[e.y])+sum[u]+e.z);
    }
    add_(l[u],sum[u]-ans[u]); add_(r[u]+1,ans[u]-sum[u]);
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=2;i<=n;i++) {scanf("%d",&pre[i][0]);h[pre[i][0]].push_back(i);}
    for (int i=1;i<20;i++)
        for (int j=1;j<=n;j++)
            pre[j][i]=pre[pre[j][i-1]][i-1];
    dfs0(1);
    for (int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        uv=lca(u,v);
        a[uv].push_back({u,v,w});
    }
    dfs(1); cout << ans[1] << endl;
    return 0;
}