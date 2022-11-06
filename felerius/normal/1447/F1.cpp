// Frequency Problem (Easy Version) (https://codeforces.com/contest/1447/problem/F1)

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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> idx(n);
    int mx = 0;
    rep(i, n) cin >> a[i], --a[i], idx[a[i]].push_back(i), mx = max(mx, sz(idx[a[i]]));

    int d = -1;
    rep(i, n) {
        if (sz(idx[i]) != mx) continue;
        if (d != -1) cout << n << '\n', exit(0);
        d = i;
    }

    vector<int> ds(n);
    ds[0] = a[0] == d;
    rep(i, 1, n)
        ds[i] = ds[i-1] + (a[i] == d);

    vector<pair<int, int>> diff(2 * n + 1, pair(0, -1));
    vector<int> sub;
    int res = 0;
    constexpr int LIMIT = 300;

    rep(i, n) {
        if (i == d || !sz(idx[i])) continue;
        diff[n] = {-1, i};

        if (sz(idx[i]) >= LIMIT) {
            int delta = 0;
            rep(j, n) {
                delta += (a[j] == i ? 1 : (a[j] == d ? -1 : 0));
                if (diff[delta + n].second == i)
                    res = max(res, j - diff[delta + n].first);
                else
                    diff[delta + n] = {j, i};
            }
        } else {
            sub.clear();
            rep(j, sz(idx[i])) {
                auto it = lower_bound(all(idx[d]), idx[i][j]);
                auto lit = it - begin(idx[d]) >= (LIMIT + 5) ? it - LIMIT - 5 : begin(idx[d]);
                auto rit = end(idx[d]) - it >= (LIMIT + 5) ? it + LIMIT + 5 : end(idx[d]);
                lit = upper_bound(lit, it, (sz(sub) ? sub.back() : -1));
                rit = lower_bound(it, rit, (j + 1 < sz(idx[i]) ? idx[i][j+1] : n));
                for (it = lit; it < rit && *it < idx[i][j]; ++it)
                    sub.push_back(*it);
                sub.push_back(idx[i][j]);
                for (; it < rit; ++it)
                    sub.push_back(*it);
            }

            int is = 0;
            trav(j, sub) {
                if (j && diff[is - ds[j - 1] + n].second == i)
                    res = max(res, j - 1 - diff[is - ds[j - 1] + n].first);
                is += a[j] == i;
                if (diff[is - ds[j] + n].second != i)
                    diff[is - ds[j] + n] = {j, i};
            }

            if (diff[is - ds[n - 1] + n].second == i)
                res = max(res, n - 1 - diff[is - ds[n - 1] + n].first);
        }
    }

    cout << res << '\n';
    return 0;
}