// Contest: Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round) (https://codeforces.com/contest/1320)
// Problem: C: World of Darkraft: Battle for Azathoth (https://codeforces.com/contest/1320/problem/C)


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
    using T = pl;
    static constexpr T UNIT = pl{-INFL, 0};
    static T combine(T& a, T& b) {
        return {max(a.first, b.first + a.second), a.second + b.second};
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

    void update(int i, ll val) {
        d[i + k].first += val;
        d[i + k].second += val;
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

    int n, m, p; cin >> n >> m >> p;
    vpi weap(n), arm(m);
    trav(p, weap) cin >> p.first >> p.second;
    trav(p, arm) cin >> p.first >> p.second;
    vector<array<int, 3>> monst(p);
    for (auto& [x, y, z] : monst) cin >> x >> y >> z;
    sort(all(weap));
    sort(all(arm));
    sort(all(monst));

    SegTree seg(m);
    rep(i, m)
        seg.leaf(i) = {-arm[i].second, 0};
    seg.build();

    auto it = begin(monst);
    ll mx = -INFL;
    for (auto [a, c] : weap) {
        while (it != end(monst) && (*it)[0] < a) {
            auto [_x, y, z] = *it++;
            auto it2 = upper_bound(all(arm), pi(y, INF));
            if (it2 != end(arm))
                seg.update(it2 - begin(arm), z);
        }
        mx = max(mx, -c + seg.root().first);
    }

    cout << mx << '\n';
    return 0;
}