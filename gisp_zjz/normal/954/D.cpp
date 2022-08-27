#include<bits/stdc++.h>
#define maxn 1030

using namespace std;
vector<int> h[maxn];
bool vis[maxn],f[maxn][maxn];
int n,m,x[maxn],y[maxn],s,t,r,ans;
queue <int> q;

int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (int i=0;i<m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        f[u][v]=f[v][u]=true;
        h[u].push_back(v);h[v].push_back(u);
    }
    memset(x,-1,sizeof(x));
    memset(y,-1,sizeof(y));
    q.push(s); x[s]=0;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i];
            if (x[v]==-1) x[v]=x[u]+1,q.push(v);
        }
    }
    q.push(t); y[t]=0;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i];
            if (y[v]==-1) y[v]=y[u]+1,q.push(v);
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (x[i]==-1) x[i]=n+1;
        if (y[i]==-1) y[i]=n+1;
    }
    r=x[t];
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (!f[i][j]&&x[i]+y[j]+1>=r&&x[j]+y[i]+1>=r) ans++;
    cout << ans << endl;
}