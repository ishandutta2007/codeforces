// Complete the MST (https://codeforces.com/contest/1508/problem/C)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"
// begin "cp-lib/ds/dsu/base.hpp"
namespace cp_lib {
    struct Dsu {
        vector<int> p;

        explicit Dsu(int n) : p(n, -1) {}

        int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
        bool same(int i, int j) { return find(i) == find(j); }
        int size(int i) { return -p[find(i)]; }
        bool join(int i, int j) {
            i = find(i), j = find(j);
            if (i == j) return false;
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
            return true;
        }
    };
}
// end "cp-lib/ds/dsu/base.hpp"
// begin "cp-lib/ds/fenwick.hpp"
// begin "../bit.hpp"
namespace cp_lib {
    template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
    template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
    template <class T> constexpr inline int ceil_log2(T n) { return floor_log2(n) + !is_pow2(n); }
}
// end "../bit.hpp"

namespace cp_lib {
    template <class Conf>
    struct NonInvFenwickTree {
        using T = typename Conf::T;

        int w;
        vector<T> d;

        explicit NonInvFenwickTree(int n) : w(1 << floor_log2(n)), d(n, Conf::UNIT) {}

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
            Base::w = 1 << floor_log2(sz(a));
            Base::d = move(a);
        }

     public:
        using Base::Base;
        using Base::query;

        // O(n) construction from values
        explicit FenwickTree(vector<T> a) : Base(0) { build(a); }

        // O(n) construction from values
        template <class Iter>
        FenwickTree(Iter it, Iter end) : Base(0) { build(vector<T>(it, end)); }

        // aggregate of [l, r)
        T query(int l, int r) const { return Conf::sub(query(r), query(l)); }
    };
}
// end "cp-lib/ds/fenwick.hpp"
// begin "cp-lib/graph/heavy-light-decomposition.hpp"
namespace cp_lib {
    struct HeavyLightDecomposition {
     private:
        vector<int> size, depth, parent, top, idx, stack;

        template <class C, class To>
        void init(const vector<C>& adj, int root, To&& to) {
            size = depth = parent = top = idx = vector(sz(adj), 0);
            auto dfs_size = [&](int v, auto&& self) -> void {
                size[v] = 1;
                trav(e, adj[v])
                    if (to(e) != parent[v])
                        depth[to(e)] = depth[v] + 1, parent[to(e)] = v, self(to(e), self), size[v] += size[to(e)];
            };
            dfs_size(root, dfs_size);

            int t = 0;
            auto dfs_hld = [&](int v, auto&& self) -> void {
                idx[v] = t++;
                auto it_heavy = find_if(all(adj[v]), [&](auto& e) {
                    return to(e) != parent[v] && 2 * size[to(e)] > size[v];
                });
                if (it_heavy != end(adj[v]))
                    top[to(*it_heavy)] = top[v], self(to(*it_heavy), self);
                for (auto it = begin(adj[v]); it != end(adj[v]); ++it)
                    if (it != it_heavy && to(*it) != parent[v])
                        top[to(*it)] = to(*it), self(to(*it), self);
            };
            parent[root] = -1;
            dfs_hld(root, dfs_hld);
        }

        template <bool Edges, class F>
        void decomp(int u, int v, F&& f) const {
            for (; top[u] != top[v]; v = parent[top[v]]) {
                if (depth[top[u]] > depth[top[v]]) swap(u, v);
                f(idx[top[v]] - Edges, idx[v] + !Edges);
            }
            f(min(idx[u], idx[v]), max(idx[u], idx[v]) + !Edges);
        }

        template <bool Edges, class F>
        void decomp_noncom(int u, int v, F&& f) {
            while (top[u] != top[v]) {
                if (depth[top[u]] > depth[top[v]])
                    f(idx[top[u]] - Edges, idx[u] + !Edges, true), u = parent[top[u]];
                else
                    stack.push_back(v), v = parent[top[v]];
            }
            f(min(idx[u], idx[v]), max(idx[u], idx[v]) + !Edges, depth[u] > depth[v]);
            while (sz(stack))
                f(idx[top[stack.back()]] - Edges, idx[stack.back()] + !Edges, false), stack.pop_back();
        }

     public:
        template <class C, class To>
        HeavyLightDecomposition(const vector<C>& adj, int root, To&& to) { init(adj, root, forward<To>(to)); }
        template <class C>
        HeavyLightDecomposition(const vector<C>& adj, int root) { init(adj, root, [](int v) { return v; }); }

        int node(int v) const { return idx[v]; }
        int edge(int u, int v) const { return max(idx[u], idx[v]) - 1; }
        pair<int, int> subtree(int v) const { return {idx[v], idx[v] + size[v]}; }
        pair<int, int> subtree_edges(int v) const { return {idx[v], idx[v] + size[v] - 1}; }

        template <class F> void decompose(int u, int v, F&& f) const { decomp<false>(u, v, forward<F>(f)); }
        template <class F> void decompose_edges(int u, int v, F&& f) const { decomp<true>(u, v, forward<F>(f)); }
        template <class F> void decompose_noncommutative(int u, int v, F&& f) { decomp_noncom<false>(u, v, forward<F>(f)); }
        template <class F> void decompose_edges_noncommutative(int u, int v, F&& f) { decomp_noncom<true>(u, v, forward<F>(f)); }

        int lca(int u, int v) const {
            for (; top[u] != top[v]; v = parent[top[v]])
                if (depth[top[u]] > depth[top[v]]) swap(u, v);
            return depth[u] < depth[v] ? u : v;
        }
    };
}
// end "cp-lib/graph/heavy-light-decomposition.hpp"

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

    int n, m; cin >> n >> m;
    vector<array<int, 3>> e(m);
    int xor_full = 0;
    vector adj(n, set<int>());
    for (auto& [u, v, w] : e)
        cin >> u >> v >> w, --u, --v, xor_full ^= w, adj[u].emplace(v), adj[v].emplace(u);

    Dsu dsu(n);
    vector treeadj(n, vector<int>());
    vector not_done(n, 0);
    int zero_in_mst = 0;
    iota(all(not_done), 0);
    while (sz(not_done)) {
        int v0 = not_done.back();
        not_done.pop_back();
        queue<int> q{{v0}};
        while (sz(q)) {
            int v = q.front(); q.pop();
            int i = 0;
            while (i < sz(not_done)) {
                int v2 = not_done[i];
                if (adj[v].find(v2) == end(adj[v])) {
                    dsu.join(v, v2);
                    treeadj[v].push_back(v2);
                    treeadj[v2].push_back(v);
                    ++zero_in_mst;

                    q.push(v2);
                    swap(not_done[i], not_done.back());
                    not_done.pop_back();
                } else {
                    ++i;
                }
            }
        }
    }

    sort(all(e), [&](auto& e1, auto& e2) { return e1[2] < e2[2]; });
    ll mst = 0;
    decltype(e) rem_e;
    for (auto& [u, v, w] : e) {
        if (dsu.join(u, v)) {
            treeadj[u].push_back(v);
            treeadj[v].push_back(u);
            mst += w;
        } else
            rem_e.push_back({u, v, w});
    }

    if (m + zero_in_mst < ll(n) * (n - 1) / 2)
        cout << mst << '\n', exit(0);

    HeavyLightDecomposition hld(treeadj, 0);
    Fenwick f(n - 1);
    rep(v, n)
        trav(u, treeadj[v])
            if (adj[v].find(u) == end(adj[v]))
                f.update(hld.edge(u, v), 1);

    reverse(all(rem_e));
    while (sz(rem_e) && rem_e.back()[2] < xor_full) {
        auto [u, v, w] = rem_e.back();
        rem_e.pop_back();

        int has_zero = 0;
        hld.decompose_edges(u, v, [&](int l, int r) {
            has_zero += f.query(l, r);
        });

        if (has_zero)
            cout << (mst + w) << '\n', exit(0);
    }


    cout << (mst + xor_full) << '\n';
    return 0;
}