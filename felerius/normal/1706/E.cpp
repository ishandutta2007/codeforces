// Qpwoeirut and Vertices (https://codeforces.com/contest/1706/problem/E)
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>
#if __has_include("dbg.h")
#  include "dbg.h"
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



#if __cpp_lib_remove_cvref < 201711L
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif
#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using iter_value_t = typename iterator_traits<remove_cvref_t<T>>::value_type;
#endif

namespace cp_lib_type_meta {
    template <class T, class = void> constexpr bool is_tuple_like = false;
    template <class T> constexpr bool is_tuple_like<T, void_t<tuple_element_t<0, T>>> = true;
}


namespace cp_lib_modint { struct ModIntTag {}; }
template <class T> constexpr bool IsModInt = is_base_of_v<cp_lib_modint::ModIntTag, T>;
#include <unistd.h>

namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    constexpr array<array<char, 4>, 10'000> DIGITS = []{
        array<array<char, 4>, 10'000> digits{};
        for (int i = 3, d = 1; i >= 0; --i, d *= 10)
            rep(j, 10'000)
                digits[j][i] = char('0' + j / d % 10);
        return digits;
    }();
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T> constexpr bool is_std_array = false;
    template <class T, size_t I> constexpr bool is_std_array<array<T, I>> = true;

    void flush() {
        for (auto* p = begin(obuf); p != optr; p += write(STDOUT_FILENO, p, optr - p));
        optr = begin(obuf);
    }
    int _flush_atexit = []{ atexit(flush); return 0; }();

    void refill() {
        memmove(begin(ibuf), iptr, iend - iptr);
        iend -= iptr - begin(ibuf);
        iptr = begin(ibuf);
        iend += read(STDIN_FILENO, iend, end(ibuf) - 1 - iend);
        *iend = '\0';
    }

    template <class T, class T2 = remove_cvref_t<T>>
    void print(T&& val) {
        if (end(obuf) - optr < 64)
            flush();

        if constexpr (is_same_v<T2, char>)
            *optr++ = val;
        else if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
            return print(int(val));
        else if constexpr (is_integral_v<T2> && is_signed_v<T2>) {
            if (val < 0)
                *optr++ = '-';
            using U = make_unsigned_t<T2>;
            return print(U(val < 0 ? -U(val) : U(val)));
        } else if constexpr (is_integral_v<T2> && is_unsigned_v<T2>) {
            T2 val2 = val;
            array<char, 64> tmp;
            char* tptr = end(tmp);
            while (val2 >= 10'000)
                tptr -= 4, memcpy(tptr, &DIGITS[val2 % 10'000][0], 4), val2 /= T2(10'000);
            int d = (val2 >= 100 ? (val2 >= 1000 ? 4 : 3) : (val2 >= 10 ? 2 : 1));
            memcpy(optr, &DIGITS[val2][4 - d], d);
            memcpy(optr + d, tptr, end(tmp) - tptr);
            optr += d + int(end(tmp) - tptr);
        } else if constexpr (is_floating_point_v<T2>)
            optr += sprintf(optr, "%.30Lf", (long double)val);
        else if constexpr (is_convertible_v<T, string_view>) {
            string_view sv(val);
            if (sz(sv) + 1 <= end(obuf) - optr)
                memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
            else {
                flush();
                for (auto *p = data(sv), *pe = p + sz(sv); p != pe; p += write(STDOUT_FILENO, p, pe - p));
            }
        } else if constexpr (IsModInt<T2>)
            return print(typename T2::Int(val));
        else if constexpr (cp_lib_type_meta::is_tuple_like<T2> && !is_std_array<T2>)
            return apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
        else {
            trav(item, val)
                print(item);
            return;
        }
        *optr++ = ' ';
    }

    template <class T>
    void read(T& val) {
        auto skip_ws = [] {
            do {
                for (; iptr != iend && *iptr <= ' '; ++iptr);
                if (iend - iptr < 64)
                    refill();
            } while (*iptr <= ' ');
        };
        auto read_other = [&](auto other) {
            read(other);
            return other;
        };

        if constexpr (is_same_v<T, char>)
            skip_ws(), val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            val = bool(read_other(uint8_t()));
        } else if constexpr (IsModInt<T>) {
            val = T(read_other(ll()));
        } else if constexpr (is_integral_v<T>) {
            skip_ws();
            if (is_signed_v<T> && *iptr == '-')
                ++iptr, val = T(-read_other(make_unsigned_t<T>()));
            else
                for (val = 0; iptr != iend && *iptr > ' '; val = T(10 * val + (*iptr++ & 15)));
        } else if constexpr (is_floating_point_v<T>)
            skip_ws(), val = T(strtold(iptr, &iptr));
        else if constexpr (is_same_v<T, string>) {
            skip_ws();
            val.clear();
            do {
                auto* after = find_if(iptr, iend, [](char c) { return c <= ' '; });
                val.append(iptr, after);
                if ((iptr = after) != iend)
                    break;
                refill();
            } while (iptr != iend);
        } else if constexpr (cp_lib_type_meta::is_tuple_like<T> && !is_std_array<T>)
            apply([](auto&... items) { (read(items), ...); }, val);
        else
            trav(item, val)
                read(item);
    }
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
    if (sizeof...(Args))
        (cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
    else
        print('\n'), --cp_lib_io::optr;
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }


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



template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }

namespace cp_lib_rmq {
    template <class T, bool Max> T minmax(T a, T b) { return (a < b) ^ Max ? a : b; }
}

template <class T, T (*Combine)(T, T)>
struct SparseTable {
    vector<vector<T>> d = {};

    SparseTable() = default;
    explicit SparseTable(const vector<T>& v) {
        int n = sz(v), k = floor_log2(n);
        d.assign(k + 1, v);
        rep(i, k) rep(j, n)
            d[i + 1][j] = Combine(d[i][j], d[i][min(j + (1 << i), n - 1)]);
    }

    // Aggregate for [l, r)
    T query(int l, int r) const {
        int k = floor_log2(r - l);
        return Combine(d[k][l], d[k][r - (1 << k)]);
    }
};

template <class T>
using Rmq = SparseTable<T, cp_lib_rmq::minmax<T, false>>;
template <class T>
using Rmaxq = SparseTable<T, cp_lib_rmq::minmax<T, true>>;


template <class A, class M = identity,
          class = enable_if_t<!cp_lib_type_meta::is_tuple_like<remove_cvref_t<A>>>>
auto graph(A&& adj, M&& m = M()) { return make_tuple(ref(adj), sz(adj), m); }
template <class G, class = enable_if_t<cp_lib_type_meta::is_tuple_like<remove_cvref_t<G>>>>
auto graph(G g) { return g; }
namespace cp_lib_graph {
    template <class G> using AdjListIter = decltype(begin(get<0>(graph(declval<G>()))[0]));
}

struct LowestCommonAncestor {
    vector<int> time, euler;
    Rmq<int> rmq;

    template <class G, class = enable_if_t<!is_same_v<LowestCommonAncestor, remove_cvref_t<G>>>>
    LowestCommonAncestor(G&& g, int root = 0) {
        auto [adj, n, to] = graph(forward<G>(g));
        if (!n) return;
        time = vector(n, -1);
        vector<int> d;
        auto dfs = [&, t = 1, &adj = adj, &to = to](int v, int p, int tp, auto&& self) mutable -> void {
            euler.push_back(p);
            d.push_back(tp);
            time[v] = t++;
            trav(e, adj[v])
                if (to(e) != p)
                    self(to(e), v, time[v], self);
        };
        dfs(root, -1, 0, dfs);
        rep(i, n)
            if (time[i] == -1)
                dfs(i, -1, 0, dfs);
        rmq = Rmq<int>(d);
    }

    int lca(int u, int v) const {
        if (u == v) return u;
        auto [l, r] = minmax(time[u], time[v]);
        return euler[rmq.query(l, r)];
    }

    bool on_path(int v, pair<int, int> path) const {
        auto [a, b] = path;
        auto av = lca(a, v), bv = lca(b, v), ab = lca(a, b);
        return av != -1 && bv != -1 && ab != -1 && minmax(av, bv) == minmax(v, ab);
    }

    bool is_ancestor(int u, int v) const { return lca(u, v) == u; }
};

int main() {
    int t; read(t);
    while (t--) {
        int n, m, q; read(n, m, q);
        vector adj(n + m, vector<int>());
        int vr = -1;
        Dsu dsu(n);
        vector root(n, 0);
        iota(all(root), 0);

        rep(i, m) {
            int u, v; read(u, v); --u, --v;
            u = dsu.find(u);
            v = dsu.find(v);
            if (u == v)
                continue;

            adj[n + i] = {root[u], root[v]};
            dsu.join(u, v);
            root[dsu.find(u)] = n + i;
            vr = n + i;
        }

        LowestCommonAncestor lca(adj, vr);
        vector seg(2 * n, 0);
        rep(i, n)
            seg[i + n] = i;
        repr(i, n - 1, 1)
            seg[i] = lca.lca(seg[2 * i], seg[2 * i + 1]);

        while (q--) {
            int l, r; read(l, r); --l;
            int ans = l;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l % 2)
                    ans = lca.lca(ans, seg[l++]);
                if (r % 2)
                    ans = lca.lca(ans, seg[--r]);
            }

            print(ans < n ? 0 : ans - n + 1);
        }

        println();
    }
}