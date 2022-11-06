// Two Editorials (https://codeforces.com/contest/1452/problem/E)

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

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}


namespace cp_lib {
    template <class Conf>
    struct NonInvFenwickTree {
        using T = typename Conf::T;

        int w = 1;
        vector<T> d;

        explicit NonInvFenwickTree(int n) : d(n, Conf::UNIT) {
            while (2 * w <= n) w *= 2;
        }

        // add val to a[i]
        void update(int i, T val) {
            for (; i < sz(d); i |= i + 1)
                d[i] = Conf::add(d[i], val);
        }

        // aggregate of [0, r)
        T query(int r) const {
            T res = Conf::UNIT;
            for (; r > 0; r &= r - 1)
                res = Conf::add(res, d[r - 1]);
            return res;
        }

        // find first index s.t. prefix aggregate fulfills pred
        template <class Pred>
        int lower_bound(Pred pred) const {
            int i = 0;
            T pref = Conf::UNIT;
            for (int j = w; j; j /= 2)
                if (i + j <= sz(d) && !pred(Conf::add(pref, d[i + j - 1])))
                    pref = Conf::add(pref, d[i + j - 1]), i += j;
            return i;
        }
    };

    template <class Conf>
    struct FenwickTree : public NonInvFenwickTree<Conf> {
     private:
        using Base = NonInvFenwickTree<Conf>;
        using typename Base::T;

        void build(vector<T> a) {
            partial_sum(all(a), begin(a), Conf::add);
            repr(i, sz(a), 1)
                if (i & (i - 1))
                    a[i-1] = Conf::sub(a[i-1], a[(i & (i - 1)) - 1]);
            this->w = 1;
            while (2 * this->w <= sz(a)) this->w *= 2;
            this->d = move(a);
        }

     public:
        using Base::Base;
        using Base::query;

        // O(n) construction from values
        explicit FenwickTree(vector<T> a) : Base(0) {
            build(a);
        }

        // O(n) construction from values
        template <class Iter>
        FenwickTree(Iter it, Iter end) : Base(0) {
            build(vector<T>(it, end));
        }

        // aggregate of [l, r)
        T query(int l, int r) const {
            return Conf::sub(query(r), query(l));
        }
    };
}

using namespace cp_lib;

struct FenwickConf {
    using T = int;
    static constexpr T UNIT = 0;
    static T add(const T& a, const T& b) { return a + b; }
    static T sub(const T& a, const T& b) { return a - b; }
};
using Fenwick = FenwickTree<FenwickConf>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> stud(m);
    for (auto& [l, r] : stud)
        cin >> l >> r, --l;

    int mx = 0;
    rep(i, n) {
        int guaranteed = 0;
        vector<int> changes(3 * n);
        for (auto [l, r] : stud) {
            int over = max(0, min(i + k, r) - max(i, l));
            guaranteed += over;
            if (over == r - l || over == k)
                continue;
            changes[l - k + over + n]++;
            changes[r - k + n]--;
            changes[l + n]--;
            changes[r + n - over]++;
        }

        int slope = 0, val = 0;
        rep(j, -n, 2 * n) {
            slope += changes[j + n];
            val += slope;
            if (0 <= j && j < n)
                mx = max(mx, guaranteed + val);
        }
}

    cout << mx << '\n';
    return 0;
}