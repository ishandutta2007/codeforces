// Contest: Codeforces Round #613 (Div. 2) (https://codeforces.com/contest/1285)
// Problem: D: Dr. Evil Underscores (https://codeforces.com/contest/1285/problem/D)


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
#   define sz(x) ((int)size(x))
#else
#   define sz(x) ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define all(a)         (a).begin(),(a).end()
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

using Iter = vector<u32>::iterator;
u32 solve(u32 b, u32 base, Iter it, Iter it_end) {
    u32 mid = (1u << b) + base;
    auto it_mid = lower_bound(it, it_end, mid);
    if (b == 0)
        return (it_mid == it_end || it_mid == it) ? 0 : 1;

    if (it_mid == it_end)
        return solve(b - 1, base, it, it_end);
    else if (it_mid == it)
        return solve(b - 1, mid, it, it_end);
    auto mn_left = solve(b - 1, base, it, it_mid);
    auto mn_right = solve(b - 1, mid, it_mid, it_end);
    return (1u << b) + min(mn_left, mn_right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<u32> a(n);
    trav(ai, a) cin >> ai;
    sort(all(a));
    cout << solve(29, 0, all(a)) << '\n';

    return 0;
}