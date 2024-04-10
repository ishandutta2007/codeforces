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

    int n; cin >> n;
    vi a(n);
    trav(ai, a) cin >> ai;

    vpi parts, next_parts;
    parts.emplace_back(0, n);
    int x = 0;

    ll total_inv = 0;
    for (int s = 29; s >= 0; --s) {
        next_parts.clear();
        ll cnt_zero = 0, cnt_one = 0;
        for (auto [l, r] : parts) {
            ll inv = 0, ones = 0;
            reps(i, l, r) {
                if ((a[i] >> s) & 1)
                    ++ones;
                else
                    inv += ones;
            }

            auto it = stable_partition(begin(a) + l, begin(a) + r, [&](int ai) {
                return ((ai >> s) & 1) == 0;
            });
            int m = (int)(it - begin(a));

            cnt_zero += inv;
            cnt_one += (ll)(r - m) * (m - l) - inv;

            if (m > l)
                next_parts.emplace_back(l, m);
            if (r > m)
                next_parts.emplace_back(m, r);
        }

        x |= (int)(cnt_one < cnt_zero) << s;
        total_inv += min(cnt_zero, cnt_one);
        swap(parts, next_parts);
    }

    cout << total_inv << ' ' << x << '\n';
    return 0;
}