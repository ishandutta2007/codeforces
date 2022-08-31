#include<bits/stdc++.h>

using namespace std;
const int maxn=500030;
int pre[maxn][2],n,o,ans[maxn],s,t,m,c[maxn];
vector <int> h[maxn];
bool f[maxn][2],g,e[maxn],vis[maxn];

void dfs(int x,bool q)
{
    f[x][q]=true;
    for (int i=0;i<h[x].size();i++)
    {
        int y=h[x][i];
        if (!f[y][q^1]) pre[y][q^1]=x,dfs(y,q^1);
    }
}

void dfs1(int x)
{
    vis[x]=true;
    for (int i=0;i<h[x].size();i++)
    {
        int y=h[x][i];
        if (!vis[y]) dfs1(y);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d",&u);
        e[i]=(u==0);
        for (int j=0;j<u;j++)
        {
            scanf("%d",&v);
            h[i].push_back(v);
        }
    }
    scanf("%d",&s);
    memset(f,0,sizeof(f)); dfs(s,0);
    t=0; for (int i=1;i<=n;i++) if (e[i]&&f[i][1]) t=i;
    g=false;
    memset(vis,0,sizeof(vis)); dfs1(s);
    for (int i=1;i<=n;i++)
        for (int j=0;j<h[i].size();j++)
            if (vis[i]) c[h[i][j]]++;
    queue <int> p;
    for (int i=1;i<=n;i++) if (vis[i]&&(c[i]==0)) p.push(i);
    while (!p.empty()){
        int u=p.front(); p.pop(); vis[u]=false;
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i];
            if (!vis[v]) continue;
            c[v]--; if (c[v]==0) p.push(v);
        }
    }
    for (int i=1;i<=n;i++) if (vis[i]) g=true;
    if (!t) {if (g) puts("Draw"); else puts("Lose");return 0;}
    puts("Win"); o=0; g=1;
    while (t!=s||g){
        ans[o++]=t;
        t=pre[t][g];
        g^=1;
    }
    ans[o]=s;
    for (int i=o;i>=0;i--) printf("%d ",ans[i]); puts("");
    return 0;
}