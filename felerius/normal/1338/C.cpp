// Contest: Codeforces Round #633 (Div. 1) (https://codeforces.com/contest/1338)
// Problem: C: Perfect Triples (https://codeforces.com/contest/1338/problem/C)


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        if (n < 4) {
            cout << n << '\n';
            continue;
        }
        int exp = (sizeof(ll) * 8 - 1 - __builtin_clzll(n)) / 2;
        ll base = 1;
        rep(_, exp) base *= 4;
        n -= base;
        switch (n % 3) {
            case 0:
                cout << (base + n / 3) << '\n';
                break;
            case 1: {
                ll r = base * 2;
                ll e = 1;
                array<ll, 4> a = {0, 2, 3, 1};
                rep(_, exp)
                    r += a[(n / 3) / e % 4] * e, e *= 4;
                cout << r << '\n';
                break;
            }
            case 2: {
                ll r = base * 3;
                ll e = 1;
                array<ll, 4> a = {0, 3, 1, 2};
                rep(_, exp)
                    r += a[(n / 3) / e % 4] * e, e *= 4;
                cout << r << '\n';
                break;
            }
        }
    }

    return 0;
}