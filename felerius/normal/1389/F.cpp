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

struct SegTree {
    using T = int;
    using L = int;
    static constexpr T UNIT = 0;
    static constexpr L NO_LAZY = 0;
    static T combine(T& a, T& b) {
        return max(a, b);
    }

    int k = 1, h = 0;
    vector<T> d, lz;

    void apply(int i, int val) {
        d[i] += val;
        if (i < k) lz[i] += val;
    }

    void rebuild(int i) {
        for (i /= 2; i; i /= 2)
            d[i] = max(d[2*i], d[2*i+1]) + lz[i];
    }

    void push(int i) {
        for (int s = h; s; --s) {
            int j = i >> s;
            if (lz[j] != NO_LAZY)
                apply(2*j, lz[j]), apply(2*j+1, lz[j]), lz[j] = NO_LAZY;
        }
    }

    explicit SegTree(int n) {
        while (k < n) k *= 2, ++h;
        d = vector(2 * k, UNIT);
        lz = vector(k, NO_LAZY);
    }

    T& root() { return d[1]; }
    T& leaf(int i) { return d[k + i]; }

    void build() {
        for (int i = k - 1; i; --i)
            d[i] = combine(d[2*i], d[2*i + 1]);
    }

    void update(int i, T val) {
        d[i + k] = max(d[i + k], val);
        rebuild(i + k);
    }

    void range_update(int l, int r, L val) {
        for (int l2 = l + k, r2 = r + k; l2 < r2; l2 /= 2, r2 /= 2) {
            if (l2 % 2) apply(l2++, val);
            if (r2 % 2) apply(--r2, val);
        }
        rebuild(l + k);
        rebuild(r + k - 1);
    }

    T query(int l, int r) { // [l, r)
        T rl = UNIT, rr = UNIT;
        push(l + k), push(r + k);
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

    int n; cin >> n;
    vector<array<int, 3>> seg1(n);
    vi p;
    p.push_back(0);
    for (auto& [l, r, t] : seg1) cin >> l >> r >> t, p.push_back(l), p.push_back(r), --t;

    sort(all(p));
    p.erase(unique(all(p)), end(p));
    auto idx = [&](int i) { return (int)(lower_bound(all(p), i) - begin(p)); };
    int m = sz(p);

    vector<array<int, 3>> seg(n);
    rep(i, n) {
        auto& [l, r, t] = seg1[i];
        seg[i] = {idx(r), idx(l), t};
    }
    sort(all(seg));

    array<SegTree, 2> dp = {SegTree(m), SegTree(m)};
    for (auto& [r, l, t] : seg) {
        int mx = dp[1-t].query(0, l);
        dp[1-t].range_update(0, l, 1);
        dp[t].update(r, mx + 1);
    }

    cout << max(dp[0].root(), dp[1].root()) << '\n';

    return 0;
}