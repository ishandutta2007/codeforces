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

    int n, h, m, k; cin >> n >> h >> m >> k;
    vi t(n);
    int m2 = m / 2;
    rep(i, n) {
        int hi, mi; cin >> hi >> mi;
        t[i] = mi % m2;
    }

    vi coords = {0};
    trav(ti, t) {
        coords.push_back((ti + 1) % m2);
        coords.push_back((ti + k) % m2);
    }
    sort(all(coords));
    coords.erase(unique(all(coords)), end(coords));

    vi diff(sz(coords));
    auto idx = [&](int i) { return lower_bound(all(coords), i) - begin(coords); };
    trav(ti, t) {
        int t1 = (ti + 1) % m2, t2 = (ti + k) % m2;
        diff[idx(t1)]++;
        if (ti + 1 < m2 && ti + k >= m2)
            diff[idx(0)]++;
        diff[idx(t2)]--;
    }
    reps(i, 1, sz(diff))
        diff[i] += diff[i-1];

    auto min_it = min_element(all(diff));
    auto st = coords[min_it - begin(diff)];
    cout << *min_it << ' ' << st << '\n';
    rep(i, n) {
        int d = (st - t[i] + m2) % m2;
        if (1 <= d && d < k)
            cout << (i + 1) << ' ';
    }
    cout << '\n';

    return 0;
}