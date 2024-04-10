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
    vi avail, blockcnt;

    explicit SegTree(int n) : avail(4 * n), blockcnt(4 * n) {}

    int get(int i) { return avail[i] * (blockcnt[i] == 0); }

    void setavail(int i, int l, int r, int qi) {
        if (r - l == 1) {
            avail[i] = 1;
            return;
        }

        int m = (l + r) / 2;
        if (qi < m)
            setavail(2*i, l, m, qi);
        else
            setavail(2*i+1, m, r, qi);
        avail[i] = get(2*i) + get(2*i+1);
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            blockcnt[i] += val;
            return;
        }

        int m = (l + r) / 2;
        update(2*i, l, m, ql, qr, val);
        update(2*i+1, m, r, ql, qr, val);
        avail[i] = get(2*i) + get(2*i+1);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return 0;
        if (ql <= l && r <= qr)
            return get(i);

        int m = (l + r) / 2;
        return (blockcnt[i] == 0) * (query(2*i, l, m, ql, qr) + query(2*i+1, m, r, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi a(n);
    trav(ai, a) cin >> ai, --ai;

    vector<array<int, 4>> pos(n, array<int, 4>{n, n, n, n});
    int mn4 = n;
    SegTree s(n + 1);
    rep(i, n + 1)
        s.setavail(1, 0, n + 1, i);
    ll c = 0;
    for (int i = n - 1; i >= 0; --i) {
        auto& p = pos[a[i]];
        s.update(1, 0, n + 1, p[0] + 1, p[2] + 1, -1);
        rotate(begin(p), end(p) - 1, end(p));
        p[0] = i;
        s.update(1, 0, n + 1, p[0] + 1, p[2] + 1, 1);
        mn4 = min(mn4, p[3]);
        c += s.query(1, 0, n + 1, i + 1, mn4 + 1);
    }

    cout << c << '\n';
    return 0;
}