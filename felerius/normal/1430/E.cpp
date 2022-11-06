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

namespace snippets_fenwick {
    template <class C> struct Fenwick_ : private C {
        using typename C::T; using C::UNIT; using C::combine; using C::inv; using C::pred;

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

        T query(int l, int r) const { // [l, r)
            return inv(query(r), query(l));
        }

        int bin_search(T val) const { // first pos s.t. prefix matches pred(q)
            int i = 0;
            for (int j = w; j; j /= 2)
                if (i + j <= sz(d) && !pred(d[i + j - 1], val))
                    i += j, val = inv(val, d[i - 1]);
            return i;
        }
    };

    struct FenwickConf {
        using T = int;
        static constexpr T UNIT = 0;

        static T combine(const T& a, const T& b) { return a + b; }
        static T inv(const T& a, const T& b) { return a - b; }
        static bool pred(const T& pref, const T& val) { return pref >= val; }
    };

    using Fenwick = Fenwick_<FenwickConf>;
} using namespace snippets_fenwick;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    vi target(n);
    for (auto c = 'a'; c <= 'z'; ++c) {
        vi idx, taridx;
        rep(i, n)
            if (s[i] == c)
                idx.push_back(i), taridx.push_back(n-1-i);
        reverse(all(taridx));
        rep(i, sz(idx))
            target[idx[i]] = taridx[i];
    }

    Fenwick left(n);
    ll swaps = 0;
    rep(i, n) {
        int to = target[i];
        swaps += left.query(to, n);
        left.update(to, 1);
    }

    cout << swaps << '\n';
    return 0;
}