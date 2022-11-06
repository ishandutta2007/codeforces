// Binary Table (Easy Version) (https://codeforces.com/contest/1440/problem/C1)

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        auto g = vector(n, vector(m, false));
        rep(i, n) {
            string s; cin >> s;
            rep(j, m) g[i][j] = s[j] == '1';
        }

        vector<array<int, 6>> ops;
        auto do_op = [&](int i1, int j1, int i2, int j2, int i3, int j3) {
            g[i1][j1] = !g[i1][j1];
            g[i2][j2] = !g[i2][j2];
            g[i3][j3] = !g[i3][j3];
            ops.push_back({i1, j1, i2, j2, i3, j3});
        };

        rep(i, n - 2)
            rep(j, m)
                if (g[i][j])
                    do_op(i, j, i + 1, j, i + 1, (j ? j - 1 : j + 1));

        rep(j, m - 2) {
            if (g[n-2][j] && g[n-1][j])
                do_op(n-2, j, n-1, j, n-1, j+1);
            else if (g[n-2][j])
                do_op(n-2, j, n-2, j+1, n-1, j+1);
            else if (g[n-1][j])
                do_op(n-1, j, n-2, j+1, n-1, j+1);
        }

        vector<vector<pair<int, array<int, 6>>>> adj(16);
        rep(i, 16) {
            rep(j, 4) {
                int x = 0;
                array<int, 6> op{};
                rep(k, 4)
                    if (k != j)
                        op[x++] = k / 2, op[x++] = k % 2;
                int to = (~i & 0xF) ^ (1 << j);
                adj[to].emplace_back(i, op);
            }
        }

        vector<tuple<int, int, array<int, 6>>> dist(16);
        dist[0] = {0, 0, array<int, 6>{}};
        queue<int> q; q.push(0);
        while (sz(q)) {
            int v = q.front(); q.pop();
            for (auto& [v2, op] : adj[v])
                if (!get<0>(dist[v2]))
                    dist[v2] = {get<0>(dist[v]) + 1, v, op}, q.push(v2);
        }

        int v = ((int)g[n-2][m-2]) | ((int)(g[n-2][m-1]) << 1) | ((int)(g[n-1][m-2]) << 2) | ((int)g[n-1][m-1] << 3);
        while (v) {
            auto op = get<2>(dist[v]);
            op[0] += n-2;
            op[2] += n-2;
            op[4] += n-2;
            op[1] += m-2;
            op[3] += m-2;
            op[5] += m-2;
            do_op(op[0], op[1], op[2], op[3], op[4], op[5]);
            v = get<1>(dist[v]);
        }

        cout << sz(ops) << '\n';
        trav(op, ops)
            rep(i, 6)
                cout << (op[i]+1) << " \n"[i==5];
    }

    return 0;
}