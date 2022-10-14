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
    int ok;
    vi d;
    vb p;
    int time;

    struct op {
        int time;
        int x, y;
        int dx, dy;
        bool px, py;

        op(int time, int x, int y, int dx, int dy, bool px, bool py): time(time), x(x), y(y), dx(dx), dy(dy), px(px), py(py) {}
    };

    void apply(const op& o) {
        d[o.x] = o.dx, d[o.y] = o.dy;
        p[o.x] = o.px, p[o.y] = o.py;
    }

    stack<op> st;

    dsu(int n): d(n, -1), p(n, 0), ok(-1), time(0) {}

    int find(int x) {
        while(d[x] >= 0) x = d[x];
        return x;
    }

    int dist(int x) {
        bool ans = 0;
        while(d[x] >= 0) ans ^= p[x], x = d[x];
        return ans;
    }

    void join(int x, int y) {
        ++time;
        int px = find(x), py = find(y);
        if(px == py) {
            if(!~ok && (dist(x) + dist(y)) % 2 == 0) ok = time;
        }
        else {
            if(d[px] > d[py]) swap(px, py);
            bool val = dist(x) ^ dist(y) ^ 1;
            st.emplace(time, px, py, d[px], d[py], p[px], p[py]);
            d[px] += d[py]; d[py] = px;
            p[py] = val;
        }
    }

    bool is_bipartite() {return !~ok;}

    void rollback(int new_time) {
        time = new_time;
        if(ok > new_time) ok = -1;
        while(!st.empty() && st.top().time > new_time) {
            apply(st.top());
            st.pop();
        }
    }
};

int32_t main() {
    fastio;
    int n, m, k; cin >> n >> m >> k;
    vector<int> color(n);
    rep(i, n) cin >> color[i], --color[i];
    vector<unordered_map<int, vector<int>>> group_edges(k);
    vector<pii> edges(m);
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        if(color[u] > color[v]) swap(u, v);
        edges[i] = {u, v};
        group_edges[color[u]][color[v]].pb(i);
    }
    vector<bool> good(k);
    int cnt = 0;
    dsu d(n);
    rep(i, k) {
        int cur = d.time;
        for(int id: group_edges[i][i]) d.join(edges[id].fi, edges[id].se);
        good[i] = d.is_bipartite();
        cnt += good[i];
        if(!good[i]) d.rollback(cur);
    }
    ll ans = cnt * 1LL * (cnt - 1) / 2;
    rep(i, k) if(good[i]) {
        for(auto& [j, v]: group_edges[i]) if(j != i && good[j]) {
            int cur = d.time;
            for(int id: v) d.join(edges[id].fi, edges[id].se);
            ans -= !d.is_bipartite();
            d.rollback(cur);
        }
    }
    cout << ans << endl;
}