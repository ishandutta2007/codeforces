// Cleaning the Phone (https://codeforces.com/contest/1475/problem/D)

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#   define MAYBE_UNUSED
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using u64 = uint64_t;
using u32 = uint32_t;

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(n);
        trav(ai, a) cin >> ai;
        trav(bi, b) cin >> bi;

        vector<ll> x, y;
        rep(i, n)
            (b[i] == 2 ? y : x).push_back(a[i]);
        sort(all(x), greater<>{});
        sort(all(y), greater<>{});
        x.insert(begin(x), 0);
        y.insert(begin(y), 0);
        partial_sum(all(x), begin(x));
        partial_sum(all(y), begin(y));

        int mn = INF;
        rep(i, sz(x)) {
            auto it = lower_bound(all(y), m - x[i]);
            if (it != end(y))
                mn = min(mn, i + 2 * int(it - begin(y)));
        }

        cout << (mn == INF ? -1 : mn) << '\n';
    }

    return 0;
}