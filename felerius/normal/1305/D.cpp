// Contest: Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!) (https://codeforces.com/contest/1305)
// Problem: D: Kuroni and the Celebration (https://codeforces.com/contest/1305/problem/D)


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

bool dfs_path(int v, int p, int a, vvi& adj, vi& path) {
    if (v == a) {
        path.push_back(v);
        return true;
    }
    for (auto v2 : adj[v]) {
        if (v2 == p)
            continue;
        if (dfs_path(v2, v, a, adj, path)) {
            path.push_back(v2);
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vvi adj(n);
    vpi e(n - 1);
    rep(i, n - 1) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        e[i] = {x, y};
    }

    vvi dadj(n);
    for (int i = 0; i < n - 1; i += 2) {
        auto [u1, v1] = e[i];
        auto [u2, v2] = i + 1 == n - 1 ? e[0] : e[i+1];
        vi path;
        pair<int, pi> mx = {0, pair(-1, -1)};
        for (auto [u, v] : {pair(u1, u2), {u1, v2}, {v1, u2}, {v1, v2}}) {
            path.clear();
            dfs_path(u, -1, v, adj, path);
            mx = max(mx, pair(sz(path), pi(u, v)));
        }
        auto [u, v] = mx.second;
        cout << "? " << (u+1) << ' ' << (v+1) << '\n' << flush;
        int r; cin >> r; --r;
        for (auto x : {u, v}) {
            path.clear();
            dfs_path(r, -1, x, adj, path);
            for (int j = 0; j + 1 < sz(path); ++j)
                dadj[path[j]].push_back(path[j+1]);
        }
    }

    vi indeg(n);
    trav(row, dadj)
        trav(v, row)
            indeg[v]++;
    int r = 0;
    while (indeg[r])
        ++r;
    cout << "! " << (r+1) << '\n';

    return 0;
}