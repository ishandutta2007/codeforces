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
// begin "cp-lib/data-structure/segtree/lazy.hpp"
// begin "_impl.hpp"
// begin "../../bit.hpp"
template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }
// end "../../bit.hpp"

namespace cp_lib_segtree {
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

template <class Conf>
struct LazySegmentTree : cp_lib_segtree::SegmentTreeImpl<LazySegmentTree<Conf>, Conf> {
 private:
    using Base = cp_lib_segtree::SegmentTreeImpl<LazySegmentTree<Conf>, Conf>;
    using U = typename Conf::U;
    friend Base;

    vector<U> lz;

    void apply_at(int i, const U& upd) {
        U dummy = Conf::NO_UPD;
        Conf::apply(Base::d[i], (i < Base::k ? lz[i] : dummy), upd, Base::width(i));
    }

    void push(int i) {
        if (lz[i] != Conf::NO_UPD)
            apply_at(2 * i, lz[i]), apply_at(2*i+1, lz[i]), lz[i] = Conf::NO_UPD;
    }

 public:
    explicit LazySegmentTree(int n_) : Base(n_), lz(Base::k, Conf::NO_UPD) {}

    template <class Iter>
    LazySegmentTree(Iter it, Iter end) : Base(it, end), lz(Base::k, Conf::NO_UPD) {}

    // Apply update to range [l, r)
    void update(int l, int r, const U& upd) {
        Base::push_path(l + Base::k);
        Base::push_path(r + Base::k - 1);

        for (int li = l + Base::k, ri = r + Base::k; li < ri; li /= 2, ri /= 2) {
            if (li % 2) apply_at(li++, upd);
            if (ri % 2) apply_at(--ri, upd);
        }

        for (int i : {l + Base::k, r + Base::k - 1})
            while (i /= 2)
                if (lz[i] == Conf::NO_UPD)
                    Base::recalc(i);
    }
};
// end "cp-lib/data-structure/segtree/lazy.hpp"
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
            return Int((x - Int(x) * INV * Wide<Int>(Mod)) >> (sizeof(Int) * 8)) + Mod;
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

        template <class T, enable_if_t<is_integral_v<T>, int> = 0>
        constexpr explicit operator T() const { return T(norm(reduce(this->i))); }
        constexpr Int raw() const { return norm(this->i); }

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
            this->i = reduce(Wide<Int>(this->i) * r.i);
            return *this;
        }
    };
}
template <uint32_t Mod, bool IsPrime> using StaticMontgomeryInt = cp_lib_modint::StaticMontgomery<uint32_t, Mod, IsPrime>;
template <uint64_t Mod, bool IsPrime> using StaticMontgomeryInt64 = cp_lib_modint::StaticMontgomery<uint64_t, Mod, IsPrime>;
// end "cp-lib/modint/static-montgomery.hpp"

using MI = StaticMontgomeryInt<int(1e9) + 7, true>;
struct Update {
    MI add_val, add_val_per_depth;
    bool reset;
    bool operator==(const Update& r) const  {
        return tie(add_val, add_val_per_depth, reset) == tie(r.add_val, r.add_val_per_depth, r.reset);
    }
    bool operator!=(const Update& r) const  {
        return tie(add_val, add_val_per_depth, reset) != tie(r.add_val, r.add_val_per_depth, r.reset);
    }
};

struct SegTreeConf {
    struct T {
        MI val, val_per_depth;
    };
    using U = Update;
    static constexpr T UNIT{0, 0};
    static constexpr U NO_UPD{0, 0, false};
    static T combine(const T& a, const T& b) {
        return {a.val + b.val, a.val_per_depth + b.val_per_depth};
    }
    static void apply(T& val, U& lz, const U& upd, int w) {
        if (upd.reset)
            val = UNIT, lz = NO_UPD;
        val.val += upd.add_val * w;
        val.val_per_depth += upd.add_val_per_depth * w;
        lz.add_val += upd.add_val;
        lz.add_val_per_depth += upd.add_val_per_depth;
        lz.reset |= upd.reset;
    }
};
using SegTree = LazySegmentTree<SegTreeConf>;

int main() {
    int n; read(n);
    vector lr(n, pair(0, 0));
    read(lr);
    vector adj(n, vector<int>());
    rep(_, n - 1) {
        int u, v; read(u, v); --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    MI ans = 0, tot_pos = 1;
    for (auto [l, r] : lr)
        tot_pos *= (r - l + 1);
    vector rem_pos(n, tot_pos);
    rep(i, n)
        rem_pos[i] /= (lr[i].second - lr[i].first + 1);

    constexpr int R = int(1e5) + 5;
    SegTree seg(R);
    vector<array<int, 2>> with_depth;
    centroid_decomposition(adj, [&](int vc, auto&& is_del) {
        auto [vc_l, vc_r] = lr[vc];
        seg.update(0, R, Update{0, 0, true});
        seg.update(vc_l, vc_r + 1, Update{0, rem_pos[vc], false});

        trav(vn, adj[vc]) {
            if (is_del(vn))
                continue;
            with_depth.clear();
            auto dfs = [&](int v, int p, int d, auto&& self) -> void {
                with_depth.push_back({v, d});
                trav(v2, adj[v])
                    if (v2 != p && !is_del(v2))
                        self(v2, v, d + 1, self);
            };
            dfs(vn, vc, 1, dfs);

            for (auto [v, d] : with_depth) {
                auto [l, r] = lr[v];
                auto [val, val_per_depth] = seg.query(l, r + 1);
                ans += (val + val_per_depth * d) / (r - l + 1);
            }

            for (auto [v, d] : with_depth) {
                auto [l, r] = lr[v];
                seg.update(l, r + 1, Update{rem_pos[v] * d, rem_pos[v], false});
            }
        }
    });

    println(ans);
}