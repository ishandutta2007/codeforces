#include<bits/stdc++.h>
#define N 503040
#define F first
#define S second
#define M 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,k,m,a[N],ans[N],sz[N],rt;
vector <int> h[N];
bool f[N];

void dfs(int u)
{
    sz[u]=1;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        dfs(v); sz[u]+=sz[v];
    }
}

void dfs2(int u)
{
    int p=0;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (sz[v]%2==0) p++,dfs2(v);
    }
    if (p<h[u].size()) ans[m++]=u;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (sz[v]%2==1) dfs2(v);
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int u;scanf("%d",&u);
        if (u) h[u].push_back(i); else rt=i;
    }
    if (n%2==0) {printf("NO\n");return 0;}
    printf("YES\n");
    dfs(rt);
    dfs2(rt);
    for (int i=0;i<m;i++) printf("%d\n",ans[i]);
    for (int i=0;i<m;i++) f[ans[i]]=1;
    for (int i=1;i<=n;i++) if (!f[i]) printf("%d\n",i);
    return 0;
}