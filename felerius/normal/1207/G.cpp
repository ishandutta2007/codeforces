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
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;

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
// begin "cp-lib/graph/euler-tour.hpp"
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

template <class G>
auto euler_tour(G&& graph, int root) {
    auto [adj, n, to] = Graph(forward<G>(graph));
    vector<int> enter(n), exit(n);
    auto dfs = [&, t=0, &adj=adj, &to=to](int v, int p, auto&& self) mutable -> void {
        enter[v] = t++;
        trav(e, adj[v])
            if (to(e) != p)
                self(to(e), v, self);
        exit[v] = t;
    };
    if (n) dfs(root, -1, dfs);
    return pair(enter, exit);
}
// end "cp-lib/graph/euler-tour.hpp"
// begin "cp-lib/data-structure/fenwick.hpp"
// begin "../bit.hpp"
template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }
// end "../bit.hpp"

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
// end "cp-lib/data-structure/fenwick.hpp"
// begin "cp-lib/string/aho-corasick.hpp"
template <int K = 26>
class AhoCorasick {
    vector<array<int, K>> t = {array<int, K>{}};
    int base;

 public:
    AhoCorasick(int base_ = 'a') : base(base_) {}

    size_t size() const { return ::size(t); }
    int next(int v, int c) const { return t[v][c - base]; }

    template <class It, class ItEnd>
    int add(It it, ItEnd it_end) {
        int v = 0;
        for (; it != it_end; v = t[v][int(*it++ - base)])
            if (!t[v][int(*it - base)])
                t[v][int(*it - base)] = sz(t), t.emplace_back().fill(0);
        return v;
    }

    template <class F>
    void build(F&& f) {
        queue<array<int, 4>> q;
        q.push({0, 0, 0, -1});
        while (sz(q)) {
            auto [v, p, plink, c] = q.front(); q.pop();
            int link = (p ? t[plink][c] : 0);
            rep(c2, K) {
                if (t[v][c2])
                    q.push({t[v][c2], v, link, c2});
                else
                    t[v][c2] = (v ? t[link][c2] : 0);
            }
            f(v, link, p, c);
        }
    }
};
// end "cp-lib/string/aho-corasick.hpp"

struct FenwickConf {
    using T = int;
    static constexpr T UNIT = 0;
    static T add(const T& a, const T& b) { return a + b; }
    static T sub(const T& a, const T& b) { return a - b; }
};
using Fenwick = FenwickTree<FenwickConf>;

int main() {
    int n; read(n);
    vector song_tree(n + 1, vector<pair<int, char>>());
    rep(i, 1, n + 1) {
        int ty; char c; int j = 0; read(ty);
        if (ty == 1)
            read(c);
        else
            read(j, c);
        song_tree[j].emplace_back(i, c);
    }

    int m; read(m);
    AhoCorasick ac;
    vector endv(m, 0);
    vector qs(n + 1, vector<int>());
    rep(i, m) {
        int j; string s; read(j, s);
        qs[j].push_back(i);
        endv[i] = ac.add(all(s));
    }

    vector ac_tree(sz(ac), vector<int>());
    ac.build([&](int v, int link, int, int) {
        if (v)
            ac_tree[link].push_back(v);
    });

    auto [enter, exit] = euler_tour(ac_tree, 0);
    Fenwick ft(sz(ac));
    vector ans(m, 0);
    auto dfs = [&, &enter=enter, &exit=exit](int v, int ac_v, auto&& self) -> void {
        ft.update(enter[ac_v], 1);
        trav(i, qs[v])
            ans[i] = ft.query(enter[endv[i]], exit[endv[i]]);
        for (auto& [v2, c] : song_tree[v])
            self(v2, ac.next(ac_v, c), self);
        ft.update(enter[ac_v], -1);
    };
    dfs(0, 0, dfs);

    trav(i, ans)
        println(i);
}