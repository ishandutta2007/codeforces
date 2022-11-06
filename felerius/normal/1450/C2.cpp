// Errich-Tac-Toe (Hard Version) (https://codeforces.com/contest/1450/problem/C2)

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
        int n; cin >> n;
        vector<string> g(n);
        trav(gi, g) cin >> gi;

        array<int, 6> a{}, b{};
        int k = 0;
        rep(i, n) rep(j, n) {
            if (g[i][j] == 'X')
                ++k, a[(i + j) % 6]++;
            else if (g[i][j] == 'O')
                ++k, b[(i + j) % 6]++;
        }


        rep(i, 6) rep(j, 6) {
            int i2 = (i + 3) % 6, j2 = (j + 3) % 6;
            if (i == j || i == j2)
                continue;
            if (a[i] + a[i2] + b[j] + b[j2] > k / 3)
                continue;

            rep(x, n) {
                rep(y, n) {
                    if (g[x][y] == '.') {
                        cout << '.';
                        continue;
                    }
                    int d = (x + y) % 6;
                    if (d == i || d == i2)
                        cout << 'O';
                    else if (d == j || d == j2)
                        cout << 'X';
                    else
                        cout << g[x][y];
                }
                cout << '\n';
            }
            goto end;
        }
end:
        int i;
    }

    return 0;
}