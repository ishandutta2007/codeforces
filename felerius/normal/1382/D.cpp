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

// region dimvec
template <class T, class... Is> struct vec_helper;
template <class T> struct vec_helper<T> { static auto f(T val) { return val; } };
template <class T, class I, class... Is> struct vec_helper<T, I, Is...> {
    static auto f(T val, I size, Is... sizes) {
        return vector(size, vec_helper<T, Is...>::f(val, sizes...));
    }
};
template <class T, class... Is> auto vec(T val, Is... sizes) { return vec_helper<T, Is...>::f(val, sizes...); }
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi p(2 * n);
        trav(pi, p) cin >> pi, --pi;

        auto dp = vec(pi(-1, -1), n + 1, n + 1);
        reps(i, 1, n + 1)
            dp[i][0] = {p[2*n - i], -1}, dp[0][i] = {-1, p[2*n - 1 - i]};
        reps(i, 1, n + 1) {
            reps(j, 1, n + 1) {
                int val = p[2*n - i - j];
                if (dp[i-1][j].second > val)
                    dp[i][j] = {val, dp[i-1][j].second};
                if (dp[i][j-1].first > val) {
                    dp[i][j].first = max(dp[i][j].first, dp[i][j-1].first);
                    dp[i][j].second = max(dp[i][j].second, val);
                }
            }
        }

        /* rep(i, n+1) */
        /*     rep(j, n+1) */
        /*         cout << i << ',' << j << ": " << dp[i][j].first << ',' << dp[i][j].second << '\n'; */

        cout << (dp[n][n].first != -1 ? "YES\n" : "NO\n");
    }

    return 0;
}