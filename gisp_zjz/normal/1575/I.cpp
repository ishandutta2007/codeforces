#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
bool hs[maxn];
int n,q,pre[maxn],fa[maxn][17],dep[maxn],cc,id[maxn],sz[maxn],L[maxn],R[maxn],hson[maxn];
ll a[maxn],b[maxn];
void upd(int x,ll val){
    while (x<maxn) b[x]+=val,x+=x&(-x);
}
void modify(int l,int r,ll val){
    upd(l,val);
    upd(r+1,-val);
}
ll qry(int x){
    ll ret=0; while (x) ret+=b[x],x-=x&(-x); return ret;
}
ll f(ll x,ll y){
    return max(abs(x+y),abs(x-y));
}
vector<int> G[maxn];
int lca(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int dif=dep[u]-dep[v];
    for (int i=16;i>=0;i--) if ((dif>>i)&1) u=fa[u][i];
    if (u==v) return u;
    for (int i=16;i>=0;i--) if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int dfs(int u,int Fa){
    id[u]=L[u]=++cc;
    fa[u][0]=Fa; dep[u]=dep[Fa]+1;
    for (auto v:G[u]){
        if (v==Fa) continue;
        dfs(v,u);
        if (sz[v]>sz[hson[u]]) hson[u]=v;
    }
    hs[hson[u]]=1;
    R[u]=cc;
    sz[u]=R[u]-L[u]+1;
}
void dfs2(int u,int Fa){
    if (!hs[u]){
        pre[u]=u;
    } else {
        modify(L[u],R[u],f(a[u],a[Fa]));
        pre[u]=pre[Fa];
    }
    for (auto v:G[u]){
        if (v==Fa) continue;
        dfs2(v,u);
    }
}
ll work(int u){
    ll ret=qry(id[u]);
    while (pre[u]){
        int v=pre[u];
        u=fa[v][0];
        ret+=f(a[u],a[v]);
    }
    return ret;
}
int main(){
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1,0); dfs2(1,0);
    for (int i=1;i<=16;i++)
        for (int j=1;j<=n;j++)
            fa[j][i]=fa[fa[j][i-1]][i-1];
    while (q--){
        int op; cin >> op;
        if (op==1){
            int u; ll val; cin >> u >> val;
            if (hs[u]){
                int v=fa[u][0];
                modify(L[u],R[u],f(val,a[v])-f(a[u],a[v]));
            }
            if (hson[u]){
                int v=hson[u];
                modify(L[v],R[v],f(val,a[v])-f(a[u],a[v]));
            }
            a[u]=val;
        } else {
            int u,v; cin >> u >> v;
            int w=lca(u,v);
            printf("%lld\n",work(u)+work(v)-work(w)*2);
        }
    }
    return 0;
}