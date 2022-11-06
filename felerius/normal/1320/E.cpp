// Contest: Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round) (https://codeforces.com/contest/1320)
// Problem: E: Treeland and Viruses (https://codeforces.com/contest/1320/problem/E)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

struct RMQ {
    using T = pi;
    static T combine(T a, T b) { return min(a, b); }

    vector<vector<T>> d;

    explicit RMQ(const vector<T>& v) {
        int k = 1, l = 1, n = sz(v);
        while (k < n) k *= 2, ++l;
        d.assign(l, v);
        rep(i, l-1) rep(j, n)
            d[i+1][j] = combine(d[i][j], d[i][min(j+(1<<i), n-1)]);
    }

    T query(int l, int r) {  // [l, r)
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return combine(d[k][l], d[k][r-(1<<k)]);
    }
};

vi enter, depth;
vpi lcatrav;
vvi adj;

void dfs(int v) {
    enter[v] = sz(lcatrav);
    lcatrav.emplace_back(depth[v], v);
    for (auto v2 : adj[v])
        if (depth[v2] == -1)
            depth[v2] = depth[v] + 1, dfs(v2), lcatrav.emplace_back(depth[v], v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    enter.resize(n), depth.resize(n, -1), adj.resize(n);
    rep(i, n - 1) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    depth[0] = 0;
    dfs(0);
    RMQ lca(lcatrav);
    auto get_lca = [&](int u, int v) {
        auto l = min(enter[u], enter[v]);
        auto r = max(enter[u], enter[v]);
        return lca.query(l, r + 1);
    };
    auto cmp_enter = [&](int u, int v) {
        return pair(enter[u], u) < pair(enter[v], v);
    };
    auto tree_dist = [&](int u, int v) {
        return depth[u] + depth[v] - 2 * get_lca(u, v).first;
    };

    int q; cin >> q;
    while (q--) {
        int k, m; cin >> k >> m;
        vi nod, imp(m);
        vpi vir(k);
        trav(p, vir) cin >> p.first >> p.second, --p.first, nod.push_back(p.first);
        trav(i, imp) cin >> i, --i, nod.push_back(i);

        sort(all(nod), cmp_enter);
        nod.erase(unique(all(nod)), end(nod));
        int inicnt = sz(nod);
        rep(i, inicnt - 1)
            nod.push_back(get_lca(nod[i], nod[i + 1]).second);
        nod.push_back(0);
        sort(all(nod), cmp_enter);
        nod.erase(unique(all(nod)), end(nod));

        vector<vpi> smalladj(sz(nod));
        vi st;
        rep(i, sz(nod)) {
            while (sz(st) && get_lca(nod[i], nod[st.back()]).second != nod[st.back()])
                st.pop_back();
            if (sz(st)) {
                int dist = depth[nod[i]] - depth[nod[st.back()]];
                smalladj[i].emplace_back(st.back(), dist);
                smalladj[st.back()].emplace_back(i, dist);
            }
            st.push_back(i);
        }

        vpi dist(sz(nod), pi(INF, 0));
        priority_queue<pair<pi, int>, vector<pair<pi, int>>, greater<>> q;
        rep(i, k) {
            int v = lower_bound(all(nod), vir[i].first, cmp_enter) - begin(nod);
            dist[v] = {0, i};
            q.emplace(dist[v], v);
        }

        while (sz(q)) {
            auto [d, v] = q.top(); q.pop();
            if (d > dist[v])
                continue;
            for (auto [v2, ed] : smalladj[v]) {
                auto [vir_v, vir_s] = vir[dist[v].second];
                int v2_act = nod[v2];
                pi dn = {(tree_dist(vir_v, v2_act) + vir_s - 1) / vir_s, dist[v].second};
                if (dn < dist[v2])
                    dist[v2] = dn, q.emplace(dn, v2);
            }
        }

        trav(v, imp) {
            int small_v = lower_bound(all(nod), v, cmp_enter) - begin(nod);
            cout << (dist[small_v].second + 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}