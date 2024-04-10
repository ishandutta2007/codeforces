// Contest: Educational Codeforces Round 86 (Rated for Div. 2) (https://codeforces.com/contest/1342)
// Problem: D: Multiple Testcases (https://codeforces.com/contest/1342/problem/D)


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

    int n, k; cin >> n >> k;
    vi c(k), cnt(k);
    rep(i, n) {
        int mi; cin >> mi;
        cnt[mi-1]++;
    }
    trav(ci, c) cin >> ci;
    c.push_back(0);

    vvi tc;
    int full = 0;
    for (int i = k - 1; i >= 0; --i) {
        int x = cnt[i];
        if (c[i] > c[i+1])
            full = 0;
        while (x > 0 && full < sz(tc)) {
            while (x > 0 && sz(tc[full]) < c[i])
                tc[full].push_back(i + 1), --x;
            if (sz(tc[full]) == c[i])
                ++full;
        }
        int add = (x + c[i] - 1) / c[i];
        tc.resize(sz(tc) + add);
        while (x > 0 && full < sz(tc)) {
            while (x > 0 && sz(tc[full]) < c[i])
                tc[full].push_back(i + 1), --x;
            if (sz(tc[full]) == c[i])
                ++full;
        }
    }

    cout << sz(tc) << '\n';
    trav(tci, tc) {
        cout << sz(tci);
        trav(i, tci)
            cout << ' ' << i;
        cout << '\n';
    }

    return 0;
}