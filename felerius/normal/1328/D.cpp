// Contest: Codeforces Round #629 (Div. 3) (https://codeforces.com/contest/1328)
// Problem: D: Carousel (https://codeforces.com/contest/1328/problem/D)


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

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vi t(n), c(n, -1); trav(ti, t) cin >> ti;
        bool all = true;
        rep(i, n)
            all &= t[i] == t[0];
        if (all) {
            cout << "1\n";
            rep(i, n) cout << "1 ";
            cout << '\n';
            continue;
        }
        if (n % 2 == 0) {
            cout << "2\n";
            rep(i, n) cout << (i % 2 ? "2 " : "1 ");
            cout << '\n';
            continue;
        }
        int i = 0;
        while (i < n && t[i] != t[(i+1)%n])
            ++i;
        if (i == n) {
            cout << "3\n";
            rep(j, n) c[j] = j % 3 + 1;
            if (c.back() == 1)
                c.back() = 2;
            trav(ci, c)
                cout << ci << ' ';
            cout << '\n';
        } else {
            c[i] = 1;
            rep(j, n - 1)
                c[(i + 1 + j)%n] = 1 + j % 2;
            cout << "2\n";
            trav(ci, c)
                cout << ci << ' ';
            cout << '\n';
        }
    }

    return 0;
}