// Contest: Codeforces Round #644 (Div. 3) (https://codeforces.com/contest/1360)
// Problem: F: Spy-string (https://codeforces.com/contest/1360/problem/F)


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

// region dimarr
template <class T, size_t... Is> struct arr_helper;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<typename arr_helper<T, Is...>::type, I>; };
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
// endregion

arr<pi, 11, 1 << 10> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> a(n);
        trav(ai, a) cin >> ai;
        rep(i, 1 << n)
            dp[0][i] = {0, 0};
        rep(i, m) {
            int x = m - 1 - i;
            arr<int, 10> ma{};
            rep(j, n)
                rep(k, n)
                    ma[j] |= (a[j][x] != a[k][x]) << k;
            rep(j, 1 << n) {
                dp[i+1][j] = {-1, 0};
                rep(k, n) {
                    if ((j & ma[k]) == 0 && dp[i][j | ma[k]].first != -1) {
                        dp[i+1][j] = {k, j | ma[k]};
                        break;
                    }
                }
            }
        }

        if (dp[m][0].first == -1)
            cout << "-1\n";
        else {
            string r;
            int ma = 0;
            for (int i = m; i > 0; --i) {
                r.push_back(a[dp[i][ma].first][m - i]);
                ma = dp[i][ma].second;
            }
            cout << r << '\n';
        }
    }

    return 0;
}