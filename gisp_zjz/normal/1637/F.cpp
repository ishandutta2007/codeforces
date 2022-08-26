#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll inf=1e18;
int n,rt,cnt[maxn];
vector<int> G[maxn];
ll f[maxn],g[maxn],a[maxn],s0,s1;
void dfs1(int u,int fa){
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs1(v,u); cnt[u]++;
        a[u]=max(a[u],a[v]);
    }
}
void dfs(int u,int fa){
    if (!cnt[u]){f[u]=0;g[u]=a[u];return;}
    ll best=inf; 
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u);
        best=min(best,f[v]-g[v]);
        f[u]+=g[v];
    }
    f[u]+=best;
    g[u]=f[u]+a[u];
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if (a[i]>a[rt]) rt=i;
    }
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v); G[v].pb(u);
    }
    dfs1(rt,0);
    dfs(rt,0);
    s0=s1=inf;
    ll ans=0;
    for (auto x:G[rt]){
        ans+=g[x];
        ll tmp=f[x]-g[x];
        if (tmp<s0) s1=s0,s0=tmp;
        else if (tmp<s1) s1=tmp;
    }
    if (cnt[rt]==1) ans=ans+a[rt]*2+s0;
    else ans=ans+a[rt]*2+s0+s1;
    cout << ans << endl;
    return 0;
}