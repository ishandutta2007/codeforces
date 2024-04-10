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
vector<tuple<int, int, int>> adj[N];
int color[N];
vector<tuple<int, int, int>> ans;

bool ok = 1;
void dfs(int u, int c) {
    if(~color[u]) {
        if(color[u] != c) ok = 0;
        return;
    }
    color[u] = c;
    for(auto& [v, _, w]: adj[u]) {
        if(!~w) continue;
        dfs(v, color[u] ^ w);
    }
}

void dfs2(int u, int p = -1) {
    for(auto& [v, w, _]: adj[u]) if(v != p && w != -2) {
        if(!~w) ans.eb(u, v, color[u] ^ color[v]);
        else ans.eb(u, v, w);
        dfs2(v, u);
    }
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        ok = 1;
        ans.clear();
        rep(i, n) adj[i].clear();
        memset(color, -1, n * sizeof(int));
        rep(_, n - 1) {
            int u, v, w; cin >> u >> v >> w; --u, --v;
            if(~w) {
                int par = __builtin_popcount(w) & 1;
                adj[u].eb(v, w, par);
                adj[v].eb(u, w, par);
            }
            else {
                adj[u].eb(v, -1, -1);
                adj[v].eb(u, -1, -1);
            }
        }
        rep(_, m) {
            int u, v, p; cin >> u >> v >> p; --u, --v;
            adj[u].eb(v, -2, p);
            adj[v].eb(u, -2, p);
        }
        rep(i, n) if(!~color[i]) dfs(i, 0);
        if(!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            dfs2(0);
            for(auto& [u, v, w]: ans) cout << u + 1 << ' ' << v + 1 << ' ' << w << endl;
        }
    }
}