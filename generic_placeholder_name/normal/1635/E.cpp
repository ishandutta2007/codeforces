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

constexpr int N = 2e5 + 5;
vi adj[N];
int n;
int c[N];
vector<pii> cond[2];

bool is_bipartite() {
    memset(c, -1, n * sizeof(int));
    queue<int> q;
    rep(i, n) if(!~c[i]) {
        c[i] = 0;
        q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto& v: adj[u]) {
                if(!~c[v]) {
                    c[v] = c[u] ^ 1;
                    q.push(v);
                }
                else if(c[v] == c[u]) return 0;
            }
        }
    }
    return 1;
}

int st[N];
int a[N];
int idx[N];

bool dfs(int u) {
    st[u] = 1;
    for(int v: adj[u]) {
        if(!st[v]) {
            if(dfs(v)) return 1;
        }
        else if(st[v] == 1) return 1;
    }
    st[u] = 2;
    return 0;
}

bool cyc() {
    rep(i, n) if(!st[i] && dfs(i)) return 1;
    return 0;
}

bool vis[N];
int ord[N];

void dfs2(int u) {
    static int t = 0;
    vis[u] = 1;
    for(int v: adj[u]) if(!vis[v]) dfs2(v);
    ord[t++] = u;
}

void topo() {
    rep(i, n) if(!vis[i]) dfs2(i);
    rep(i, n / 2) swap(ord[i], ord[n - i - 1]);
}

int32_t main() {
    fastio;
    int m; cin >> n >> m;
    rep(i, m) {
        int t, u, v; cin >> t >> u >> v; --t, --u, --v;
        cond[t].eb(u, v);
        adj[u].eb(v);
        adj[v].eb(u);
    }
    if(!is_bipartite()) return cout << "NO\n", 0;
    rep(i, n) adj[i].clear();
    rep(i, 2) for(auto& [u, v]: cond[i]) {
        if(c[u]) swap(u, v);
        if(i) swap(u, v);
        adj[u].eb(v);
    }
    if(cyc()) return cout << "NO\n", 0;
    cout << "YES\n";
    topo();
    for(int i = n - 1; ~i; i--) {
        int id = ord[i];
        a[id] = n;
        for(int j: adj[id]) a[id] = min(a[id], a[j] - 1);
    }
    iota(idx, idx + n, 0);
    sort(idx, idx + n, [&](int i, int j) {return a[i] < a[j];});
    rep(i, n) a[idx[i]] = i;
    rep(i, n) cout << (c[i] ? "R " : "L ") << a[i] << endl;
}