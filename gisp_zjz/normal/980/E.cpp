#include<bits/stdc++.h>
#define maxn 1048576

using namespace std;
int a[maxn],l[maxn],r[maxn],n,k,p,pre[maxn],cnt,dep[maxn],s,b[maxn];
bool f[maxn];
vector <int> h[maxn];

void dfs(int fa,int u)
{
    pre[u]=fa;
    l[u]=++cnt;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(u,v);
    }
    r[u]=cnt;
}

void update_(int x,int y)
{
    while (x<maxn) b[x]+=y,x+=x&(-x);
}

int qry(int x)
{
    int rt=0;
    while (x) rt+=b[x],x-=x&(-x);
    return rt;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    dfs(0,n); f[n]=true; s=n-k-1;
    for (int i=n-1;i>=1;i--){
        if (dep[i]-qry(l[i])>s) continue;
        int t=i;
        while (!f[t]){
            f[t]=true; update_(l[t],1); update_(r[t]+1,-1);
            t=pre[t]; s--;
        }
    }
    for (int i=1;i<=n;i++) if (!f[i]) cout << i << ' '; cout <<endl;
    return 0;
}