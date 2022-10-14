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
vi adj[N];
vector<pii> ans;
int T;

void dfs(int u, int t, int p = -1) {
    int c = adj[u].size() - !!~p;
    ans.eb(u, t);
    int now = t;
    for(int v: adj[u]) if(v != p) {
        if(now == T) {
            int nxt = t - 1 - c;
            ans.eb(u, now = nxt);
        }
        dfs(v, ++now, u);
        ans.eb(u, now);
        --c;
    }
    if(now >= t) ans.eb(u, t - 1);
}

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(_, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, n) T = max(T, (int)adj[i].size());
    dfs(0, 0);
    ans.pop_back();
    cout << ans.size() << endl;
    for(auto& [x, y]: ans) cout << x + 1 << ' ' << y << endl;
}