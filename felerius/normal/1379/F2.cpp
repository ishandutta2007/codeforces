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

// region segtree
struct SegTree {
    using T = tuple<int, int, bool>;
    static constexpr T UNIT = {0, INF, true};
    static T combine(T& a, T& b) {
        auto [al, ah, ao] = a;
        auto [bl, bh, bo] = b;
        return {max(al, bl), min(ah, bh), ao && bo && al <= bh};
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

    void update(int i, int l, int h) {
        d[i + k] = {l, h, l <= h};
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

    int n, m, q; cin >> n >> m >> q;
    SegTree s(m);
    rep(i, m)
        s.leaf(i) = {0, n, true};
    s.build();
    set<pi> blocked;

    while (q--) {
        int i, j; cin >> i >> j; --i, --j;
        i = 2 * n - 1 - i;
        auto [it, ins] = blocked.emplace(j, i);
        if (!ins)
            blocked.erase(it);
        int j2 = j / 2;
        int l = 0, h = n;
        auto l_it = blocked.lower_bound(pair(j2 * 2 + 1, 0));
        if (l_it != begin(blocked) && prev(l_it)->first == j2 * 2)
            l = prev(l_it)->second / 2 + 1;
        auto h_it = blocked.lower_bound(pair(j2 * 2 + 1, 0));
        if (h_it != end(blocked) && h_it->first == j2 * 2 + 1)
            h = h_it->second / 2;
        s.update(j2, l, h);
        cout << (get<2>(s.root()) ? "YES\n" : "NO\n");
    }

    return 0;
}