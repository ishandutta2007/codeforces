// region boilerplate
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
//endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    auto g = vector(n, vector(m, false));
    char c;
    rep(i, n) rep(j, m) cin >> c, g[i][j] = c == '#';

    bool row = false, col = false;
    rep(i, n) {
        int j = 0;
        while (j < m && !g[i][j]) ++j;
        if (j == m) { row = true; continue; }
        while (j < m && g[i][j]) ++j;
        reps(k, j, m)
            if (g[i][k])
                cout << "-1\n", exit(0);
    }
    rep(i, m) {
        int j = 0;
        while (j < n && !g[j][i]) ++j;
        if (j == n) { col = true; continue; }
        while (j < n && g[j][i]) ++j;
        reps(k, j, n)
            if (g[k][i])
                cout << "-1\n", exit(0);
    }
    if (col != row)
        cout << "-1\n", exit(0);

    int comp = 0;
    rep(i, n) rep(j, m) {
        if (!g[i][j]) continue;
        ++comp;
        queue<pi> q; q.emplace(i, j);
        g[i][j] = false;
        while (sz(q)) {
            auto [a, b] = q.front(); q.pop();
            for (auto [a2, b2] : {pair(a-1,b), {a+1,b}, {a,b-1}, {a,b+1}})
                if (0 <= a2 && a2 < n && 0 <= b2 && b2 < m && g[a2][b2])
                    g[a2][b2] = false, q.emplace(a2, b2);
        }
    }

    cout << comp << '\n';
    return 0;
}