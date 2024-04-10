// Contest: Codeforces Round #620 (Div. 2) (https://codeforces.com/contest/1304)
// Problem: F2: Animal Observation (hard version) (https://codeforces.com/contest/1304/problem/F2)


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

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

struct SegTree {
    int k;
    vl mx, add;

    explicit SegTree(vl& v) : k(1) {
        while (k < sz(v))
            k *= 2;
        mx.resize(2 * k, -INFL), add.resize(2 * k);
        rep(i, sz(v))
            mx[k + i] = v[i];
        for (int i = k - 1; i; --i)
            mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    }

    void push(int i) {
        for (int j : {2 * i, 2 * i + 1})
            add[j] += add[i], mx[j] += add[i];
        add[i] = 0;
    }

    ll query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return mx[i];
        if (qr <= l || r <= ql)
            return -INFL;
        int m = (r + l) / 2;
        push(i);
        return max(query(2 * i, l, m, ql, qr), query(2 * i + 1, m, r, ql, qr));
    }
    ll query(int l, int r) { return query(1, 0, k, l, r); }

    void update(int i, int l, int r, int ql, int qr, ll diff) {
        if (ql <= l && r <= qr) {
            add[i] += diff, mx[i] += diff;
            return;
        }
        if (qr <= l || r <= ql)
            return;
        int m = (r + l) / 2;
        push(i);
        update(2 * i, l, m, ql, qr, diff);
        update(2 * i + 1,m, r, ql, qr, diff);
        mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    }
    void update(int l, int r, ll diff) { update(1, 0, k, l, r, diff); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<vl> d(n + 1, vl(m));
    rep(i, n) trav(v, d[i]) cin >> v;
    rep(i, n) reps(j, 1, m) d[i][j] += d[i][j-1];
    auto range = [&](int i, int l, int r) { return d[i][r-1] - (l ? d[i][l-1] : 0); };

    int w = m - k + 1;
    vl dp(w);
    rep(i, w)
        dp[i] = range(0, i, i + k) + range(1, i, i + k);

    reps(i, 1, n) {
        SegTree s(dp);
        rep(j, k)
            s.update(0, j + 1, -range(i, j, j + 1));
        rep(j, w) {
            dp[j] = s.query(0, w) + range(i, j, j + k) + range(i + 1, j, j + k);
            s.update(max(0, j - k + 1), j + 1, range(i, j, j + 1));
            if (j + k < m)
                s.update(j + 1, min(w, j + 1 + k), -range(i, j + k, j + k + 1));
        }
    }

    cout << *max_element(all(dp)) << '\n';
    return 0;
}