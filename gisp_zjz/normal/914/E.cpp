#include<bits/stdc++.h>
#define maxn 500020

using namespace std;
typedef long long ll;

vector <ll> h[maxn];
ll a[maxn],b[maxn],n,m,k,sz[maxn],pre[maxn];
bool f[maxn];
ll ans[maxn],cnt[1<<20];

char s[maxn];

void dfs(ll u,ll fa)
{
    sz[u]=1; pre[u]=fa;
    for (ll i=0;i<h[u].size();i++)
    {
        ll v=h[u][i];
        if (v!=fa&&f[v]) dfs(v,u),sz[u]+=sz[v];
    }
}

ll getroot(ll x)
{
    dfs(x,0); m=sz[x];
    ll j=0;
    for (ll i=0;i<h[x].size();i++)
    {
        ll v=h[x][i];
        if (pre[x]!=v&&f[v]&&sz[v]>sz[j]) j=v;
    }
    while (sz[j]>m/2) {
        x=j; j=0;
        for (ll i=0;i<h[x].size();i++)
        {
            ll v=h[x][i];
            if (pre[x]!=v&&f[v]&&sz[v]>sz[j]) j=v;
        }
    }
    dfs(x,0);
    return x;
}

void dfs1(ll x,ll y,ll z)
{
    y^=b[x]; cnt[y]+=z;
    for (ll i=0;i<h[x].size();i++)
    {
        ll v=h[x][i];
        if (f[v]&&pre[x]!=v) dfs1(v,y,z);
    }
}

ll cal(ll x,ll y)
{
    ll sum=0;
    y^=b[x]; sum+=cnt[y];
    for (ll i=0;i<20;i++) sum+=cnt[y^(1<<i)];
    for (ll i=0;i<h[x].size();i++)
    {
        ll v=h[x][i];
        if (f[v]&&pre[x]!=v) sum+=cal(v,y);
    }
    ans[x]+=sum;
    return sum;
}

void solve(ll x)
{
    ll root=getroot(x);
    ll sum=0;
    dfs1(root,0,1);
    for (ll i=0;i<h[root].size();i++)
    {
        ll v=h[root][i];
        if (!f[v]) continue;
        dfs1(v,b[root],-1);
        sum+=cal(v,0);
        dfs1(v,b[root],1);
    }
    sum+=cnt[0];
    for (ll i=0;i<20;i++) sum+=cnt[1<<i];
    ans[root]+=(sum+1)/2;
    dfs1(root,0,-1);
    f[root]=false;
    for (ll i=0;i<h[root].size();i++)
    {
        ll v=h[root][i];
        if (!f[v]) continue;
        solve(v);
    }
}

int main()
{
    scanf("%I64d",&n);
    for (ll i=1;i<n;i++)
    {
        ll u,v;scanf("%I64d%I64d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    scanf("%s",s+1);
    for (ll i=1;i<=n;i++) b[i]=1<<(s[i]-'a');
    memset(f,true,sizeof(f));
    solve(1);
    for (ll i=1;i<=n;i++) printf("%I64d ",ans[i]); printf("\n");
    return 0;
}