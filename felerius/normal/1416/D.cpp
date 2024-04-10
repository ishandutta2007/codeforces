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
        using T = pi;
        using U = int;
        static constexpr T UNIT = {0, 0};

        static T combine(const T& l, const T& r) { return max(l, r); }
        static void update(T& v, U upd) { v.first = upd; }

        static bool pred(const T&, int) { return false; }
    };

    using SegTree = SegTree_<SegTreeConf>;
} using namespace snippets_segtree;

const int N = 200'005;
int enter[2 * N], exit_[2 * N];
vi euler;

int find(vi& dsu, int i) {
    return dsu[i] < 0 ? i : dsu[i] = find(dsu, dsu[i]);
}

void merge(vi& dsu, vvi& adj, int i, int j) {
    i = find(dsu, i), j = find(dsu, j);
    if (i != j) {
        int x = sz(dsu);
        dsu[i] = dsu[j] = x;
        dsu.emplace_back(-1);
        adj.emplace_back();
        adj.back() = {i, j};
    }
}

void dfs(int v, int n, vvi& adj) {
    enter[v] = sz(euler);
    if (v < n)
        euler.push_back(v);
    trav(v2, adj[v])
        dfs(v2, n, adj);
    exit_[v] = sz(euler);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;
    vi p(n);
    trav(pi, p) cin >> pi;
    vpi e(m);
    for (auto& [u, v] : e) cin >> u >> v, --u, --v;
    vpi qu(q);
    for (auto& [a, b] : qu) cin >> a >> b, --b;

    auto del = vector(m, false);
    for (auto& [a, b] : qu)
        if (a == 2)
            del[b] = true;

    vi dsu(n, -1);
    vvi adj(n);
    rep(i, m)
        if (!del[i])
            merge(dsu, adj, e[i].first, e[i].second);

    vi reprs;
    for (int i = q - 1; i >= 0; --i) {
        auto [t, j] = qu[i];
        if (t == 1)
            reprs.push_back(find(dsu, j));
        else
            merge(dsu, adj, e[j].first, e[j].second);
    }
    reverse(all(reprs));

    set<int> roots;
    rep(i, n)
        roots.emplace(find(dsu, i));
    adj.emplace_back(all(roots));
    dfs(sz(adj) - 1, n, adj);

    SegTree s(sz(euler));
    rep(i, sz(euler))
        s.leaf(i) = {p[euler[i]], i};
    s.build();

    trav(r, reprs) {
        auto [x, i] = s.query(enter[r], exit_[r]);
        s.update(i, 0);
        cout << x << '\n';
    }

    return 0;
}