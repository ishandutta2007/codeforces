// Contest: Codeforces Round #620 (Div. 2) (https://codeforces.com/contest/1304)
// Problem: E: 1-Trees and Queries (https://codeforces.com/contest/1304/problem/E)


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

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
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

vvi adj;
vpi inord;
vi enter, depth;

void lcadfs(int v, int p, int d) {
    enter[v] = sz(inord);
    depth[v] = d;
    inord.emplace_back(d, v);
    for (auto v2 : adj[v])
        if (v2 != p)
            lcadfs(v2, v, d + 1), inord.emplace_back(d, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b; cin >> n;
    adj.resize(n), enter.resize(n), depth.resize(n);
    rep(_, n - 1)
        cin >> a >> b, --a, --b, adj[a].push_back(b), adj[b].push_back(a);
    lcadfs(0, -1, 0);
    RMQ lca(inord);
    auto pathlen = [&](int a, int b) {
        auto [el, er] = minmax(enter[a], enter[b]);
        int l = lca.query(el, er + 1).second;
        return (depth[a] - depth[l]) + (depth[b] - depth[l]);
    };

    int q; cin >> q;
    while (q--) {
        int x, y, k; cin >> x >> y >> a >> b >> k; --x, --y, --a, --b;
        array<int, 2> shortest = {INF + 1, INF + 1};
        for (auto l : {pathlen(a, b), pathlen(a, x) + 1 + pathlen(y, b), pathlen(a, y) + 1 + pathlen(x, b)})
            shortest[l % 2] = min(shortest[l % 2], l);
        cout << (shortest[k % 2] <= k ? "YES\n" : "NO\n");
    }

    return 0;
}