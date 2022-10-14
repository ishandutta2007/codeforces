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

constexpr int N=5e5+1;
constexpr ll INF=1e18;
ll t[4*N+4], lz[4*N+4];
vector<pii> adj[N];
vector<array<int, 3>> queries[N];
bool is_leaf[N];
int tin[N], tout[N];
int path[N];
ll dist[N];
ll ans[N];

inline void push(int v) {
    if(!lz[v]) return;
    const int lc=v*2, rc=v*2+1;
    t[lc]+=lz[v];
    lz[lc]+=lz[v];
    t[rc]+=lz[v];
    lz[rc]+=lz[v];
    lz[v]=0;
}

inline void pull(int v) {
    const int lc=v*2, rc=v*2+1;
    t[v]=min(t[lc], t[rc]);
}

void bld(ll a[], int v=1, int l=0, int r=N-1) {
    if(l==r) t[v]=a[l];
    else {
        int m=(l+r)/2;
        bld(a, v*2, l, m);
        bld(a, v*2+1, m+1, r);
        pull(v);
    }
}

void upd(int ql, int qr, ll val, int v=1, int l=0, int r=N-1) {
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r) {
        t[v]+=val;
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

ll get(int ql, int qr, int v=1, int l=0, int r=N-1) {
    if(ql>r||qr<l) return INF;
    if(ql<=l&&qr>=r) return t[v];
    else {
        push(v);
        int m=(l+r)/2;
        return min(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
    }
}

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    rep1(i, n-1) {
        int p, w; cin>>p>>w;
        adj[--p].eb(i, w);
        path[i]=w;
    }
    rep(i, q) {
        int v, l, r; cin>>v>>l>>r; --v, --l, --r;
        queries[v].pb({l, r, i});
    }
    auto dfs_up = [&](int u) {
        auto dfs = [&](int u, const auto& _dfs) -> void {
            tin[u]=tout[u]=u;
            for(auto& [v, w]: adj[u]) {
                dist[v]=dist[u]+w;
                _dfs(v, _dfs);
                tout[u]=max(tout[u], tout[v]);
            }
            is_leaf[u]=(tin[u]==tout[u]);
        };
        dfs(u, dfs);
    };
    auto dfs_down = [&](int u) {
        auto dfs = [&](int u, const auto& _dfs) -> void {
            upd(0, n-1, path[u]);
            upd(tin[u], tout[u], -2LL*path[u]);
            for(auto& query: queries[u]) {
                ans[query[2]]=get(query[0], query[1]);
            }
            for(auto& [v, w]: adj[u]) {
                _dfs(v, _dfs);
            }
            upd(0, n-1, -path[u]);
            upd(tin[u], tout[u], 2LL*path[u]);
        };
        dfs(u, dfs);
    };
    dfs_up(0);
    rep(i, n) if(!is_leaf[i]) dist[i]=INF;
    bld(dist);
    dfs_down(0);
    rep(i, q) cout<<ans[i]<<endl;
}