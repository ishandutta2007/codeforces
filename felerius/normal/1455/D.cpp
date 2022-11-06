// Sequence and Swaps (https://codeforces.com/contest/1455/problem/D)

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

void chmin(int& a, int b) { a = min(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, x0; cin >> n >> x0;
        vector<int> a(n);
        trav(ai, a) cin >> ai;

        auto b = a;
        b.push_back(x0);
        sort(all(b));
        b.erase(unique(all(b)), end(b));
        x0 = (int)(lower_bound(all(b), x0) - begin(b));
        trav(ai, a)
            ai = (int)(lower_bound(all(b), ai) - begin(b));

        int m = sz(b);
        // start of suffix, value of x, max of prefix
        auto dp = vector(n, vector(m, vector(m, INF)));
        rep(x, m) rep(mx, m) {
            if (a[n-1] >= mx)
                dp[n-1][x][mx] = 0;
            else if (x >= mx && a[n-1] > x)
                dp[n-1][x][mx] = 1;
        }

        repr(i, n - 2) {
            rep(x, m) rep(mx, m) {
                if (a[i] >= mx)
                    chmin(dp[i][x][mx], dp[i+1][x][a[i]]);
                if (x >= mx && a[i] > x)
                    chmin(dp[i][x][mx], dp[i+1][a[i]][x] + 1);
            }
        }

        cout << (dp[0][x0][0] >= INF ? -1 : dp[0][x0][0]) << '\n';
    }

    return 0;
}