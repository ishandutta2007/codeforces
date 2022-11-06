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

ll check(array<int, 18>& d, int n, int k, int res) {
    auto old_d = d;

    int x = 0;
    rep(_, k + 1) {
        trav(di, d)
            x += di;
        int i = sz(d) - 1;
        while (i > 0) {
            if (++d[i] == 10)
                d[i] = 0, --i;
            else
                break;
        }
    }
    if (x <= n && (n - x) % (k + 1) == 0) {
        d = old_d;
        int rem = (n - x) / (k + 1);
        int i = 17 - res;
        while (rem >= 9)
            d[i--] = 9, rem -= 9;
        d[i--] = rem;
        ll num = 0;
        trav(di, d)
            num = num * 10 + di;
        return num;
    }
    return INFL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == 0) {
            string s;
            while (n >= 9)
                s.push_back('9'), n -= 9;
            if (n)
                s.push_back('0' + n);
            reverse(all(s));
            cout << s << '\n';
            continue;
        }

        ll mn = INFL;
        array<int, 18> d;
        rep(first, 10) {
            rep(nines, 17) {
                rep(last,10) {
                    int i = 17;
                    d[i--] = last;
                    rep(_, nines)
                        d[i--] = 9;
                    d[i--] = first;
                    while (i>=0)
                        d[i--] = 0;
                    mn = min(mn, check(d, n, k, 2 + nines));
                }
            }
        }

        if (mn == INFL)
            cout << "-1\n";
        else
            cout << mn << '\n';
    }

    return 0;
}