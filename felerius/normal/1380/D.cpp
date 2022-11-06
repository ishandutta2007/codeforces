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

    int n, m; cin >> n >> m;
    if (m > n)
        cout << "-1\n", exit(0);
    int k; ll x, y; cin >> x >> k >> y;
    vi a(n), b(m);
    trav(ai, a) cin >> ai, --ai;
    trav(bi, b) cin >> bi, --bi;

    vi bidx(m);
    int i = 0;
    rep(j, n) {
        if (i == m) break;
        if (a[j] == b[i])
            bidx[i++] = j;
    }
    if (i != m)
        cout << "-1\n", exit(0);

    ll cost = 0;
    rep(i, m + 1) {
        int l = i ? bidx[i - 1] + 1 : 0;
        int r = i == m ? n : bidx[i];
        if (l >= r)
            continue;
        ll gapcost = INFL;
        int w = r - l;
        if (w >= k)
            gapcost = min({
                gapcost,
                (w / k) * x + (w % k) * y,  // As many fireballs as possible
                x + (w - k) * y             // Exactly 1 fireball
            });
        int adj = max(i ? b[i - 1] : -1, i == m ? -1 : b[i]);
        int inside = *max_element(begin(a) + l, begin(a) + r);
        if (adj > inside)
            gapcost = min(gapcost, w * y); // No fireballs
        if (gapcost == INFL)
            cout << "-1\n", exit(0);
        cost += gapcost;
    }

    cout << cost << '\n';
    return 0;
}