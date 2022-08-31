#include<bits/stdc++.h>
#define maxn 200500
#define F first
#define S second

using namespace std;
typedef pair<int,int> pi;
int dp[maxn],pre[maxn][18],n,m,l[maxn],r[maxn],dep[maxn],cnt,a[maxn][18],ans[maxn],c[maxn],s[maxn];
vector <int> h[maxn],b[maxn];
vector <pi> g[maxn];

void dfs(int u)
{
    l[u]=cnt++;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        dfs(v);
        if (dep[dp[v]]<dep[dp[u]]) dp[u]=dp[v];
    }
    r[u]=cnt;
}

int pp(int x,int y)
{
    for (int i=17;i>=0;i--)
        if (y&(1<<i)) x=pre[x][i];
    return x;
}

int lca(int u,int v)
{
    if (dep[u]<dep[v]) swap(u,v);
    u=pp(u,dep[u]-dep[v]);
    if (u==v) return u;
    for (int i=17;i>=0;i--)
        if (pre[u][i]!=pre[v][i]) u=pre[u][i],v=pre[v][i];
    return pre[u][0];
}

void add_(int x) {while (x<maxn) c[x]++,x+=x&(-x);}
int qry(int x) {int rt=0; while (x) rt+=c[x],x-=x&(-x); return rt;}

void dfs2(int u)
{
    for (int i=0;i<g[u].size();i++) {
        pi tmp=g[u][i];
        s[tmp.S]=qry(r[tmp.F])-qry(l[tmp.F]);
    }
    for (int i=0;i<b[u].size();i++) add_(l[b[u][i]]+1);
    for (int i=0;i<h[u].size();i++) dfs2(h[u][i]);
    for (int i=0;i<g[u].size();i++) {
        pi tmp=g[u][i];
        if (s[tmp.S]<qry(r[tmp.F])-qry(l[tmp.F])) ans[tmp.S]--;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) dp[i]=i;
    for (int i=2;i<=n;i++) {
        scanf("%d",&m);
        pre[i][0]=m; dep[i]=dep[m]+1;
        h[m].push_back(i);
    }
    for (int i=1;i<18;i++) for (int j=1;j<=n;j++) pre[j][i]=pre[pre[j][i-1]][i-1];
    scanf("%d",&m);
    while (m--){
        int u,v,w;scanf("%d%d",&u,&v);
        b[u].push_back(v); b[v].push_back(u);
        w=lca(u,v);
        if (dep[dp[u]]>dep[w]) dp[u]=w;
        if (dep[dp[v]]>dep[w]) dp[v]=w;
    }
    dfs(1);
    for (int i=1;i<=n;i++) a[i][0]=dp[i];
    for (int i=1;i<18;i++) for (int j=1;j<=n;j++) a[j][i]=a[a[j][i-1]][i-1];
    scanf("%d",&m);
    for (int i=1;i<=m;i++) {
        int u,v,w; scanf("%d%d",&u,&v);
        if (dep[u]>dep[v]) swap(u,v);
        w=lca(u,v); ans[i]=(u==w)?1:2;
        for (int j=17;j>=0;j--) if (dep[a[u][j]]>dep[w]) ans[i]+=(1<<j),u=a[u][j];
        for (int j=17;j>=0;j--) if (dep[a[v][j]]>dep[w]) ans[i]+=(1<<j),v=a[v][j];
        if (dep[dp[u]]>dep[w]||dep[dp[v]]>dep[w]) {ans[i]=-1; continue;}
        if (u!=w) g[u].push_back({v,i});
    }
    dfs2(1);
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}