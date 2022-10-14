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
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 2005;
vi G[N], g[N], adj[N];
int low[N], disc[N], cmp[N];
int w[N], dp[N];

void dfs(int u, int p = -1) {
    static int t = 0;
    low[u] = disc[u] = ++t;
    for(int v: g[u]) if(v != p) {
        if(disc[v]) low[u] = min(low[u], disc[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] <= disc[u]) G[u].pb(v), G[v].pb(u);
        }
    }
}

void dfs2(int u, int c) {
    if(cmp[u]) return;
    cmp[u] = c;
    for(int v: G[u]) dfs2(v, c);
}

ll dfs3(int u, int p = -1, int d = 0) {
    ll ans = d * w[u];
    dp[u] = w[u];
    for(int v: adj[u]) if(v != p) {
        ans += dfs3(v, u, d + w[u]);
        dp[u] += dp[v];
    }
    return ans;
}

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1);
    int sz = 0;
    rep1(i, n) if(!cmp[i]) dfs2(i, ++sz);
    rep1(i, n) for(int j: g[i]) if(cmp[i] != cmp[j]) {
        adj[cmp[i]].pb(cmp[j]);
    }
    rep1(i, n) w[cmp[i]]++;
    ll a = 0, b = 0;
    rep1(i, sz) {
        a += w[i] * 1LL * w[i];
        ll z = dfs3(i);
        bitset<N> vis;
        vis[0] = 1;
        int tot = 0;
        for(int v: adj[i]) {
            vis |= (vis << dp[v]);
            tot += dp[v];
        }
        for(int x = vis._Find_first(); x < N; x = vis._Find_next(x)) {
            int y = tot - x;
            b = max(b, z + (n - w[i] - x) * x);
        }
    }
    cout << a + b << endl;
}