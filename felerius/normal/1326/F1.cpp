// Contest: Codeforces Global Round 7 (https://codeforces.com/contest/1326)
// Problem: F1: Wise Men (Easy Version) (https://codeforces.com/contest/1326/problem/F1)


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

arr<vl, 1u << 14u, 14> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    arr<bool, 14, 14> adj{};
    rep(i, n) {
        string s; cin >> s;
        rep(j, n)
            adj[i][j] = s[j] == '1';
    }

    rep(i, n)
        dp[1u << i][i] = {1};

    for (u32 m = 1; m < (1u << n); ++m) {
        int pop = __builtin_popcount(m);
        auto m2 = m;
        while (m2) {
            int last = __builtin_ctz(m2);
            m2 &= m2 - 1;
            dp[m][last].resize(1u << (pop - 1));
            auto mwithout = m & ~(1u << last);
            rep(k, sz(dp[m][last]) / 2) {
                auto m3 = mwithout;
                while (m3) {
                    int secondlast = __builtin_ctz(m3);
                    m3 &= m3 - 1;
                    dp[m][last][(k << 1u) | adj[last][secondlast]] += dp[mwithout][secondlast][k];
                }
            }
        }
    }

    u32 full = (1u << n) - 1;
    rep(i, 1u << (n - 1)) {
        ll sum = 0;
        rep(j, n)
            sum += dp[full][j][i];
        cout << sum << ' ';
    }

    return 0;
}