#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int dep[maxn],Fa[maxn],n,m,x[maxn],y[maxn],pre[maxn],ans[maxn];
vi G[maxn];
vector<pi> a;
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    Fa[u]=fa;
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u);
    }
}
void _flip(int u,int v){
    if (u>v) swap(u,v);
    for (int i=1;i<=m;i++)
        if (x[i]==u&&y[i]==v) ans[i]=1;
}
void work(int u,int v){
    dfs(1,0);
    if (dep[u]>dep[v]) _flip(u,Fa[u]); else _flip(v,Fa[v]);
}
int ffind(int x){
    if (pre[x]==x) return x;
    return pre[x]=ffind(pre[x]);
}
void solve(){  
    cin >> n >> m; a.clear();
    for (int i=1;i<=n;i++) pre[i]=i,G[i].clear();
    for (int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        if (u>v) swap(u,v);
        x[i]=u; y[i]=v;
        if (ffind(u)!=ffind(v)){
            pre[ffind(v)]=ffind(u);
            G[u].pb(v); G[v].pb(u);
            ans[i]=0;
        } else {
            ans[i]=1;
            a.pb((pi){u,v});
        }
    }
    sort(a.begin(),a.end());
    if (a.size()==3){
        if (a[0].F==a[1].F&&a[0].S==a[2].F&&a[1].S==a[2].S){
            for (int i=1;i<=m;i++) if (ans[i]){
                ans[i]=0;
                work(x[i],y[i]);
                break;
            }
        }
    }
    for (int i=1;i<=m;i++) printf("%d",ans[i]); puts("");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}