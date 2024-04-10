#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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
vector<pii> adj[N];
int low[N], disc[N];
ll dist[N], f[N];
int comp[N];
ll g[N];
stack<int> st;
bool in[N];

void dfs(int u) {
    static int t = 0;
    static int k = 0;
    low[u] = disc[u] = ++t;
    st.push(u); in[u] = 1;
    for(auto& [v, w]: adj[u]) {
        if(!disc[v]) {
            dist[v] = dist[u] + w;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in[v]) {
            low[u] = min(low[u], low[v]);
            f[u] = gcd(f[u], dist[u] - dist[v] + w);
        }
    }
    if(low[u] == disc[u]) {
        k++;
        while(st.top() != u) {
            int v = st.top(); st.pop();
            in[v] = 0;
            comp[v] = k;
            g[k] = gcd(g[k], f[v]);
        }
        st.pop();
        in[u] = 0;
        comp[u] = k;
        g[k] = gcd(g[k], f[u]);
    }
}


int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w;
        adj[--u].eb(--v, w);
    }
    rep(i, n) if(!disc[i]) dfs(i);
    int q; cin >> q;
    while(q--) {
        int v, s, t; cin >> v >> s >> t; --v;
        if(!s) puts("YES");
        else if(!g[comp[v]]) puts("NO");
        else puts(s % gcd(g[comp[v]], (ll)t) ? "NO" : "YES");
    }
}