#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 1e5 + 5;
constexpr int M = (1 << 18) + 1;
constexpr ll INF = 1e18;

int n;
vi adj[N];
int sz[N], dep[N], par[N];
int heavy[N], nxt[N];
int tin[N];

void dfs1(int u, int p = -1) {
    sz[u] = 1;
    for(int v: adj[u]) if(v != p) {
        par[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
        if(!~heavy[u] || sz[v] > sz[heavy[u]]) heavy[u] = v;
    }
}

void dfs2(int u, int p = -1) {
    static int t = 0;
    tin[u] = t++;
    if(~heavy[u]) {
        nxt[heavy[u]] = nxt[u];
        dfs2(heavy[u], u);
    }
    for(int v: adj[u]) if(v != p && v != heavy[u]) {
        nxt[v] = v;
        dfs2(v, u);
    }
}

vector<pair<ll, int>> val[N];
int loc[N];
ll mn[M], lz[M];
int idx[M];

void push(int v) {
    if(!lz[v]) return;
    mn[v * 2] += lz[v];
    lz[v * 2] += lz[v];
    mn[v * 2 + 1] += lz[v];
    lz[v * 2 + 1] += lz[v];
    lz[v] = 0;
}

void pull(int v) {
    if(mn[v * 2] < mn[v * 2 + 1]) mn[v] = mn[v * 2], idx[v] = idx[v * 2];
    else mn[v] = mn[v * 2 + 1], idx[v] = idx[v * 2 + 1];
}

void bld(int v = 1, int l = 0, int r = n - 1) {
    if(l == r) {assert(!val[l].empty()); tie(mn[v], idx[v]) = val[l].back();}
    else {
        int m = (l + r) / 2;
        bld(v * 2, l, m);
        bld(v * 2 + 1, m + 1, r);
        pull(v);
    }
}

void upd(int ql, int qr, ll val, int v = 1, int l = 0, int r = n - 1) {
    if(ql > r || qr < l) return;
    if(ql <= l && qr >= r) {
        mn[v] += val;
        lz[v] += val;
    }
    else {
        push(v);
        int m = (l + r) / 2;
        upd(ql, qr, val, v * 2, l, m);
        upd(ql, qr, val, v * 2 + 1, m + 1, r);
        pull(v);
    }
}

pair<ll, int> query(int ql, int qr, int v = 1, int l = 0, int r = n - 1) {
    if(ql > r || qr < l) return mp(INF, -1);
    if(ql <= l && qr >= r) return mp(mn[v], idx[v]);
    else {
        push(v);
        int m = (l + r) / 2;
        return min(query(ql, qr, v * 2, l, m), query(ql, qr, v * 2 + 1, m + 1, r));
    }
}

void pop(int pos, int v = 1, int l = 0, int r = n - 1) {
    if(l == r) {
        val[l].pop_back();
        tie(mn[v], idx[v]) = mp(val[l].back().fi + lz[v], val[l].back().se);
    }
    else {
        push(v);
        int m = (l + r) / 2;
        if(pos <= m) pop(pos, v * 2, l, m);
        else pop(pos, v * 2 + 1, m + 1, r);
        pull(v);
    }
}

pair<ll, int> query_edges(int u, int v) {
    pair<ll, int> ans = {INF, -1};
    while(nxt[u] != nxt[v]) {
        if(dep[nxt[u]] > dep[nxt[v]]) swap(u, v);
        ans = min(ans, query(tin[nxt[v]], tin[v]));
        v = par[nxt[v]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ans = min(ans, query(tin[u], tin[v]));
    return ans;
}

int32_t main() {
    fastio;
    int m, q; cin >> n >> m >> q;
    rep(_, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(heavy, -1, sizeof(heavy));
    dfs1(0);
    dfs2(0);
    rep(i, n) val[i].eb(INF, -1);
    rep(i, m) {
        int v; cin >> v; --v;
        val[tin[v]].eb(i + 1, i);
        loc[i] = v;
    }
    rep(i, n) sort(rall(val[i]));
    bld();
    vi ans;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int u, v, k; cin >> u >> v >> k; --u, --v;
            rep(_, k) {
                auto p = query_edges(u, v);
                if(p.fi >= INF) break;
                else {
                    ans.pb(p.se);
                    pop(tin[loc[p.se]]);
                }
            }
            cout << ans.size() << ' ';
            for(int x: ans) cout << x + 1 << ' ';
            cout << endl;
            ans.clear();
        }
        else {
            int v, k; cin >> v >> k; --v;
            upd(tin[v], tin[v] + sz[v] - 1, k);
        }
    }
}