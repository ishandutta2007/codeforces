// Contest: Codeforces Round #613 (Div. 2) (https://codeforces.com/contest/1285)
// Problem: B: Just Eat It! (https://codeforces.com/contest/1285/problem/B)


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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        trav(ai, a) cin >> ai;

        ll sum = 0;
        trav(ai, a) sum += ai;
        ll mx = 0, suffmx = 0;
        bool waszero = false;
        rep(i, n) {
            if (i + 1 == n && suffmx == sum - a.back() && !waszero)
                suffmx -= a[0];
            suffmx = max(0ll, suffmx + a[i]);
            waszero |= suffmx == 0;
            mx = max(mx, suffmx);
        }
        if (mx == 0)
            mx = min(mx, (ll)*max_element(all(a)));
        cout << (sum > mx ? "YES" : "NO") << '\n';
    }

    return 0;
}