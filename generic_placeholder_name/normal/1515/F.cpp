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

struct dsu {
    vi d;
    vll v;
    vvi s;

    dsu(const vll& a, const vvi& adj): d(a.size(), -1), v(a), s(adj) {}
    int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}
    ll val(int x) {return v[find(x)];}
    void join(int x, int y, int k) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y]; d[y] = x;
        v[x] += v[y] - k; v[y] = 0;
        if(s[x].size() < s[y].size()) s[x].swap(s[y]);
        s[x].insert(s[x].end(), all(s[y])); vi{}.swap(s[y]);
    }
};

int32_t main() {
    fastio;
    int n, m, x; cin >> n >> m >> x;
    vll a(n); rep(i, n) cin >> a[i];
    vvi adj(n);
    vector<pii> edge(m);
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].eb(i);
        adj[v].eb(i);
        edge[i] = {u, v};
    }
    dsu d(a, adj);
    priority_queue<pair<ll, int>> s;
    rep(i, n) s.emplace(a[i], i);
    vi ans;
    while(ans.size() < n - 1) {
        auto [w, i] = s.top(); s.pop();
        if(w != d.val(i) || i != d.find(i)) continue;
        while(1) {
            if(d.s[i].empty()) return puts("NO"), 0;
            int id = d.s[i].back(); d.s[i].pop_back();
            auto& [u, v] = edge[id];
            if(d.find(u) != d.find(v) && d.val(u) + d.val(v) >= x) {
                ans.pb(id);
                d.join(u, v, x);
                s.emplace(d.val(u), d.find(u));
                break;
            }
        }
    }
    cout << "YES\n";
    for(auto& i: ans) cout << i + 1 << endl;
}