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

    int n, q; cin >> n >> q;
    vi a(n);
    trav(ai, a) cin >> ai;
    sort(all(a));

    set<int> vals(all(a));
    multiset<int> dists;
    reps(i, 1, n)
        dists.emplace(a[i] - a[i-1]);

    cout << (*rbegin(vals) - *begin(vals) - (sz(dists) ? *rbegin(dists) : 0)) << '\n';
    while (q--) {
        int t, x; cin >> t >> x;
        if (t) {
            auto it = vals.emplace(x).first;
            if (sz(vals) > 1) {
                if (it != begin(vals) && next(it) != end(vals)) {
                    int l = *prev(it), r = *next(it);
                    dists.erase(dists.find(r - l));
                    dists.emplace(x - l);
                    dists.emplace(r - x);
                } else if (it != begin(vals))
                    dists.emplace(x - *prev(it));
                else
                    dists.emplace(*next(it) - x);
            }
        } else {
            auto it = vals.find(x);
            if (it != begin(vals))
                dists.erase(dists.find(x - *prev(it)));
            if (next(it) != end(vals))
                dists.erase(dists.find(*next(it) - x));
            if (it != begin(vals) && next(it) != end(vals))
                dists.emplace(*next(it) - *prev(it));
            vals.erase(it);
        }
        if (sz(vals))
            cout << (*rbegin(vals) - *begin(vals) - (sz(dists) ? *rbegin(dists) : 0)) << '\n';
        else
            cout << "0\n";
    }

    return 0;
}