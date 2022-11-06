// {{{ boilerplate
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
// }}}

// region segtree
struct SegTree {
    using T = pi;
    static constexpr T UNIT = {0, -INF};
    static T combine(T& a, T& b) {
        return {a.first + b.first, max(a.second, a.first + b.second)};
    }

    int k = 1;
    vector<T> d;

    explicit SegTree(int n) {
        while (k < n) k *= 2;
        d = vector(2 * k, UNIT);
    }

    T& root() { return d[1]; }
    T& leaf(int i) { return d[k + i]; }

    void build() {
        for (int i = k - 1; i; --i)
            d[i] = combine(d[2*i], d[2*i + 1]);
    }

    void update(int i, int diff) {
        d[i + k].first += diff;
        d[i + k].second += diff;
        for (int j = i + k; j /= 2;)
            d[j] = combine(d[2*j], d[2*j+1]);
    }

    T query(int l, int r) { // [l, r)
        T rl = UNIT, rr = UNIT;
        for (l += k, r += k; l < r; l /= 2, r /= 2) {
            if (l % 2) rl = combine(rl, d[l++]);
            if (r % 2) rr = combine(d[--r], rr);
        }
        return combine(rl, rr);
    }
};
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m; cin >> n >> k >> m; --k;
    set<pi> pawns;
    multiset<int> pos;
    SegTree s(2 * n);
    s.leaf(0) = {-n, -n};
    reps(i, 1, 2 * n)
        s.leaf(i) = {1, 1};
    s.build();

    while (m--) {
        int x, y; cin >> x >> y; --x, --y;
        int p = y + abs(x - k);
        auto it = pawns.find(pi(x, y));
        if (it == end(pawns)) {
            pawns.emplace(x, y);
            pos.emplace(p);
            s.update(0, 1);
            s.update(p + 1, -1);
        } else {
            pawns.erase(it);
            pos.erase(pos.find(p));
            s.update(0, -1);
            s.update(p + 1, 1);
        }

        if (sz(pos)) {
            int mx = *rbegin(pos);
            cout << max(0, s.query(0, mx + 1).second) << '\n';
        } else
            cout << "0\n";
    }

    return 0;
}