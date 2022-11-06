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
        int n, l; cin >> n >> l;
        vi a(n);
        trav(ai, a) cin >> ai;

        ld low = 0, high = l;
        ld last_t1 = 0;
        while (high - low >= 1e-7) {
            auto mid = (low + high) / 2;
            ld t1 = 0, t2 = 0;

            int pos1 = 0, pos2 = l;
            ld speed1 = 1, speed2 = 1;
            rep(i, n) {
                if (a[i] >= mid)
                    break;
                t1 += (a[i] - pos1) / speed1;
                speed1 += 1;
                pos1 = a[i];
            }
            t1 += (mid - pos1) / speed1;

            for (int i = n - 1; i >= 0; --i) {
                if (a[i] <= mid)
                    break;
                t2 += (pos2 - a[i]) / speed2;
                speed2 += 1;
                pos2 = a[i];
            }
            t2 += (pos2 - mid) / speed2;

            if (t1 > t2)
                high = mid;
            else
                low = mid;
            last_t1 = t1;
        }

        cout << setprecision(20) << fixed << last_t1 << '\n';
    }

    return 0;
}