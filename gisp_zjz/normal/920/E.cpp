#include<bits/stdc++.h>
#define maxn 200050
#define maxm 5020
#define x first
#define y second

using namespace std;
typedef pair<int,int> pi;

pi a[maxn];
bool f[maxm][maxm],g[maxn],flag;
int n,m,r,cnt,ans[maxn],pre[maxn],b[maxn],d[maxn];
bool vis[maxn];
set <pi> s;

int dfs(int x)
{
    vis[x]=true;
    int tmp=1;
    for (int i=1;i<=m;i++)
        if (f[x][i]&&!vis[i]) tmp+=dfs(i);
    return tmp;
}

int main()
{
    scanf("%d%d",&n,&m);
    if (n<5000){
        memset(f,true,sizeof(f));
        while (m--)
        {
            int u,v;scanf("%d%d",&u,&v);
            f[u][v]=f[v][u]=0;
        }
        m=n;
        memset(vis,0,sizeof(vis)); cnt=0;
        for (int i=1;i<=n;i++) if (!vis[i]) ans[cnt++]=dfs(i);
    }
    else{
        memset(d,0,sizeof(d));
        while (m--)
        {
            int u,v;scanf("%d%d",&u,&v);
            if (u>v) swap(u,v);
            s.insert({u,v});
            d[u]++;d[v]++;
        }
        memset(g,true,sizeof(g));
        for (int i=1;i<=n;i++) if (d[i]>n/2) g[i]=false;
        r=0;
        for (int i=1;i<=n;i++) if (!g[i]) b[++r]=i;
        for (int i=1;i<=r;i++) for (int j=1;j<=r;j++) f[i][j]=(s.find({min(b[i],b[j]),max(b[i],b[j])})==s.end());
        //for (int i=1;i<=r;i++) {for (int j=1;j<=r;j++) printf("%d ",f[i][j]); printf("\n");}
        memset(vis,0,sizeof(vis)); cnt=1; ans[0]=n-r; m=r;
        for (int i=1;i<=r;i++)
        if (!vis[i]){
            int v=b[i];
            flag=true;
            for (int j=1;j<=n&&flag;j++) if (g[j]&&s.find({min(v,j),max(v,j)})==s.end()) flag=false;
            if (!flag) ans[0]+=dfs(i);
        }
        for (int i=1;i<=r;i++) if (!vis[i]) ans[cnt++]=dfs(i);
    }
    sort(ans,ans+cnt);
    printf("%d\n",cnt);
    for (int i=0;i<cnt;i++) printf("%d ",ans[i]);printf("\n");
}