// Contest: Codeforces Round #629 (Div. 3) (https://codeforces.com/contest/1328)
// Problem: E: Tree Queries (https://codeforces.com/contest/1328/problem/E)


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


constexpr int N = 200'005;
array<vi, N> adj;
array<int, N> enter, d;
vpi inorder;

void dfs(int v, int p) {
    enter[v] = sz(inorder);
    inorder.emplace_back(d[v], v);
    for (auto v2 : adj[v])
        if (v2 != p)
            d[v2] = d[v] + 1, dfs(v2, v), inorder.emplace_back(d[v], v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    rep(i, n-1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    RMQ rmq(inorder);
    auto lca = [&](int u, int v) {
        int l = min(enter[u], enter[v]), r = max(enter[u], enter[v]) + 1;
        return rmq.query(l, r).second;
    };

    vi q;
    rep(i, m) {
        int k; cin >> k;
        q.resize(k);
        trav(qi, q) cin >> qi, --qi;
        int low = q[0];
        trav(qi, q)
            if (d[qi] > d[low])
                low = qi;
        bool all = true;
        trav(qi, q) {
            int u = low, v = qi;
            int l = lca(u, v);
            all &= (d[u] - d[l] < 2 || d[v] - d[l] < 2);
        }
        cout << (all ? "YES\n" : "NO\n");
    }

    return 0;
}