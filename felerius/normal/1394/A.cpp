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

    int n, d, m; cin >> n >> d >> m;
    vl sm, lg;
    rep(i, n) {
        int ai; cin >> ai;
        (ai > m ? lg : sm).push_back(ai);
    }
    sort(all(lg));
    sort(all(sm));

    reps(i, 1, sz(lg))
        lg[i] += lg[i-1];
    reps(i, 1, sz(sm))
        sm[i] += sm[i-1];
    if (!sz(lg))
        cout << sm.back() << '\n', exit(0);
    if (!sz(sm)) {
        int kept = (sz(lg) + d) / (d + 1);
        cout << (lg.back() - (kept == sz(lg) ? 0ll : lg[sz(lg) - 1 - kept])) << '\n';
        return 0;
    }

    ll res = 0;
    reps(x, 1, sz(lg) + 1) {
        int mn = (x - 1) * d, mx = x * d;
        if (x + mn > n)
            break;
        if (sz(lg) - x > mx)
            continue;
        int sm_covered = max(0, mn - (sz(lg) - x));
        ll sum_sm = sm.back() - (sm_covered ? sm[sm_covered - 1] : 0ll);
        ll sum_lg = lg.back() - (x == sz(lg) ? 0ll : lg[sz(lg) - 1 - x]);
        res = max(res, sum_sm + sum_lg);
    }

    cout << res << '\n';
    return 0;
}