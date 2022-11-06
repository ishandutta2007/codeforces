// Contest: Educational Codeforces Round 82 (Rated for Div. 2) (https://codeforces.com/contest/1303)
// Problem: D: Fill The Bag (https://codeforces.com/contest/1303/problem/D)


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        array<int, 30> c{};
        u64 n; int m; cin >> n >> m;
        u64 sum = 0;
        rep(i, m) {
            u32 ai; cin >> ai;
            sum += ai;
            c[__builtin_ctz(ai)]++;
        }
        if (sum < n) {
            cout << "-1\n";
            continue;
        }
        int res = 0;
        u64 sum_smaller = 0;
        for (u32 i = 0; i < 62; ++i) {
            if (i < 30)
                sum_smaller += (1ull << i) * c[i], c[i] = 0;
            if ((n & (1ull << i)) == 0)
                continue;
            if (sum_smaller >= (1ull << i))
                sum_smaller -= 1ull << i;
            else {
                u32 j = i + 1;
                while (c[j] == 0)
                    ++j;
                res += j - i;
                for (u32 k = i; k < j; ++k)
                    c[k]++;
                c[j]--;
            }
        }

        cout << res << '\n';
    }

    return 0;
}