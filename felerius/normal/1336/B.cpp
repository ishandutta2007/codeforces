// Contest: Codeforces Round #635 (Div. 1) (https://codeforces.com/contest/1336)
// Problem: B: Xenia and Colorful Gems (https://codeforces.com/contest/1336/problem/B)


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
        int nr, ng, nb; cin >> nr >> ng >> nb;
        array<vi, 3> a = {vi(nr), vi(ng), vi(nb)};
        rep(i, 3)
            trav(j, a[i])
                cin >> j;
        trav(ai, a)
            sort(all(ai));

        ll mn = 3 * INFL;
        for (auto [i, j, k] : {tuple(0, 1, 2), {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}) {
            auto itl = begin(a[i]), endl = end(a[i]);
            auto itr = begin(a[k]), endr = end(a[k]);
            for (auto& mi : a[j]) {
                while (itl + 1 < endl && *(itl + 1) <= mi)
                    ++itl;
                while (itr < endr && *itr < mi)
                    ++itr;
                if (itl != endl && itr != endr) {
                    ll d1 = mi - *itl, d2 = *itr - mi, d3 = *itr - *itl;
                    mn = min(mn, d1 * d1 + d2 * d2 + d3 * d3);
                }
            }
        }
        cout << mn << '\n';
    }

    return 0;
}