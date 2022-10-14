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

constexpr int N = 2e5 + 5;
constexpr int T = 512;
constexpr int M = N / T + 1;

vi adj[N];
int dp[N][max(T, M)];
int tmp[M];

#define max kaejfuikjbc
__attribute__((always_inline)) int max(int a, int b) {return a > b ? a : b;}

void dfs1(int u, int p = -1) {
    for(int v: adj[u]) if(v != p) {
        dfs1(v, u);
        rep(i, T) dp[u][i] += max(dp[v][i] - i, 1);
    }
}

int dfs2(int u, int p = -1) {
    int sz = 1;
    for(int v: adj[u]) if(v != p) {
        int csz = dfs2(v, u);
        memset(tmp, 0, sizeof(tmp));
        rep(i, min(sz, M)) tmp[i] = dp[u][i] + 1;
        rep(i, min(sz, M)) {
            rep(j, min(csz, M - i - 1)) {
                tmp[i + j + 1] = max(tmp[i + j + 1], dp[u][i] + dp[v][j]);
            }
        }
        memmove(dp[u], tmp, min(sz += csz, M) * sizeof(int));
    }
    return sz;
}

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int q; cin >> q;
    vi ans(q);
    vector<pii> queries(q);
    rep(i, q) {
        int v, k; cin >> v >> k;
        queries[i] = {--v, k};
    }
    memset(dp, 0, sizeof(dp));
    dfs1(0);
    rep(i, q) {
        auto& [v, k] = queries[i];
        if(k < T) ans[i] = dp[v][k];
    }
    memset(dp, 0, sizeof(dp));
    dfs2(0);
    rep(i, q) {
        auto& [v, k] = queries[i];
        if(k >= T) rep(j, M) ans[i] = max(ans[i], dp[v][j] - j * k);
    }
    rep(i, q) cout << ans[i] << endl;
}