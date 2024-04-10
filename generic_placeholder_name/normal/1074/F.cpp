#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//oops
//i am slow as fuck
//also full of bugs

constexpr int N=2e5+1, M=18;
int lvl[N];
int par[N][M+1];
vi adj[N];

void dfs_lca(int u, int p) {
    par[u][0]=p;
    rep1(i, M) par[u][i]=par[par[u][i-1]][i-1];
    if(p!=u) lvl[u]=lvl[p]+1;
    for(int v: adj[u]) if(v!=p) dfs_lca(v, u);
}

int lca(int u, int v) {
    if(lvl[u]<lvl[v]) swap(u, v);
    for(int i=M; ~i; i--) {
        if(lvl[u]-(1<<i)>=lvl[v]) u=par[u][i];
    }
    if(u==v) return u;
    for(int i=M; ~i; i--) {
        if(par[u][i]!=par[v][i]) {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}

int anc(int u, int dep) {
    for(int i=M; ~i; i--) {
        if(lvl[u]-(1<<i)>=dep) u=par[u][i];
    }
    return u;
}

int tin[N], tout[N];

void dfs_euler(int u, int p) {
    static int t=0;
    tin[u]=t++;
    for(int v: adj[u]) if(v!=p) dfs_euler(v, u);
    tout[u]=t-1;
}

array<int, 4*N+4> lz, mn, cnt;

inline void push(int v) {
    if(!lz[v]) return;
    const int lc=2*v, rc=2*v+1;
    mn[lc]+=lz[v];
    mn[rc]+=lz[v];
    lz[lc]+=lz[v];
    lz[rc]+=lz[v];
    lz[v]=0;
}

inline void pull(int v) {
    const int lc=2*v, rc=2*v+1;
    if(mn[lc]<mn[rc]) {
        mn[v]=mn[lc];
        cnt[v]=cnt[lc];
    }
    else if(mn[rc]<mn[lc]) {
        mn[v]=mn[rc];
        cnt[v]=cnt[rc];
    }
    else {
        mn[v]=mn[lc];
        cnt[v]=cnt[lc]+cnt[rc];
    }
}

void bld(int v=1, int l=0, int r=N-1) {
    cnt[v]=r-l+1;
    if(l!=r) {
        int m=(l+r)/2;
        bld(v*2, l, m);
        bld(v*2+1, m+1, r);
    }
}

void upd(int ql, int qr, int val, int v=1, int l=0, int r=N-1) {
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r) {
        mn[v]+=val;
        lz[v]+=val;
    }
    else {
        push(v);
        int m=(l+r)/2;
        upd(ql, qr, val, v*2, l, m);
        upd(ql, qr, val, v*2+1, m+1, r);
        pull(v);
    }
}

array<int, 2> get(int ql, int qr, int v=1, int l=0, int r=N-1) {
    if(ql>r||qr<l) return {INT_MAX, 0};
    if(ql<=l&&qr>=r) return {mn[v], cnt[v]};
    else {
        push(v);
        int m=(l+r)/2;
        auto lc=get(ql, qr, v*2, l, m);
        auto rc=get(ql, qr, v*2+1, m+1, r);
        if(lc[0]<rc[0]) return lc;
        else if(rc[0]<lc[0]) return rc;
        else return {lc[0], lc[1]+rc[1]};
    }
}

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    rep(i, n-1) {
        int u, v; cin>>u>>v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs_lca(0, 0);
    dfs_euler(0, -1);
    bld();
    map<pii, bool> exist;
    while(q--) {
        int u, v; cin>>u>>v; --u, --v;
        if(u>v) swap(u, v);
        if(!exist[{u, v}]) {
            exist[{u, v}]=1;
            if(lvl[u]>lvl[v]) swap(u, v);
            int p=lca(u, v);
            if(p!=u) {
                upd(0, n-1, 1);
                upd(tin[u], tout[u], -1);
                upd(tin[v], tout[v], -1);
            }
            else {
                int x=anc(v, lvl[u]+1);
                upd(tin[x], tout[x], 1);
                upd(tin[v], tout[v], -1);
            }
        }
        else {
            exist[{u, v}]=0;
            if(lvl[u]>lvl[v]) swap(u, v);
            int p=lca(u, v);
            if(p!=u) {
                upd(0, n-1, -1);
                upd(tin[u], tout[u], 1);
                upd(tin[v], tout[v], 1);
            }
            else {
                int x=anc(v, lvl[u]+1);
                upd(tin[x], tout[x], -1);
                upd(tin[v], tout[v], 1);
            }
        }
        auto ans=get(0, n-1);
        if(ans[0]!=0) cout<<"0\n";
        else cout<<ans[1]<<endl;
    }
}