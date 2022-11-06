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
// begin "cp-lib/string/p.hpp"
template <class It, class ItEnd>
vector<int> pfunc(It it, ItEnd it_end) {
    vector p(it_end - it, 0);
    rep(i, 1, sz(p)) {
        int pi = p[i - 1];
        while (pi && it[pi] != it[i])
            pi = p[pi - 1];
        p[i] = pi + (it[pi] == it[i]);
    }
    return p;
}
// end "cp-lib/string/p.hpp"

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

    vector<int> by_len_rev() const {
        vector cnt(t[last].len + 1, 0);
        trav(v, t)
            cnt[v.len]++;
        partial_sum(rbegin(cnt), rend(cnt), rbegin(cnt));
        vector idx(sz(t), 0);
        rep(i, sz(t))
            idx[--cnt[t[i].len]] = i;
        return idx;
    }

    void extend(int c) {
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
    }
};

int main() {
    string s; read(s);
    SuffixAutomaton sa;
    trav(c, s)
        sa.extend(c - 'a');

    vector pos_cnt(sz(sa), 0);
    rep(i, sz(sa))
        pos_cnt[i] = (sa[i].clone_of == -1);
    auto by_len_rev = sa.by_len_rev();
    trav(i, by_len_rev)
        if (sa[i].link != -1)
            pos_cnt[sa[i].link] += pos_cnt[i];

    int n; read(n);
    string x;
    while (n--) {
        read(x);
        auto p = pfunc(all(x));
        int m = 2 * sz(x) - 1;
        if (sz(x) % (sz(x) - p.back()) == 0)
            m = sz(x) + (sz(x) - p.back()) - 1;

        int v = 0, matched = 0, ans = 0;
        rep(i, m) {
            int c = x[i % sz(x)] - 'a';
            while (v && sa[v].next[c] == -1)
                v = sa[v].link, matched = sa[v].len;
            if (sa[v].next[c] == -1)
                continue;

            v = sa[v].next[c];
            ++matched;
            while (v && sa[sa[v].link].len >= sz(x))
                v = sa[v].link, matched = sa[v].len;

            if (matched >= sz(x))
                ans += pos_cnt[v];
        }

        println(ans);
    }
}