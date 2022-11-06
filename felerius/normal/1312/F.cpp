// Contest: Educational Codeforces Round 83 (Rated for Div. 2) (https://codeforces.com/contest/1312)
// Problem: F: Attack on Red Kingdom (https://codeforces.com/contest/1312/problem/F)


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

pi find_cycle(vector<arr<int, 3>>& dp) {
    rep(i, sz(dp)) {
        reps(l, 1, (sz(dp) - i) / 2) {
            bool a = true;
            for (int j = i + l; a && j < sz(dp); ++j)
                a &= dp[j] == dp[(j - i) % l + i];
            if (a)
                return {i, l};
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, x, y, z; cin >> n >> x >> y >> z;
        arr<int, 3> step = {x, y, z};
        vector<arr<int, 3>> dp(200);
        dp[0] = {0, 0, 0};
        reps(i, 1, sz(dp)) {
            rep(j, 3) {
                arr<bool, 4> seen{};
                rep(k, 3)
                    if (k == 0 || j != k)
                        seen[dp[max(0, i - step[k])][k]] = true;
                while (seen[dp[i][j]])
                    dp[i][j]++;
            }
        }

        auto [s, l] = find_cycle(dp);
        auto norm = [s=s, l=l](ll i){ return i >= s ? (i - s) % l + s : i; };
        vl a(n);
        trav(ai, a) cin >> ai;
        int xo = 0;
        rep(i, n) xo ^= dp[norm(a[i])][0];
        if (xo == 0) {
            cout << "0\n";
            continue;
        }
        int cnt = 0;
        rep(i, n) {
            int xo2 = xo ^ dp[norm(a[i])][0];
            rep(j, 3)
                cnt += (xo2 ^ dp[norm(max(0ll, a[i] - step[j]))][j]) == 0;
        }
        cout << cnt << '\n';
    }

    return 0;
}