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
        using T = ll;
        static constexpr T UNIT = 0;

        static T combine(const T& a, const T& b) { return a + b; }
        static T inv(const T& a, const T& b) { return a - b; }
        static bool pred(const T& pref, const T& val) { return pref >= val; }
    };

    using Fenwick = Fenwick_<FenwickConf>;
} using namespace snippets_fenwick;

const int MAX_T = 10'005;

struct BookSet {
    Fenwick cnt, sum;

    BookSet() : cnt(MAX_T), sum(MAX_T) {}

    void add(int t) {
        cnt.update(t, 1);
        sum.update(t, t);
    }

    void remove(int t) {
        cnt.update(t, -1);
        sum.update(t, -t);
    }

    int total() {
        return (int)cnt.query(MAX_T);
    }

    ll query(int c) {
        int i = cnt.bin_search(c);
        auto bef = cnt.query(i);
        return sum.query(i) + (c - bef) * i;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vpi both, alice, bob, none;
    rep(i, n) {
        int t, a, b; cin >> t >> a >> b;
        (a ? (b ? both : alice) : (b ? bob : none)).emplace_back(t, i);
    }
    sort(all(both)), sort(all(alice)), sort(all(bob)), sort(all(none));

    int mx_only = min({sz(alice), sz(bob), k});
    int mn_both = k - mx_only;
    if (mn_both > sz(both))
        cout << "-1\n", exit(0);

    ll sum_both = 0, sum_alice = 0, sum_bob = 0;
    rep(i, mn_both)
        sum_both += both[i].first;
    rep(i, mx_only)
        sum_alice += alice[i].first, sum_bob += bob[i].first;

    BookSet rem;
    reps(i, mn_both, sz(both))
        rem.add(both[i].first);
    reps(i, mx_only, sz(alice))
        rem.add(alice[i].first);
    reps(i, mx_only, sz(bob))
        rem.add(bob[i].first);
    trav(p, none)
        rem.add(p.first);

    pair<ll, int> mn = {INFL, 0};
    reps(i, mn_both, min(k, sz(both)) + 1) {
        int cnt = i + 2 * (k - i);
        if (cnt <= m && m - cnt <= rem.total()) {
            ll cost = sum_both + sum_alice + sum_bob + rem.query(m - cnt);
            mn = min(mn, pair(cost, i));
        }

        if (i < min(k, sz(both))) {
            rem.remove(both[i].first);
            sum_both += both[i].first;
            rem.add(alice[k - i - 1].first);
            sum_alice -= alice[k - i - 1].first;
            rem.add(bob[k - i - 1].first);
            sum_bob -= bob[k - i - 1].first;
        }
    }

    auto [cost, num_both] = mn;
    if (cost == INFL)
        cout << "-1\n", exit(0);

    cout << cost << '\n';
    set<pi> all;
    for (auto& c : {both, alice, bob, none})
        trav(b, c)
            all.emplace(b);
    vi idx;
    rep(i, num_both)
        idx.emplace_back(both[i].second), all.erase(both[i]);
    rep(i, k - num_both)
        idx.emplace_back(alice[i].second), all.erase(alice[i]);
    rep(i, k - num_both)
        idx.emplace_back(bob[i].second), all.erase(bob[i]);
    auto it = begin(all);
    rep(i, m - num_both - 2 * (k - num_both))
        idx.emplace_back(it++->second);

    trav(i, idx)
        cout << (i + 1) << ' ';
    cout << '\n';

    return 0;
}