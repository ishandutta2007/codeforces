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
        int n; ll k; cin >> n >> k;
        ll l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2)
            swap(l1, l2), swap(r1, r2);
        ll act = 0, rem = 0;
        if (l2 < r1) {
            ll over = min(r1, r2) - l2;
            k -= n * over;
            act = 0;
            rem = (r1 - l1) + (r2 - l2) - 2 * over;
        } else {
            act = l2 - r1;
            rem = r2 - l1;
        }

        if (k <= 0) {
            cout << "0\n";
            continue;
        }

        ll cost = act + min(k, rem);
        k -= min(k, rem);
        rep(i, n-1) {
            ll step = min(k, rem);
            if (act + step < 2 * step)
                cost += act + step;
            else
                cost += 2 * step;
            k -= step;
        }
        cost += 2 * k;

        cout << cost << '\n';
    }

    return 0;
}