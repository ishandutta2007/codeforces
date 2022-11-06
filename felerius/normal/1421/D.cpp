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

    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        ll c1, c2, c3, c4, c5, c6; cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

        ll cost = 0;
        if (x >= 0 && y >= 0) {
            ll mn = min(x, y), mx = max(x, y);
            cost = min({
                c6 * x + c2 * y,
                c1 * mn + c6 * (x-mn) + c2 * (y-mn),
                c1 * mx + c3 * (mx-x) + c5 * (mx-y),
            });
        } else if (x <= 0 && y <= 0) {
            x = -x, y = -y;
            ll mn = min(x, y), mx = max(x, y);
            cost = min({
                c3 * x + c5 * y,
                c4 * mn + c3 * (x-mn) + c5 * (y-mn),
                c4 * mx + c6 * (mx-x) + c2 * (mx-y),
            });
        } else if (x <= 0 && y >= 0) {
            x = -x;
            cost = min({
                c3 * x + c2 * y,
                c4 * x + c2 * (x + y),
                c1 * y + c3 * (x + y),
            });
        } else {
            y = -y;
            cost = min({
                c6 * x + c5 * y,
                c1 * x + c5 * (x + y),
                c4 * y + c6 * (x + y),
            });
        }

        cout << cost << '\n';
    }

    return 0;
}