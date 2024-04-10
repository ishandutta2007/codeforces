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

int sgn(int i) {
    return i < 0 ? -1 : 1;
}

struct SegTree {
    struct Streak {
        int mx = 0, w = 0;

        pi left, right;

        bool full() {
            return left.first + left.second == w;
        }
    };

    Streak combine(Streak& l, Streak& r) {
        if (l.w == 0) return r;
        if (r.w == 0) return l;
        Streak res;
        res.w = l.w + r.w;
        res.mx = max(l.mx, r.mx);
        res.left = l.left;
        res.right = r.right;

        if (l.right.second == 0 || r.left.first == 0) {
            pi mid = {l.right.first + r.left.first, l.right.second + r.left.second};
            res.mx = max(res.mx, mid.first + mid.second);
            if (l.full())
                res.left = mid;
            if (r.full())
                res.right = mid;
        }

        return res;
    }

    int k = 1;
    vector<pair<Streak, Streak>> d;
    vector<bool> rev;

    explicit SegTree(int n) {
        while (k <= n) k *= 2;
        d.resize(2 * k);
        rev.resize(2 * k);
    }

    pair<Streak, Streak>& root() { return d[1]; }
    pair<Streak, Streak>& leaf(int i) { return d[k + i]; }

    void recalc(int i) {
        d[i].first = combine(d[2*i].first, d[2*i+1].first);
        d[i].second = combine(d[2*i].second, d[2*i+1].second);
    }

    void build() {
        for (int i = k - 1; i; --i)
            recalc(i);
    }

    void toggle_rev(int i) {
        rev[i] = !rev[i];
        swap(d[i].first, d[i].second);
    }

    void push(int i) {
        if (!rev[i]) return;
        toggle_rev(2 * i);
        toggle_rev(2 * i + 1);
        rev[i] = false;
    }

    void reverse(int i, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            toggle_rev(i);
            return;
        }

        push(i);
        int m = (l + r) / 2;
        reverse(2 * i, l, m, ql, qr);
        reverse(2 * i + 1, m, r, ql, qr);
        recalc(i);
    }
    void reverse(int l, int r) { reverse(1, 0, k, l, r); }

    pair<Streak, Streak> query(int i, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return pair(Streak{}, Streak{});
        if (ql <= l && r <= qr)
            return d[i];

        push(i);
        int m = (l + r) / 2;
        auto [l1, l2] = query(2 * i, l, m, ql, qr);
        auto [r1, r2] = query(2 * i + 1, m, r, ql, qr);
        return {combine(l1, r1), combine(l2, r2)};
    }
    pair<Streak, Streak> query(int l, int r) { return query(1, 0, k, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    string s_; cin >> s_;

    SegTree::Streak left, right;
    left.w = right.w = 1;
    left.mx = right.mx = 1;
    left.left = left.right = {0, 1};
    right.left = right.right = {1, 0};

    SegTree s(n);
    rep(i, n) {
        if (s_[i] == '<')
            s.leaf(i) = {left, right};
        else
            s.leaf(i) = {right, left};
    }
    s.build();

    while (q--) {
        int l, r; cin >> l >> r; --l;
        s.reverse(l, r);
        cout << s.query(l, r).first.mx << '\n';
    }

    return 0;
}