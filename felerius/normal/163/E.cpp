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
// begin "modint/_detect.hpp"
namespace cp_lib_modint { struct ModIntTag {}; }
// end "modint/_detect.hpp"
#include <unistd.h>

namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T, class = void> struct is_tuple_like : false_type {};
    template <class T> struct is_tuple_like<T, void_t<tuple_element_t<0, T>>> : true_type {};
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
            else if constexpr (is_tuple_like<T2>() && !is_std_array<T2>())
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
        } else if constexpr (is_tuple_like<T>() && !is_std_array<T>())
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
// begin "cp-lib/modint/static-montgomery.hpp"
// begin "_base.hpp"
// begin "../math/ext-gcd.hpp"
template <class I>
constexpr enable_if_t<is_signed_v<I>, array<I, 3>> ext_gcd(I a, I b) {
    I x(1), y(0), x1(0), y1(1);
    while (b) {
        I t = a / b;
        tie(x, x1) = pair(x1, x - t * x1);
        tie(y, y1) = pair(y1, y - t * y1);
        tie(a, b) = pair(b, a - t * b);
    }
    return {a, x, y};
}
// end "../math/ext-gcd.hpp"

namespace cp_lib_modint {
    template <class Self, class Int>
    struct Base : ModIntTag {
        static_assert(is_same_v<Int, uint32_t> || is_same_v<Int, uint64_t>);

        friend constexpr Self operator+(Self l, Self r) { return l += r; }
        friend constexpr Self operator-(Self l, Self r) { return l -= r; }
        friend constexpr Self operator*(Self l, Self r) { return l *= r; }
        friend constexpr Self operator/(Self l, Self r) { return l * r.inv(); }
        friend constexpr Self& operator/=(Self& l, Self r) { return l *= r.inv(); }
        friend constexpr Self operator+(Self x) { return x; }
        friend constexpr Self operator-(Self x) { return Self(0) - x; }
        friend constexpr Self& operator++(Self& x) { return x += Self(1); }
        friend constexpr Self& operator--(Self& x) { return x -= Self(1); }
        friend constexpr Self operator++(Self& x, int) { auto y = x; ++x; return y; }
        friend constexpr Self operator--(Self& x, int) { auto y = x; --x; return y; }

#define CP_LIB_DEF(op) \
        template <class T, enable_if_t<is_integral_v<T>, int> = 0> \
        friend constexpr auto operator op(T l, Self r) { return Self(l) op r; }
        CP_LIB_DEF(==) CP_LIB_DEF(!=) CP_LIB_DEF(<) CP_LIB_DEF(+) CP_LIB_DEF(-) CP_LIB_DEF(*) CP_LIB_DEF(/)
#undef CP_LIB_DEF

        template <class T>
        constexpr enable_if_t<is_integral_v<T>, Self> pow(T e) const {
            Self r(1), b(*(Self*)(this));
            for (; e; b *= b, e >>= 1)
                if (e & 1) r *= b;
            return r;
        }

        constexpr optional<Self> try_inv() const {
            if (Self::is_prime())
                return *(Self*)this == Self() ? nullopt : optional(pow(Self::mod() - 2));
            auto [g, x, _] = ext_gcd(ll(*(Self*)this), ll(Self::mod()));
            return (abs(g) == 1 ? optional(Self(x)) : nullopt);
        }
        constexpr Self inv() const {
            if (Self::is_prime()) return pow(Self::mod() - 2);
            auto [g, x, _] = ext_gcd(ll(*(Self*)this), ll(Self::mod()));
            cp_lib_assert(abs(g) == 1);
            return x;
        }

        friend ostream& operator<<(ostream& out, Self m) { return out << uint64_t(m); }
        friend istream& operator>>(istream& in, Self& m) { ll x; in >> x; m = x; return in; }

     protected:
        Int i = 0;
    };

    template <class Int> using Wide = conditional_t<is_same_v<uint64_t, Int>, unsigned __int128, uint64_t>;
}
struct ModIntRaw {};
// end "_base.hpp"

namespace cp_lib_modint {
    template <class Int, Int Mod, bool IsPrime>
    class StaticMontgomery : public Base<StaticMontgomery<Int, Mod, IsPrime>, Int> {
        static_assert(Mod % 2 && Mod < (1ull << (sizeof(Int) * 8 - 2)));
        static constexpr Int INV = []{
            Int inv = Mod;
            rep(_, __builtin_ctz(sizeof(Int) * 8) - 1) inv *= 2 - Mod * inv;
            return inv;
        }();
        static constexpr Int R2 = Int(-Wide<Int>(Mod) % Mod);
        static constexpr Int reduce(Wide<Int> x) {
            return Int((x - Int(x) * INV * Wide<Int>(Mod))>> (sizeof(Int) * 8)) + Mod;
        }
        constexpr Int norm(Int x) const { return x >= Mod ? x - Mod : x; }

     public:
        static constexpr Int mod() { return Mod; }
        static constexpr bool is_prime() { return IsPrime; }

        StaticMontgomery() = default;
        template <class T, enable_if_t<is_unsigned_v<T>, int> = 0>
        constexpr StaticMontgomery(T x) { this->i = reduce(Wide<Int>(uint64_t(x) % Mod) * R2); }
        template <class T, enable_if_t<is_signed_v<T>, int> = 0>
        constexpr StaticMontgomery(T x) { this->i = reduce(Wide<Int>(ll(x) % ll(Mod) + ll(Mod)) * R2); }
        constexpr StaticMontgomery(Int x, ModIntRaw) { this->i = x; }

        template <class T, enable_if_t<is_integral_v<T>, int> = 0>
        constexpr explicit operator T() const { return T(norm(reduce(this->i))); }

        constexpr bool operator==(StaticMontgomery r) const { return norm(this->i) == norm(r.i); }
        constexpr bool operator!=(StaticMontgomery r) const { return norm(this->i) != norm(r.i); }
        constexpr bool operator<(StaticMontgomery r) const { return norm(this->i) < norm(r.i); }

        constexpr StaticMontgomery& operator+=(StaticMontgomery r) {
            if ((this->i += r.i) >= 2 * Mod)
                this->i -= 2 * Mod;
            return *this;
        }
        constexpr StaticMontgomery& operator-=(StaticMontgomery r) {
            if (make_signed_t<Int>(this->i -= r.i) < 0)
                this->i += 2 * Mod;
            return *this;
        }
        constexpr StaticMontgomery& operator*=(StaticMontgomery r) {
            return *this = {reduce(Wide<Int>(this->i) * r.i), {}};
        }
    };
}
template <uint32_t Mod, bool IsPrime> using StaticMontgomeryInt = cp_lib_modint::StaticMontgomery<uint32_t, Mod, IsPrime>;
template <uint64_t Mod, bool IsPrime> using StaticMontgomeryInt64 = cp_lib_modint::StaticMontgomery<uint64_t, Mod, IsPrime>;
// end "cp-lib/modint/static-montgomery.hpp"
// begin "cp-lib/graph/flatten.hpp"
// begin "_detail.hpp"
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
// end "_detail.hpp"

template <class G>
auto flatten(G&& graph, int root) {
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
// end "cp-lib/graph/flatten.hpp"
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

template <int K>
struct Trie {
    vector<array<int, K>> t{1};
    vector<int> cnt = {INF};

    size_t size() const { return ::size(t); }
    int next(int v, int c) const { return t[v][c]; }

    template <class It, class ItEnd, class T = typename iterator_traits<It>::value_type,
              class... Containers>
    int add(It it, ItEnd it_end, T base = (is_same_v<T, char> ? 'a' : T(0)), Containers&... cs) {
        int v = 0;
        for (; it != it_end; ++it) {
            if (!t[v][*it - base])
                t[v][*it - base] = sz(t), t.emplace_back(), cnt.emplace_back();
            v = t[v][*it - base];
            ++cnt[v];
        }
        (cs.resize(sz(t)), ...);
        return v;
    }

    template <class It, class ItEnd, class T = typename iterator_traits<It>::value_type>
    void remove(It it, ItEnd it_end, T base = (is_same_v<T, char> ? 'a' : T(0))) {
        int v = 0;
        for (; it != it_end && --cnt[next(v, *it - base)]; v = next(v, *it++ - base))
            cp_lib_assert(next(v, *it - base));
        if (it != it_end)
            t[v][*it - base] = 0;
    }
};

template <int W>
class BitTrie : public Trie<2> {
    array<bool, W> bits;

    void to_bits(uint64_t x) { rep(i, W) bits[W - 1 - i] = (x >> i) & 1; }

    template <bool Max>
    uint64_t xor_eval(uint64_t x) const {
        uint64_t ans = 0;
        for (int i = W - 1, v = 0, bit = int((x >> i) & 1); i >= 0; bit = int((x >> --i) & 1)) {
            if (next(v, bit ^ Max))
                v = next(v, bit ^ Max), ans ^= (uint64_t(Max) << i);
            else
                v = next(v, !bit ^ Max), ans ^= (uint64_t(!Max) << i);
        }
        return ans;
    }

 public:
    uint64_t xor_min(uint64_t x) const { return xor_eval<false>(x); }
    uint64_t xor_max(uint64_t x) const { return xor_eval<true>(x); }

    template <class... Containers>
    int add(uint64_t x, Containers&... cs) { to_bits(x); return Trie<2>::add(all(bits), 0, cs...); }
    template <class... Containers>
    void remove(uint64_t x, Containers&... cs) { to_bits(x); Trie<2>::remove(all(bits), 0, cs...); }
};

template <int K = 26>
struct AhoCorasick : Trie<K> {
    template <class F>
    void build(F&& f) {
        queue<array<int, 4>> q;
        q.push({0, -1, 0, -1});
        while (sz(q)) {
            auto [v, c, p, plink] = q.front(); q.pop();
            int link = (p ? this->next(plink, c) : 0);
            rep(i, K) {
                if (this->next(v, i))
                    q.push({this->next(v, i), i, v, link});
                else
                    this->t[v][i] = (v ? this->next(link, i) : 0);
            }
            if (v)
                f(v, link, c, p);
        }
    }
};

struct FenwickConf {
    using T = int;
    static constexpr T UNIT = 0;
    static T add(const T& a, const T& b) { return a + b; }
    static T sub(const T& a, const T& b) { return a - b; }
};
using Fenwick = FenwickTree<FenwickConf>;

int main() {
    int n, k; read(n, k);
    vector tree(1, vector<int>());

    AhoCorasick ac;
    vector end(k, 0);
    rep(i, k) {
        string s; read(s);
        end[i] = ac.add(all(s), 'a', tree);
    }
    ac.build([&](int v, int link, int, int) {
        tree[link].push_back(v);
    });

    auto [enter, exit] = flatten(tree, 0);
    Fenwick ft(sz(ac) + 1);
    rep(i, k)
        ft.update(enter[end[i]], 1), ft.update(exit[end[i]], -1);

    vector in_gov(k, true);
    while (n--) {
        char ty; read(ty);
        if (ty == '+') {
            int i; read(i); --i;
            if (!in_gov[i])
                ft.update(enter[end[i]], 1), ft.update(exit[end[i]], -1);
            in_gov[i] = true;
        } else if (ty == '-') {
            int i; read(i); --i;
            if (in_gov[i])
                ft.update(enter[end[i]], -1), ft.update(exit[end[i]], 1);
            in_gov[i] = false;
        } else {
            string s; read(s);
            ll ans = 0;
            int v = 0;
            trav(c, s)
                v = ac.next(v, c - 'a'), ans += ft.query(enter[v] + 1);
            println(ans);
        }
    }

    // int n; ll l, r; read(n, l, r);
    // vector fib = {0ll, 1ll};
    // while (fib.back() <= r)
    //     fib.push_back(fib.back() + fib[sz(fib) - 2]);

    // AhoCorasick<10, vector<bool>> ac;
    // auto& [is_end] = ac.containers;
    // trav(fi, fib) {
    //     if (fi < l || r < fi)
    //         continue;
    //     auto s = to_string(fi);
    //     int v = ac.add(all(s), '0');
    //     is_end[v] = true;
    // }
    // ac.build([&is_end=is_end](int v, int link, int, int) {
    //     is_end[v] = is_end[v] || is_end[link];
    // });

    // int m = sz(ac);
    // using MI = StaticMontgomeryInt<int(1e9) + 7, true>;
    // vector dp(n + 1, vector(m, MI(0)));
    // dp[0][0] = 1;
    // rep(i, n) rep(j, m) rep(k, 10)
    //     if (!is_end[j])
    //         dp[i + 1][ac.next(j, k)] += dp[i][j];

    // MI ans = 0;
    // rep(i, m)
    //     if (!is_end[i])
    //         ans += dp[n][i];
    // println(ans - 1);
}