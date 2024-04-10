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

int n;

int to[N << 1], nxt[N << 1], lst[N];

int edges;
void add_edge(int u, int v) {
    nxt[++edges] = lst[u];
    to[edges] = v;
    lst[u] = edges;
}

int tin[N];
int sz[N];
int dep[N];
int f[N];

void dfs(int u, int p, int x) {
    static int t = 0;
    tin[u] = ++t;
    f[u] = x; sz[u] = 1;
    for(int id = lst[u]; id; id = nxt[id]) {
        int v = to[id];
        if(v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u, x);
            sz[u] += sz[v];
        }
    }
}

bool anc(int u, int v) {
    if(tin[u] > tin[v]) swap(u, v);
    return tin[u] + sz[u] > tin[v];
}

int fl, fr, vl, vr;
bool good;

void add_vertex(int v) {
    if(!good) return;
    if(!~fl) fl = f[v], vl = v;
    else if(fl == f[v]) good &= anc(vl, v), vl = dep[vl] < dep[v] ? v : vl;
    else if(!~fr) fr = f[v], vr = v;
    else if(fr == f[v]) good &= anc(vr, v), vr = dep[vr] < dep[v] ? v : vr;
    else good = 0;
}

ll ans[N];

ll get_paths() {
    if(!good) return 0;
    else if(!~fr) return sz[vl] * 1LL * (n - sz[fl]);
    else return sz[vl] * 1LL * sz[vr];
}

void reset() {
    edges = 0;
    memset(lst, 0, n * sizeof(int));
    fl = fr = -1;
    good = 1;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        reset();
        cin >> n;
        rep(_, n - 1) {
            int u, v; cin >> u >> v;
            add_edge(u, v);
            add_edge(v, u);
        }
        ans[0] = n * 1LL * (n - 1) / 2;
        ans[1] = 0;
        int s = 1;
        for(int id = lst[0]; id; id = nxt[id]) {
            int v = to[id];
            dep[v] = 1;
            dfs(v, 0, v);
            ans[1] += s * 1LL * sz[v];
            s += sz[v];
        }
        rep1(i, n - 1) {
            add_vertex(i);
            ans[i + 1] = get_paths();
        }
        rep(i, n) ans[i] -= ans[i + 1];
        rep(i, n + 1) cout << ans[i] << ' '; cout << endl;
    }
}