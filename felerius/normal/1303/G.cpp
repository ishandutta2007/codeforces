#pragma GCC optimize("fast-math")
// begin "cp-lib/prelude.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define cp_lib_4th(_1, _2, _3, x, ...)  x
#define cp_lib_rep(i, l, r)             for (int i = (l); (i) < (r); ++(i))
#define cp_lib_rep0(i, r)               cp_lib_rep(i, 0, r)
#define rep(...)                        cp_lib_4th(__VA_ARGS__, cp_lib_rep, cp_lib_rep0, _)(__VA_ARGS__)
#define cp_lib_repr(i, r, l, ...)       for (int i = (r); (i) >= (l); --(i))
#define repr(...)                       cp_lib_repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : (b))

using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/prelude.hpp"
// begin "cp-lib/io.hpp"
// begin "_assert.hpp"
#ifdef CP_LIB_DEBUG
#define cp_lib_assert(expr) \
    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << #expr << " (" << __FILE__ << ':' << __LINE__ << ")\n"; \
        ::abort(); \
    } } while (0)
#else
#define cp_lib_assert(expr)
#endif
// end "_assert.hpp"
// begin "_type-meta.hpp"
#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif

namespace cp_lib_type_meta {
    struct NoOp { template <class... Args> void operator()(Args&&...) const noexcept {} };
    template <class T, class = void> struct is_tuple_like : false_type {};
    template <class T> struct is_tuple_like<T, void_t<tuple_element_t<0, T>>> : true_type {};
}
// end "_type-meta.hpp"
// begin "modint/_detect.hpp"
namespace cp_lib_modint { struct ModIntTag {}; }
// end "modint/_detect.hpp"
#include <unistd.h>

namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T> struct is_std_array : false_type {};
    template <class T, size_t I> struct is_std_array<array<T, I>> : true_type {};

    void flush() { write(STDOUT_FILENO, begin(obuf), optr - begin(obuf)); optr = begin(obuf); }
    void ensure_write(int l) { if (end(obuf) - optr < l) flush(); }
    int _flush_atexit = []{ atexit(flush); return 0; }();
    void refill() {
        memmove(begin(ibuf), iptr, iend - iptr);
        iend -= iptr - begin(ibuf);
        iptr = begin(ibuf);
        iend += read(STDIN_FILENO, iend, end(ibuf) - iend);
    }
    void skip_ensure_read(int l) {
        do {
            while (iptr != iend && *iptr <= ' ') ++iptr;
            if (iend - iptr < l) refill();
        } while (*iptr <= ' ');
    }

    template <class T, class T2 = remove_reference_t<remove_cv_t<T>>>
    void print(T&& val) {
        if constexpr (is_same_v<T2, char>)
            ensure_write(2), *optr++ = val;
        else if constexpr (is_integral_v<T2> && !is_same_v<T2, bool>) {
            ensure_write(numeric_limits<T>::digits10 + 1 + is_signed_v<T2>);
            if (val < 0) { *optr++ = '-'; print(make_unsigned_t<T2>(-make_unsigned_t<T2>(val))); return; }
            array<char, 128> tmp;
            char* tptr = end(tmp);
            remove_const_t<T2> val_copy = val;
            do { *--tptr = char('0' + val_copy % 10), val_copy /= 10; } while (val_copy);
            memcpy(optr, tptr, end(tmp) - tptr);
            optr += end(tmp) - tptr;
#if __cpp_lib_to_chars >= 201611
        } else if constexpr (is_floating_point_v<T2>) {
            ensure_write(64);
            auto res = to_chars(optr, end(obuf), val, chars_format::fixed, 30);
            cp_lib_assert(res.ec == errc());
            optr = res.ptr;
#endif
        } else if constexpr (is_convertible_v<T, string_view>) {
            string_view sv(val);
            if (sz(sv) + 1 <= end(obuf) - optr)
                memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
            else
                flush(), write(STDOUT_FILENO, data(sv), sz(sv));
        } else {
            if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
                print(int(val));
            else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T2>)
                print(decltype(T2::mod())(val));
            else if constexpr (cp_lib_type_meta::is_tuple_like<T2>() && !is_std_array<T2>())
                apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
            else
                trav(item, val) print(item);
            return;
        }
        *optr++ = ' ';
    }

    template <class T>
    void read(T& val) {
        if constexpr (is_same_v<T, char>)
            skip_ensure_read(1), val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            uint8_t ival; read(ival), val = bool(ival);
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>) {
            ll ival; read(ival); val = T(ival);
        } else if constexpr (is_integral_v<T>) {
            skip_ensure_read(numeric_limits<T>::digits10 + 1 + is_signed_v<T>);
            if (is_signed_v<T> && *iptr == '-') {
                ++iptr;
                make_unsigned_t<T> uval;
                read(uval);
                val = T(-uval);
            } else {
                val = 0;
                while (iptr != iend && *iptr > ' ') val = T(10 * val + (*iptr++ - '0'));
            }
#if __cpp_lib_to_chars >= 201611
        } else if constexpr (is_floating_point_v<T>) {
            skip_ensure_read(128);
            auto res = from_chars(iptr, iend, val);
            assert(res.ec == errc());
            iptr = const_cast<char*>(res.ptr);
#endif
        } else if constexpr (is_same_v<T, string>) {
            val = string();
            skip_ensure_read(1);
            do {
                auto* after = iptr;
                while (after != iend && *after > ' ') ++after;
                copy(iptr, after, back_inserter(val));
                if ((iptr = after) == iend)
                    refill();
                else
                    break;
            } while (iptr != iend);
        } else if constexpr (cp_lib_type_meta::is_tuple_like<T>() && !is_std_array<T>())
            apply([](auto&... items) { (read(items), ...); }, val);
        else
            trav(item, val) read(item);
    }
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
    if (sizeof...(Args) > 0)
        (cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
    else
        cp_lib_io::ensure_write(1), *cp_lib_io::optr++ = '\n';
}

template <class... Args>
void printlns(Args&&... args) {
    ((cp_lib_io::print(forward<Args>(args)), *(cp_lib_io::optr - 1) = '\n'), ...);
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }
// end "cp-lib/io.hpp"
// begin "cp-lib/graph/centroid-decomposition.hpp"
// begin "_detail.hpp"
template <class A, class M>
struct Graph {
    const A& adj;
    int n;
    M map;

    Graph(const A& adj_, int n_, M&& map_) : adj{adj_}, n{n_}, map{forward<M>(map_)} {}
    Graph(const A& adj_, M&& map_) : adj{adj_}, n{sz(adj)}, map{forward<M>(map_)} {}
    Graph(const A& adj_, int n_) : adj{adj_}, n{n_}, map{identity{}} {}
    explicit Graph(const A& adj_) : adj{adj_}, n{sz(adj)}, map{identity{}} {}
};

template <class A> Graph(const A&, int) -> Graph<A, identity>;
template <class A> Graph(const A&) -> Graph<A, identity>;
// end "_detail.hpp"

template <class G, class F>
void centroid_decomposition(G&& graph, F&& f) {
    auto [adj, n, to] = Graph(forward<G>(graph));
    vector size(n, 1);
    auto size_dfs = [&, &adj=adj, &to=to](int v, int p, auto&& self) -> void {
        trav(e, adj[v])
            if (to(e) != p)
                self(to(e), v, self), size[v] += size[to(e)];
    };
    size_dfs(0, -1, size_dfs);

    vector del(n, false);
    auto decomp_dfs = [&, &adj=adj, &to=to](int v, auto&& self) -> void {
        while (true) {
            auto it = find_if(all(adj[v]), [&](auto& e) { return !del[to(e)] && 2 * size[to(e)] > size[v]; });
            if (it == end(adj[v])) break;
            size[v] -= size[to(*it)];
            size[to(*it)] += size[v];
            v = to(*it);
        }

        f(v, [&](int vi) { return del[vi]; });

        del[v] = true;
        trav(e, adj[v])
            if (!del[to(e)])
                self(to(e), self);
    };
    decomp_dfs(0, decomp_dfs);
}
// end "cp-lib/graph/centroid-decomposition.hpp"
// begin "cp-lib/data-structure/li-chao/dynamic.hpp"
template <class Conf>
struct DynamicLiChaoTree {
    using T = typename Conf::T;
    using Func = typename Conf::Func;
    struct Node { int l, r; Func f; };

    vector<Node> d;
    int root = -1;

    int insert(int v, Func f, T l, T r) {
        if (v == -1) {
            d.push_back(Node{-1, -1, f});
            return sz(d) - 1;
        }
        T m = (l + r) / 2;
        bool left = Conf::cmp(f, d[v].f, l), mid = Conf::cmp(f, d[v].f, m);
        if (mid) swap(d[v].f, f);
        if (r - l <= Conf::EPS) return v;
        if (left != mid)
            d[v].l = insert(d[v].l, f, l, m);
        else
            d[v].r = insert(d[v].r, f, m, r);
        return v;
    }

    int insert_segment(int v, Func f, T l, T r, T fl, T fr) {
        if (fr <= l || r <= fl) return v;
        if ((fl <= l && r <= fr) || r - l <= Conf::EPS) return insert(v, f, l, r);
        if (v == -1)
            v = sz(d), d.push_back(Node{-1, -1, Conf::UNIT});
        T m = (l + r) / 2;
        d[v].l = insert_segment(d[v].l, f, l, m, fl, fr);
        d[v].r = insert_segment(d[v].r, f, m, r, fl, fr);
        return v;
    }

    Func query(int v, T x, T l, T r) const {
        if (v == -1) return Conf::UNIT;
        if (r - l <= Conf::EPS) return d[v].f;
        T m = (l + r) / 2;
        Func below = (x < m ? query(d[v].l, x, l, m) : query(d[v].r, x, m, r));
        return (Conf::cmp(d[v].f, below, x) ? d[v].f : below);
    }

    void insert(Func f) { root = insert(root, f, Conf::MIN, Conf::MAX + Conf::EPS); }
    template <class U=T> enable_if_t<!is_floating_point_v<U>> insert_segment(Func f, T l, T r) {
        root = insert_segment(root, f, Conf::MIN, Conf::MAX + Conf::EPS, l, r);
    }
    Func query(T x) const { return query(root, x, Conf::MIN, Conf::MAX + Conf::EPS); }
};
// end "cp-lib/data-structure/li-chao/dynamic.hpp"

struct LiChaoConf {
    using T = ll;
    struct Func {
        ll a, b;
        ll eval(ll x) const { return a * x + b; }
    };
    static constexpr Func UNIT = {0, -INFL};
    static constexpr T MIN = -INF, MAX = INF, EPS = 1;
    static bool cmp(const Func& f1, const Func& f2, T x) { return f1.eval(x) > f2.eval(x); }
};
using LiChao = DynamicLiChaoTree<LiChaoConf>;

int main() {
    int n; read(n);
    vector adj(n, vector<int>());
    rep(_, n - 1) {
        int u, v; read(u, v); --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector a(n, 0);
    read(a);

    vector depth(n, 0), nodes(0, 0);
    vector sum(n, 0ll), tria_down(n, 0ll), tria_up(n, 0ll);
    ll mx = 0;
    centroid_decomposition(adj, [&](int vc, auto&& is_del) {
        LiChao lc_f, lc_g;
        sum[vc] = tria_down[vc] = tria_up[vc] = depth[vc] = 0;
        lc_f.insert({1, a[vc]});
        lc_g.insert({a[vc], a[vc]});

        trav(vn, adj[vc]) {
            if (is_del(vn))
                continue;

            nodes.clear();
            auto dfs = [&](int v, int p, auto&& self) -> void {
                depth[v] = depth[p] + 1;
                sum[v] = sum[p] + a[v];
                tria_down[v] = tria_down[p] + ll(a[v]) * depth[v];
                tria_up[v] = tria_up[p] + sum[p] + a[v];
                nodes.push_back(v);

                trav(v2, adj[v])
                    if (v2 != p && !is_del(v2))
                        self(v2, v, self);
            };
            dfs(vn, vc, dfs);

            trav(v, nodes) {
                ll u_to_v = lc_f.query(sum[v]).eval(sum[v]) + tria_down[v];
                ll v_to_u = lc_g.query(depth[v]).eval(depth[v]) + tria_up[v];
                mx = max({mx, u_to_v, v_to_u});
            }

            trav(v, nodes) {
                lc_f.insert({depth[v] + 1, tria_up[v] + ll(depth[v] + 1) * a[vc]});
                lc_g.insert({sum[v] + a[vc], tria_down[v] + sum[v] + a[vc]});
            }
        }
    });

    println(mx);
}