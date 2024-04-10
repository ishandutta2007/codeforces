// Contest: Educational Codeforces Round 82 (Rated for Div. 2) (https://codeforces.com/contest/1303)
// Problem: E: Erase Subsequences (https://codeforces.com/contest/1303/problem/E)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
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

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}

template <class T, size_t... Is> struct arr_helper;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<typename arr_helper<T, Is...>::type, I>; };
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;

template <class T, class C>
void fillrec(C& c, T val) {
    if constexpr (is_assignable_v<C&, T>)
        c = val;
    else
        trav(i, c) fillrec(i, val);
}

arr<int, 405, 405> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string s, t; cin >> s >> t;
        vector<arr<int, 26>> bef(sz(s));
        arr<int, 26> last;
        last.fill(-1);
        rep(i, sz(s)) {
            last[s[i] - 'a'] = i;
            bef[i] = last;
        }
        int n = sz(s);
        bool pos = false;
        reps(m, 0, sz(t) + 1) {
            int len_front = m, len_back = sz(t) - len_front;
            fillrec(dp, INF);
            dp[len_front][len_back] = 0;
            for (int i = len_front; i >= 0; --i) for (int j = len_back; j >= 0; --j) {
                if (i == len_front && j == len_back)
                    continue;
                int mn = INF;
                if (i < len_front && dp[i + 1][j] < n) {
                    char c = t[i];
                    int idx = bef[n - 1 - dp[i + 1][j]][c - 'a'];
                    if (idx != -1)
                        mn = min(mn, n - idx);
                }
                if (j < len_back && dp[i][j + 1] < n) {
                    char c = t[len_front + j];
                    int idx = bef[n - 1 - dp[i][j + 1]][c - 'a'];
                    if (idx != -1)
                        mn = min(mn, n - idx);
                }
                dp[i][j] = mn;
            }
            if (dp[0][0] <= n) {
                pos = true;
                break;
            }
        }

        cout << (pos ? "YES\n" : "NO\n");
    }

    return 0;
}