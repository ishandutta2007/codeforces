// Dog Snacks (https://codeforces.com/contest/1453/problem/E)

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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

pair<int, int> dfs(int v, int p, int d, vector<vector<int>>& adj) {
    int res = 1;
    vector<int> ds;
    trav(v2, adj[v]) {
        if (v2 == p) continue;
        auto [dc, cres] = dfs(v2, v, d + 1, adj);
        res = max(res, cres);
        ds.push_back(dc);
    }

    sort(all(ds));
    if (!sz(ds)) return {d, 1};

    if (v == 0) {
        if (sz(ds) > 1)
            res = max(res, ds[sz(ds)-2] + 1);
        res = max(res, ds.back());
        return {0, res};
    }

    if (sz(ds) > 1)
        res = max(res, ds.back() - d + 1);
    return {ds[0], res};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        rep(i, n - 1) {
            int u, v; cin >> u >> v; --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << dfs(0, -1, 0, adj).second << '\n';
    }

    return 0;
}