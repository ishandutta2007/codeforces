// Good Graph (https://codeforces.com/contest/1555/problem/F)
#pragma GCC optimize("fast-math")
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define _choose(_1, _2, _3, x, ...)     x
#define _rep(i, l, r)                   for (int i = l; i < r; ++i)
#define _rep0(i, r)                     _rep(i, 0, r)
#define rep(...)                        _choose(__VA_ARGS__, _rep, _rep0, _)(__VA_ARGS__)
#define _repr(i, r, l, ...)             for (int i = r; i >= l; --i)
#define repr(...)                       _repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : b)

using namespace std;
namespace cp_lib {}

using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
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
// begin "cp-lib/ds/segtree/base.hpp"
// begin "_impl.hpp"
// begin "../../bit.hpp"
namespace cp_lib {
    template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
    template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
    template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }
}
// end "../../bit.hpp"

namespace cp_lib::_segtree_detail {
    template <class Derived, class Conf>
    struct SegmentTreeImpl {
     private:
        using T = typename Conf::T;

        void push(int i) { ((Derived*)this)->push(i); }

     protected:
        int n, k;
        vector<T> d;

        void push_path(int i) { repr(s, __builtin_ctz(k), 1) push(i >> s); }
        void recalc(int i) { d[i] = Conf::combine(d[2*i], d[2*i+1]); }

     public:
        explicit SegmentTreeImpl(int n_) : n(n_), k(1 << ceil_log2(n)), d(2 * k, Conf::UNIT) {}

        template <class Iter>
        SegmentTreeImpl(Iter it, Iter end) : n(int(end - it)), k(1 << ceil_log2(n)), d(2 * k, Conf::UNIT) {
            copy(it, end, begin(d) + k);
            build();
        }

        T& root() { return d[1]; }
        T& leaf(int i) { return d[k + i]; }

        // Width of the range represented by a node
        int width(int i) { return min(k >> floor_log2(i), n); }

        // Build the entire tree from the leaves up
        void build() { repr(i, k - 1, 1) recalc(i); }

        // Aggregate for [l, r)
        T query(int l, int r) {
            push_path(l + k);
            push_path(r + k - 1);
            T rl = Conf::UNIT, rr = Conf::UNIT;
            for (l += k, r += k; l < r; l /= 2, r /= 2) {
                if (l % 2) rl = Conf::combine(rl, d[l++]);
                if (r % 2) rr = Conf::combine(d[--r], rr);
            }
            return Conf::combine(rl, rr);
        }

        // Update single leaf value
        template <class F>
        void point_update(int i, F f) {
            push_path(i += k);
            f(d[i]);
            while (i /= 2) recalc(i);
        }

        // First position s.t. prefix matches pred
        template <class Pred>
        int lower_bound(Pred pred) {
            if (!pred(d[1])) return n;
            T pref = Conf::UNIT;
            int i = 1;
            while (i < k)
                if (push(i); !pred(Conf::combine(pref, d[i *= 2])))
                    pref = Conf::combine(pref, d[i++]);
            return i - k;
        }
    };
}
// end "_impl.hpp"

namespace cp_lib {
    template <class Conf>
    struct SegmentTree : _segtree_detail::SegmentTreeImpl<SegmentTree<Conf>, Conf> {
     private:
        using Base = _segtree_detail::SegmentTreeImpl<SegmentTree<Conf>, Conf>;
        friend Base;

        void push(int) {}

     public:
        using Base::Base;
    };
}
// end "cp-lib/ds/segtree/base.hpp"
// begin "cp-lib/graph/heavy-light-decomposition.hpp"
// begin "_detail.hpp"
namespace cp_lib {
    struct Identity {
        template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }
    };

    template <class A, class M>
    struct Graph {
        const A& adj;
        int n;
        M map;

        Graph(const A& adj_, int n_, M&& map_) : adj{adj_}, n{n_}, map{forward<M>(map_)} {}
        Graph(const A& adj_, M&& map_) : adj{adj_}, n{sz(adj)}, map{forward<M>(map_)} {}
        Graph(const A& adj_, int n_) : adj{adj_}, n{n_}, map{Identity{}} {}
        explicit Graph(const A& adj_) : adj{adj_}, n{sz(adj)}, map{Identity{}} {}
    };

    template <class A> Graph(const A&, int) -> Graph<A, Identity>;
    template <class A> Graph(const A&) -> Graph<A, Identity>;
}
// end "_detail.hpp"

namespace cp_lib {
    struct HeavyLightDecomposition {
     private:
        vector<int> size, depth, parent, top, idx, stack;

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
        template <class G>
        HeavyLightDecomposition(G&& graph, int root) {
            auto [adj, n, to] = Graph(forward<G>(graph));
            size = depth = idx = vector(n, 0);
            top = parent = vector(n, root);
            auto dfs_size = [&, &adj=adj, &to=to](int v, auto&& self) -> void {
                size[v] = 1;
                trav(e, adj[v])
                    if (to(e) != parent[v])
                        depth[to(e)] = depth[v] + 1, parent[to(e)] = v, self(to(e), self), size[v] += size[to(e)];
            };
            dfs_size(root, dfs_size);

            auto dfs_hld = [&, t=0, &adj=adj, &to=to](int v, auto&& self) mutable -> void {
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

struct SegTreeConf {
    using T = int;
    static constexpr T UNIT = 0;
    static T combine(const T& a, const T& b) { return a + b; }
};
using SegTree = SegmentTree<SegTreeConf>;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<array<int, 3>> queries(q);
    for (auto& [u, v, x] : queries)
        cin >> u >> v >> x, --u, --v;

    vector adj(n + 1, vector<int>());
    Dsu dsu(n);
    for (auto& [u, v, x] : queries)
        if (dsu.join(u, v))
            adj[u].push_back(v), adj[v].push_back(u);
    rep(v, n)
        if (dsu.find(v) == v)
            adj[n].push_back(v), adj[v].push_back(n);

    HeavyLightDecomposition hld(adj, n);
    SegTree seg_len(n), seg_marked(n);
    dsu = Dsu(n);
    for (auto& [u, v, x] : queries) {
        if (dsu.join(u, v)) {
            seg_len.point_update(hld.edge(u, v), [x=x](int& val) { val = x; });
            cout << "YES\n";
            continue;
        }

        int marked = 0;
        hld.decompose_edges(u, v, [&](int l, int r) {
            marked += seg_marked.query(l, r);
        });
        if (marked) {
            cout << "NO\n";
            continue;
        }

        int len = x;
        hld.decompose_edges(u, v, [&](int l, int r) {
            len += seg_len.query(l, r);
        });

        if (len % 2) {
            hld.decompose_edges(u, v, [&](int l, int r) {
                rep(i, l, r)
                    seg_marked.point_update(i, [&](int& val) { val = 1; });
            });
        }

        cout << (len % 2 ? "YES\n" : "NO\n");
    }
}