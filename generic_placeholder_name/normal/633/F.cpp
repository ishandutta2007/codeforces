#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 1e5 + 5;

struct Data {
    ll f, s, t;
    int w;
    Data(int w = 0): f(w), s(0), t(0), w(w) {}
    void insert(ll x) {
        if(f < x) t = s, s = f, f = x;
        else if(s < x) t = s, s = x;
        else if(t < x) t = x;
    }
    ll query_end(ll x) {return f == x ? s : f;}
    ll query(ll x) {return max(query_end(x), (f == x ? s + t : f + (s == x ? t : s)) - w);}
    ll query() {return f + max(0LL, s - w);}
} dp[N];

struct Data2 {
    ll f, s;
    Data2(): f(0), s(0) {}
    void insert(ll x) {
        if(f < x) s = f, f = x;
        else if(s < x) s = x;
    }
    ll query(ll x) {return f == x ? s : f;}
} mx[N];

int w[N];
vi adj[N];
ll ans;

void dfs1(int u, int p = -1) {
    dp[u] = Data(w[u]);
    for(int v: adj[u]) if(v != p) {
        dfs1(v, u);
        mx[u].insert(max(dp[v].query(), mx[v].f));
        dp[u].insert(dp[v].f + w[u]);
    }
}

void dfs2(int u, int p = -1) {
    for(int v: adj[u]) if(v != p) {
        auto mx_v = max(dp[v].query(), mx[v].f);
        auto mx_out = max(mx[u].query(mx_v), dp[u].query(dp[v].f + w[u]));
        ans = max(ans, mx_out + mx_v);
        dp[v].insert(dp[u].query_end(dp[v].f + w[u]) + w[v]);
        mx[v].insert(mx_out);
        dfs2(v, u);
    }
}

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) cin >> w[i];
    rep(_, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(0);
    dfs2(0);
    cout << ans << endl;
}