// Contest: Codeforces Round #612 (Div. 1) (https://codeforces.com/contest/1286)
// Problem: A: Garland (https://codeforces.com/contest/1286/problem/A)


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

template <class T, size_t... Is> struct arr_helper;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<typename arr_helper<T, Is...>::type, I>; };
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;

arr<int, 101, 101, 101, 2> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    arr<int, 2> rem = {n / 2, (n + 1) / 2};
    vi p(n);
    trav(pi, p) {
        cin >> pi;
        if (pi != 0)
            rem[pi % 2]--;
    }

    rep(i, 101) rep(j, 101) rep(k, 2) dp[0][i][j][k] = 0;
    rep(i, n) {
        rep(j, 101) rep(k, 101) rep(x, 2) {
            dp[i+1][j][k][x] = INF;
            if (p[i] != 0 && p[i] % 2 != x)
                continue;
            int dj = j - (p[i] == 0 && x == 0);
            int dk = k - (p[i] == 0 && x == 1);
            if (dj < 0 || dk < 0)
                continue;
            rep(y, 2)
                dp[i+1][j][k][x] = min(dp[i+1][j][k][x], dp[i][dj][dk][y] + (x != y));
        }
    }

    cout << min(dp[n][rem[0]][rem[1]][0], dp[n][rem[0]][rem[1]][1]) << '\n';
    return 0;
}