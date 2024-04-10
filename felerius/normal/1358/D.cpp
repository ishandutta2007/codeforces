// Contest: Codeforces Round #645 (Div. 2) (https://codeforces.com/contest/1358)
// Problem: D: The Best Vacation (https://codeforces.com/contest/1358/problem/D)


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll x; cin >> n >> x;
    vi d(2 * n);
    rep(i, n) cin >> d[i], d[n + i] = d[i];

    auto tri = [](int r) { return (ll)r * (r + 1) / 2; };
    auto stair = [&](int l, int r) { return tri(r) - tri(l-1); };

    int l = -1, remlw = 0;
    ll mx = 0, su = 0, w = 0;
    rep(i, 2 * n) {
        w += d[i];
        su += tri(d[i]);
        while (w > x) {
            if (!remlw)
                ++l, remlw = d[l];
            int sw = min((ll)remlw, w - x);
            su -= stair(d[l] - remlw + 1, d[l] - remlw + sw);
            remlw -= sw;
            w -= sw;
        }
        mx = max(mx, su);
    }

    cout << mx << '\n';

    return 0;
}