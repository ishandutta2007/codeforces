// Contest: Codeforces Round #370 (Div. 2) (https://codeforces.com/contest/712)
// Problem: E: Memory and Casinos (https://codeforces.com/contest/712/problem/E)


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

struct SegTree {
    using T = pair<double, double>;
    static constexpr T UNIT = {1, 0};
    static T combine(T& a, T& b) {
        auto [l1, r1] = a;
        auto [l2, r2] = b;
        return {
            l1 * l2 / (1 + (l2 - 1) * r1),
            r2 + r1 * l2 * (1 - r2) / (1 - r1 * (1 - l2)),
        };
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

    void update(int i, double p) {
        d[i + k] = {p, p};
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int n, q, a, b; cin >> n >> q;
    SegTree s(n);
    rep(i, n)
        cin >> a >> b, s.update(i, (double)a / b);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i >> a >> b; --i;
            s.update(i, (double)a / b);
        } else {
            int l, r; cin >> l >> r; --l;
            cout << s.query(l, r).first << '\n';
        }
    }

    return 0;
}