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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
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
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
// endregion

namespace snippets_noninvfenwick {
    template <class C> struct Fenwick_ : private C {
        using typename C::T; using C::UNIT; using C::combine; using C::pred;

        int w = 1;
        vector<T> d;

        explicit Fenwick_(int n) : d(n, UNIT) {
            while (2 * w <= n) w *= 2;
        }

        void update(int i, T val) {
            for (; i < sz(d); i |= i + 1)
                d[i] = combine(d[i], val);
        }

        T query(int r) const { // [0, r)
            T res = UNIT;
            for (; r > 0; r &= r - 1)
                res = combine(res, d[r - 1]);
            return res;
        }

        int bin_search(T val) const { // first pos s.t. prefix matches pred(q)
            int i = 0, pref = UNIT;
            for (int j = w; j; j /= 2)
                if (i + j <= sz(d) && !pred(combine(pref, d[i + j - 1]), val))
                    i += j, pref = combine(pref, d[i - 1]);
            return i;
        }
    };

    struct FenwickConf {
        using T = int;
        static constexpr T UNIT = INF;
        static T combine(const T& a, const T& b) { return min(a, b); }
        static bool pred(const T& pref, const T& val) { return pref >= val; }
    };

    using Fenwick = Fenwick_<FenwickConf>;
} using namespace snippets_noninvfenwick;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vi s(n), c(n);
    trav(si, s) cin >> si;
    trav(ci, c) cin >> ci;

    vi sc = s;
    sort(all(sc));
    sc.erase(unique(all(sc)), end(sc));
    Fenwick f(sz(sc));

    int mn = INF;
    rep(i, n) {
        int ii = (int)(lower_bound(all(sc), s[i]) - begin(sc));
        reps(j, i+1, n)
            if (s[i] < s[j])
                mn = min(mn, f.query(ii) + c[i] + c[j]);
        f.update(ii, c[i]);
    }

    cout << (mn < INF ? mn : -1) << '\n';
    return 0;
}