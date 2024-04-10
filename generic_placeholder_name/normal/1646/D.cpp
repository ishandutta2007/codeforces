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

#define int long long

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
vi adj[N];
int ans[N];
pii dp[N][2]; //why the additional restriction? it's incomprehensible

pii operator + (const pii& a, const pii& b) {
    return mp(a.fi + b.fi, a.se + b.se);
}

void dfs1(int u, int p = 0) {
    dp[u][1] = {1, 0};
    dp[u][0] = {0, -1};
    for(int v: adj[u]) if(v != p) {
        dfs1(v, u);
        dp[u][1] = dp[u][1] + dp[v][0] + mp(0, -1);
        dp[u][0] = dp[u][0] + max(dp[v][0], dp[v][1] + mp(0, -1));
    }
}

void dfs2(int u, int p = 0, bool on = 1) {
    if(on && dp[u][0] >= dp[u][1]) on = 0;
    if(on) ans[u] += ans[p];
    else ans[u] = 1;
    for(int v: adj[u]) if(v != p) {
        dfs2(v, u, !on);
        if(on) ans[u] += ans[v];
    }
}

int32_t main() {
    fastio;
    int n; cin >> n;
    if(n == 2) return puts("2 2\n1 1"), 0;
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1);
    dfs2(1);
    auto res = max(dp[1][0], dp[1][1]);
    //assert(-res.se == accumulate(ans + 1, ans + n + 1, 0));
    cout << res.fi << ' ' << -res.se << endl;
    rep1(i, n) cout << ans[i] << ' ';
}