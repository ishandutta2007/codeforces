#include<bits/stdc++.h>
#define maxn 505

using namespace std;
typedef pair<int,int> pi;
vector <int> h[maxn],g[maxn];
int n,m,c[maxn],d[maxn],k;
bool vis[maxn];
pi e[maxn];
queue <int> q;

bool check(int x)
{
    q.push(x); for (int i=1;i<=n;i++) c[i]=d[i];
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i];
            c[v]--;
            if (!c[v]&&v!=x) q.push(v);
        }
    }
    for (int i=1;i<=n;i++) if (c[i]) return false;
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        h[u].push_back(v); d[v]++;
    }
    for (int i=1;i<=n;i++) if (!d[i]) q.push(i);
    while (!q.empty())
    {
        int u=q.front(); q.pop(); vis[u]=true;
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i];
            d[v]--;
            if (!d[v]) q.push(v);
        }
    }
    for (int i=1;i<=n;i++) k+=d[i]; if (!k){cout << "YES" << endl;return 0;}
    for (int i=1;i<=n;i++) if (d[i]==1&&check(i)) {cout << "YES" << endl;return 0;}
    cout << "NO" << endl;
}