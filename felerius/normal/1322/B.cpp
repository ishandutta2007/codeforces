// Contest: Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics) (https://codeforces.com/contest/1322)
// Problem: B: Present (https://codeforces.com/contest/1322/problem/B)


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

    int n; cin >> n;
    vi a(n);
    trav(ai, a) cin >> ai;
    sort(all(a));

    int res = 0;
    rep(i, 25) {
        int mb = 1 << i, ma = mb - 1;
        auto mid = partition(all(a), [&](int ai) { return (ai & mb) == 0; });
        sort(begin(a), mid, [&](int i, int j) { return (i & ma) < (j & ma); });
        sort(mid, end(a), [&](int i, int j) { return (i & ma) < (j & ma); });

        ll cnt = 0;
        for (auto it = begin(a); it < mid; ++it) {
            auto it2 = partition_point(it + 1, mid, [&](int i) { return (i & ma) + (*it & ma) < mb; });
            cnt += mid - it2;
        }
        for (auto it = mid; it < end(a); ++it) {
            auto it2 = partition_point(it + 1, end(a), [&](int i) { return (i & ma) + (*it & ma) < mb; });
            cnt += end(a) - it2;
        }
        for (auto it = begin(a); it < mid; ++it) {
            auto it2 = partition_point(mid, end(a), [&](int i) { return (i & ma) + (*it & ma) < mb; });
            cnt += it2 - mid;
        }

        res |= (int)(cnt % 2) * mb;
    }

    cout << res << '\n';
    return 0;
}