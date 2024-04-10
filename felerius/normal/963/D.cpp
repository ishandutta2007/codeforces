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

template <int K>
struct Trie {
    static constexpr bool Sparse = (K == -1);
    vector<array<int, K>> t{1};
    vector<int> cnt = {INF};

    size_t size() const { return ::size(t); }
    int next(int v, int c) const { return t[v][c]; }

    template <class It, class ItEnd, class T = typename iterator_traits<It>::value_type>
    int add(It it, ItEnd it_end, T base = (is_same_v<T, char> ? 'a' : T(0))) {
        int v = 0;
        for (; it != it_end; ++it) {
            if (!t[v][*it - base])
                t[v][*it - base] = sz(t), t.emplace_back(), cnt.emplace_back();
            v = t[v][*it - base];
            ++cnt[v];
        }
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

    int add(uint64_t x) { to_bits(x); return Trie<2>::add(all(bits)); }
    void remove(uint64_t x) { to_bits(x); Trie<2>::remove(all(bits)); }
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

int main() {
    string s; int n; read(s, n);

    AhoCorasick ac;
    vector<vector<int>> ends;
    vector k(n, 0), len(n, 0);
    rep(i, n) {
        string t; read(k[i], t);
        len[i] = sz(t);
        int v = ac.add(all(t));
        if (v >= sz(ends))
            ends.resize(v + 1);
        ends[v].push_back(i);
    }

    // vector ends_link(sz(ac), 0);
    ac.build([&](int v, int link, int, int) {
        copy(all(ends[link]), back_inserter(ends[v]));
        // ends_link[v] = (sz(ends[link]) ? link : ends_link[link]);
    });

    vector<queue<int>> qs(n);
    vector mn(n, INF);
    int v = 0;
    rep(i, sz(s)) {
        v = ac.next(v, s[i] - 'a');
        // for (int v2 = v; v2; v2 = ends_link[v2]) {
            // trav(j, ends[v2]) {
            trav(j, ends[v]) {
                qs[j].push(i);
                if (sz(qs[j]) == k[j])
                    mn[j] = min(mn[j], i - qs[j].front() + len[j]), qs[j].pop();
            }
        // }
    }

    trav(i, mn)
        println(i == INF ? -1 : i);
}