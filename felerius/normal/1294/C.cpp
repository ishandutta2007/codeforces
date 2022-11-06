// Contest: Codeforces Round #615 (Div. 3) (https://codeforces.com/contest/1294)
// Problem: C: Product of Three Numbers (https://codeforces.com/contest/1294/problem/C)


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
        int n1 = n;
        vpi p;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i)
                continue;
            p.emplace_back(i, 0);
            while (n % i == 0)
                p.back().second++, n /= i;
        }
        if (n > 1)
            p.emplace_back(n, 1);
        if (sz(p) >= 3) {
            cout << "YES\n" << p[0].first << ' ' << p[1].first << ' ' << (n1 / p[0].first / p[1].first) << '\n';
        } else if (sz(p) == 2) {
            auto [p1, e1] = p[0];
            auto [p2, e2] = p[1];
            if (e2 > e1)
                swap(e1, e2), swap(p1, p2);
            if (e1 >= 3)
                cout << "YES\n" << p1 << ' ' << (p1*p1) << ' ' << (n1/p1/p1/p1) << '\n';
            else if (e1 == 2 && e2 == 2)
                cout << "YES\n" << p1 << ' ' << p2 << ' ' << (p1*p2) << '\n';
            else
                cout << "NO\n";
        } else {
            auto [pi, e] = p[0];
            if (e >= 6)
                cout << "YES\n" << pi << ' ' << (pi*pi) << ' ' << (n1/pi/pi/pi) << '\n';
            else
                cout << "NO\n";
        }
    }

    return 0;
}