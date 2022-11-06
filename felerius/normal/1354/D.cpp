// Contest: Educational Codeforces Round 87 (Rated for Div. 2) (https://codeforces.com/contest/1354)
// Problem: D: Multiset (https://codeforces.com/contest/1354/problem/D)


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

struct Fenwick {
    using T = int;
    static constexpr T NEUTRAL = 0;
    static T combine(const T& a, const T& b) { return a + b; }
    static T inv(const T& a, const T& b) { return a - b; }

    vector<T> d;

    explicit Fenwick(int n) : d(n, NEUTRAL) {}

    void update(int i, T val) {
        for (; i < sz(d); i |= i + 1)
            d[i] = combine(d[i], val);
    }

    T query(int i) const { // [0, i)
        T r = NEUTRAL;
        for (; i > 0; i &= i - 1)
            r = combine(r, d[i - 1]);
        return r;
    }

    T query(int l, int r) { // [l, r)
        return inv(query(r), query(l));
    }

    int lower_bound(int v) {
        int w = 1, i = 0;
        while (2 * w <= sz(d))
            w *= 2;
        for (; w; w /= 2) {
            if (i + w <= sz(d) && d[i + w - 1] < v)
                i += w, v -= d[i - 1];
        }
        return i;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, ai;
    cin >> n >> q;
    Fenwick f(n);
    rep(_, n)cin >> ai, f.update(ai - 1, 1);
    while (q--) {
        int k;
        cin >> k;
        if (k > 0)
            f.update(k - 1, 1);
        else {
            int i = f.lower_bound(-k);
            f.update(i, -1);
        }
    }
    if (f.query(n))
        cout << (f.lower_bound(1) + 1) << '\n';
    else
        cout << "0\n";

    return 0;
}