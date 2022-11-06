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

namespace snippets_segtree {
    template <class C> struct SegTree_ : private C {
        using typename C::T; using typename C::U; using C::UNIT; using C::combine;

        int n, k = 1;
        vector<T> d;

        explicit SegTree_(int n) : n(n) {
            while (k < n) k *= 2;
            d = vector(2 * k, UNIT);
        }

        T& root() { return d[1]; }
        T& leaf(int i) { return d[k + i]; }

        void build() {
            for (int i = k - 1; i; --i)
                d[i] = combine(d[2*i], d[2*i + 1]);
        }

        void update(int i, U upd) {
            C::update(d[i + k], upd);
            for (int j = i + k; j /= 2;)
                d[j] = combine(d[2*j], d[2*j+1]);
        }

        T query(int l, int r) const { // [l, r)
            T rl = UNIT, rr = UNIT;
            for (l += k, r += k; l < r; l /= 2, r /= 2) {
                if (l % 2) rl = combine(rl, d[l++]);
                if (r % 2) rr = combine(d[--r], rr);
            }
            return combine(rl, rr);
        }

        template <class Q> int bin_search(Q q) const { // first pos s.t. prefix matches pred(q)
            if (!C::pred(d[1], q)) return n;
            T pref = UNIT; int i = 1;
            while (i < k)
                if (!C::pred(combine(pref, d[i *= 2]), q))
                    pref = combine(pref, d[i++]);
            return i - k;
        }
    };

    struct SegTreeConf {
        using T = array<array<ll, 2>, 2>;
        using U = int;
        static constexpr T UNIT = {array<ll, 2>{0, -INFL}, array<ll, 2>{-INFL, 0}};

        static T combine(const T& l, const T& r) {
            T res{};
            res[0][0] = max(l[0][0] + r[0][0], l[0][1] + r[1][0]);
            res[0][1] = max(l[0][0] + r[0][1], l[0][1] + r[1][1]);
            res[1][0] = max(l[1][0] + r[0][0], l[1][1] + r[1][0]);
            res[1][1] = max(l[1][0] + r[0][1], l[1][1] + r[1][1]);
            return res;
        }
        static void update(T& v, U upd) {
            v = T();
            v[0][1] = upd;
            v[1][0] = -upd;
        }

        static bool pred(const T&, int) { return false; }
    };

    using SegTree = SegTree_<SegTreeConf>;
} using namespace snippets_segtree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vi a(n);
        trav(ai, a) cin >> ai;

        SegTree s(n);
        rep(i, n)
            s.update(i, a[i]);

        auto print = [&]() {
            auto ans = s.query(0, n);
            cout << max(ans[0][0], ans[0][1]) << '\n';
        };
        print();

        while (q--) {
            int l, r; cin >> l >> r; --l, --r;
            swap(a[l], a[r]);
            s.update(l, a[l]);
            s.update(r, a[r]);
            print();
        }
    }

    return 0;
}