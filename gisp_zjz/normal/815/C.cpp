#include<bits/stdc++.h>
#define maxn 5020
#define inf 1000020000

using namespace std;
typedef long long ll;
ll f[maxn][maxn],g[maxn][maxn],n,a[maxn],b[maxn],k,sz[maxn];
ll m;
vector <int> h[maxn];

void dfs(int x)
{
    sz[x]=1;
    for (int i=0;i<=n;i++) f[x][i]=g[x][i]=inf;
    f[x][1]=a[x];f[x][0]=0;g[x][1]=a[x]-b[x];
    for (int i=0;i<h[x].size();i++)
    {
        int v=h[x][i]; dfs(v);
        for (int j=sz[x];j>=0;j--)
            for (int k=0;k<=sz[v];k++)
                f[x][j+k]=min(f[x][j+k],f[x][j]+f[v][k]),
                g[x][j+k]=min(g[x][j+k],g[x][j]+min(f[v][k],g[v][k]));
        sz[x]+=sz[v];
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&a[1],&b[1]);
    for (int i=2;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&k);
        h[k].push_back(i);
    }
    dfs(1); k=0;
    for (int i=1;i<=n;i++) if (min(f[1][i],g[1][i])<=m) k=i;
    cout << k << endl;
}