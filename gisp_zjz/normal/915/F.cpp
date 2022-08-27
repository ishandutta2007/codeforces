#include<bits/stdc++.h>
#define maxn 1000020
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
pi a[maxn];
vector<ll> h[maxn];
ll pre[maxn],b[maxn],d[maxn];
ll p,q,s,r,n,sz[maxn];

void sub_union(int u,int v)
{
    if (d[u]>d[v]) pre[v]=u,sz[u]+=sz[v];
    else if (d[v]>d[u]) pre[u]=v,sz[v]+=sz[u];
    else pre[v]=u,d[u]++,sz[u]+=sz[v];
}

int ffind(int x)
{
    if (x==pre[x]) return x;
    pre[x]=ffind(pre[x]);
    return pre[x];
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].y=i;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) b[a[i].y]=i;
    for (int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        u=b[u]; v=b[v];
        h[u].push_back(v);
        h[v].push_back(u);
    }
    for (int i=1;i<=n;i++) pre[i]=i,d[i]=sz[i]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<h[i].size();j++)
        {
            int t=h[i][j];
            if (t>i) continue;
            int u=ffind(t),v=ffind(i);
            q-=sz[u]*(sz[u]+1)*a[i].x/2;
            sub_union(u,v);
        }
        r=ffind(i);
        q+=sz[r]*(sz[r]+1)*a[i].x/2;
    }
    for (int i=1;i<=n;i++) pre[i]=i,d[i]=sz[i]=1;
    for (int i=n;i;i--)
    {
        for (int j=0;j<h[i].size();j++)
        {
            int t=h[i][j];
            if (t<i) continue;
            int u=ffind(t),v=ffind(i);
            p-=sz[u]*(sz[u]+1)*a[i].x/2;
            sub_union(u,v);
        }
        r=ffind(i);
        p+=sz[r]*(sz[r]+1)*a[i].x/2;
    }
    cout << q-p << endl;
}