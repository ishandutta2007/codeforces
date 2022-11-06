// Contest: Codeforces Round #613 (Div. 2) (https://codeforces.com/contest/1285)
// Problem: C: Fadi and LCM (https://codeforces.com/contest/1285/problem/C)


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

#if __cpp_lib_nonmember_container_access >= 201411
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

#if __has_cpp_attribute(maybe_unused) >= 201603
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

    ll x; cin >> x;
    ll xi = x;
    vl f;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        f.emplace_back(1);
        while(x % i == 0)
            f.back() *= i, x /= i;
    }
    if (x > 1)
        f.emplace_back(x);

    int n = sz(f);
    ll mn = xi;
    for (u32 m = 0; m < (1u << n); ++m) {
        ll a = 1;
        u32 m2 = m;
        while (m2)
            a *= f[__builtin_ctzl(m2)], m2 &= m2 - 1;
        mn = min(mn, max(a, xi / a));
    }

    cout << mn << ' ' << (xi / mn) << '\n';
    return 0;
}