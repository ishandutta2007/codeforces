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

constexpr int N = 3e5 + 5;
vi adj[N];
int dep[N];
int mxd[N];

void add(int& f, int& s, int x) {
    if(x > f) s = f, f = x;
    else if(x > s) s = x;
}

int dfs(int u, int p = -1) {
    int f = dep[u], s = dep[u];
    for(int v: adj[u]) if(v != p) {
        dep[v] = dep[u] + 1;
        add(f, s, dfs(v, u));
    }
    mxd[s] = max(mxd[s], f + s - 2 * dep[u] + 1);
    return f;
}

void solve() {
    int n; cin >> n;
    rep(i, n) adj[i].clear();
    memset(mxd, 0, (n + 1) * sizeof(int));
    rep(_, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    for(int i = n - 2; ~i; i--) mxd[i] = max(mxd[i], mxd[i + 1]);
    for(int i = 1, p = 1; i <= n; i++) {
        while(mxd[p] && mxd[p] / 2 + i >= p) p++;
        cout << p - 1 << ' ';
    }
    cout << endl;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) solve();
}