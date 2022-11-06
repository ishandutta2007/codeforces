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
    template <class T, class = void> constexpr bool is_tuple_like = false;
    template <class T> constexpr bool is_tuple_like<T, void_t<tuple_element_t<0, T>>> = true;
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

    template <class T> constexpr bool is_std_array = false;
    template <class T, size_t I> constexpr bool is_std_array<array<T, I>> = true;

    void flush() {
        auto* p = begin(obuf);
        while (p != optr)
            p += write(STDOUT_FILENO, p, optr - p);
        optr = begin(obuf);
    }
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
            else if constexpr (cp_lib_type_meta::is_tuple_like<T2> && !is_std_array<T2>)
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
        } else if constexpr (cp_lib_type_meta::is_tuple_like<T> && !is_std_array<T>)
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

template <int K = 26>
struct SuffixAutomaton {
    struct Node {
        array<int, K> next;
        int link, len, clone_of = -1;
        explicit Node(int len_, int link_ = 0) : link(link_), len(len_) { next.fill(-1); }
    };

 private:
    vector<Node> t = {Node(0, -1)};
    int last = 0;

 public:
    size_t size() const { return ::size(t); }
    const Node& operator[](size_t i) const { return t[i]; }
    int min_len(int v) const { return v ? t[t[v].link].len + 1 : 0; }

    int extend(int c) {
        int p = exchange(last, sz(t));
        t.emplace_back(t[p].len + 1);

        for (; p != -1 && t[p].next[c] == -1; p = t[p].link)
            t[p].next[c] = last;
        if (p != -1) {
            int q = t[last].link = t[p].next[c];
            if (t[q].len != t[p].len + 1) {
                t.emplace_back(t[q]).len = t[p].len + 1;
                t.back().clone_of = q;
                int clone = t[last].link = t[q].link = sz(t) - 1;
                for (; p != -1 && t[p].next[c] == q; p = t[p].link)
                    t[p].next[c] = clone;
            }
        }

        return last;
    }

    template <class... Containers>
    void sort(Containers&... cs) {
        vector cnt(t[last].len + 1, 0);
        trav(v, t)
            cnt[v.len]++;
        partial_sum(all(cnt), begin(cnt));
        vector idx(sz(t), 0);
        rep(i, sz(t))
            idx[i] = --cnt[t[i].len];
        trav(v, t) {
            v.link = (v.link == -1 ? -1 : idx[v.link]);
            v.clone_of = (v.clone_of == -1 ? -1 : idx[v.clone_of]);
            trav(i, v.next)
                i = (i == -1 ? -1 : idx[i]);
        }
        rep(i, sz(t))
            while (idx[i] != i)
                swap(t[i], t[idx[i]]), (swap(cs[i], cs[idx[i]]), ...), swap(idx[i], idx[idx[i]]);
    }
};

template <int K = 8>
class SparseSuffixAutomaton {
    static constexpr uint32_t CHAR_MASK = (1u << K) - 1;
    struct Node {
        vector<uint32_t> adj;
        int link, len, cloned_from;
        auto next(int c) { return find_if(all(adj), [&](auto i) { return (i & CHAR_MASK) == c; }); }
    };
    vector<Node> t = {Node{{}, -1, 0, -1}};
    int last = 0;

 public:
    size_t size() const { return ::size(t); }
    int next(int v, int c) const {
        cp_lib_assert(0 <= c && c < (1 << K));
        auto it = find_if(all(t[v].adj), [&](auto i) { return (i & CHAR_MASK) == c; });
        return (it == end(t[v].adj) ? -1 : *it >> K);
    }
    int len(int v) const { return t[v].len; }
    int link(int v) const { return t[v].link; }
    int cloned_from(int v) const { return t[v].cloned_from; }
    int min_len(int v) const { return v ? t[t[v].link].len + 1 : 0; }

    void extend(int c) {
        cp_lib_assert(0 <= c && c < (1 << K));
        int p = exchange(last, sz(t));
        t.push_back(Node{{}, 0, t[p].len + 1, -1});

        vector<uint32_t>::iterator it;
        for (; p != -1 && (it = t[p].next(c)) == end(t[p].adj); p = t[p].link)
            t[p].adj.push_back((last << K) | c);
        if (p != -1) {
            int q = t[last].link = (*it >> K);
            if (t[q].len != t[p].len + 1) {
                t.push_back(Node{t[q].adj, t[q].link, t[p].len + 1, q});
                int clone = t[last].link = t[q].link = sz(t) - 1;
                for (; p != -1 && (it = t[p].next(c)) != end(t[p].adj) && (*it >> K) == q; p = t[p].link)
                    *it = (clone << K) | c;
            }
        }
    }

    void sort() {
        vector cnt(t[last].len + 1, 0);
        trav(v, t)
            cnt[v.len]++;
        partial_sum(all(cnt), begin(cnt));
        vector idx(sz(t), 0);
        rep(i, sz(t))
            idx[i] = --cnt[t[i].len];
        trav(v, t) {
            v.link = (v.link == -1 ? -1 : idx[v.link]);
            v.cloned_from = (v.cloned_from == -1 ? -1 : idx[v.cloned_from]);
            trav(i, v.adj)
                i = (idx[i >> K] << K) | (i & CHAR_MASK);
        }
        rep(i, sz(t))
            while (idx[i] != i)
                swap(t[i], t[idx[i]]), swap(idx[i], idx[idx[i]]);
    }
};

int main() {
    array<string, 3> s; read(s);

    SparseSuffixAutomaton sa;
    rep(i, 3) {
        trav(c, s[i])
            sa.extend(c);
        sa.extend(i);
    }
    sa.sort();

    vector cnt(sz(sa), array{0, 0, 0});
    repr(i, sz(sa) - 1, 1) {
        if (sa.cloned_from(i) == -1) {
            int l = sa.len(i);
            if (l <= sz(s[0]))
                ++cnt[i][0];
            else if (l <= sz(s[0]) + 1 + sz(s[1]))
                ++cnt[i][1];
            else
                ++cnt[i][2];
        }
        rep(j, 3)
            cnt[sa.link(i)][j] += cnt[i][j];
    }

    using MI = StaticMontgomeryInt<int(1e9) + 7, true>;
    int n = min({sz(s[0]), sz(s[1]), sz(s[2])});
    vector ans(n + 2, MI(0));
    rep(i, sz(sa)) {
        int l = sa.min_len(i), r = sa.len(i) + 1;
        r = min(n + 1, r);
        auto c = MI(cnt[i][0]) * cnt[i][1] * cnt[i][2];
        if (r > l)
            ans[l] += c, ans[r] -= c;
    }

    partial_sum(all(ans), begin(ans));
    rep(i, 1, n + 1)
        print(ans[i]);
    println();
}