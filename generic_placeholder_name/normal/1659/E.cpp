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

struct dsu {
    vi d;
    dsu(int n) : d(n, -1) {}
    int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}
    void join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y]; d[y] = x;
    }
    bool is_joined(int x, int y) {
        return find(x) == find(y);
    }
};

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w;
        edges.eb(--u, --v, w);
    }
    vector<dsu> zero(30, n), one(30, n);
    rep(j, 30) {
        for(auto& [u, v, w]: edges) if(w >> j & 1) {
            zero[j].join(u, v);
        }
    }
    vb even(n);
    rep1(j, 29) {
        for(auto& [u, v, w]: edges) if((w >> j & 1)) {
            one[j].join(u, v);
        }
        vb vis(n);
        for(auto& [u, v, w]: edges) if(!(w & 1)) {
            vis[one[j].find(u)] = 1;
            vis[one[j].find(v)] = 1;
        }
        rep(i, n) if(vis[one[j].find(i)]) even[i] = 1;
    }
    auto check = [&](int u, int v) -> int {
        rep(j, 30) if(zero[j].is_joined(u, v)) return 0;
        if(even[u]) return 1;
        rep1(j, 29) if(one[j].is_joined(u, v)) return 1;
        return 2;
    };
    int q; cin >> q;
    while(q--) {
        int u, v; cin >> u >> v; --u, --v;
        cout << check(u, v) << endl;
    }
}