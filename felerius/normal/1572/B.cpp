// Xor of 3 (https://codeforces.com/contest/1572/problem/B)
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

template <class It, class ItEnd>
vector<int> solve(It it, ItEnd it_end) {
    assert(!it->first);
    vector<int> pos;
    auto perform = [&](auto pit) {
        pos.emplace_back(min({pit->second, next(pit)->second, next(next(pit))->second}));
        auto x = pit->first ^ next(pit)->first ^ next(next(pit))->first;
        pit->first = x;
        next(pit)->first = x;
        next(next(pit))->first = x;
    };

    while (it_end - it >= 4) {
        auto a = next(it)->first, b = next(next(it))->first, c = next(next(next(it)))->first;

        // 00**
        if (!a) {
            ++it;
            continue;
        }

        // 011*
        if (b) {
            perform(it);
            it += 2;
            continue;
        }

        if (c) {
            // 0101
            perform(next(it));
            it += 3;
        } else {
            // 0100
            perform(next(it));
            // 0111
            perform(it);
            // 0001
            it += 2;
        }
    }

    if (it_end - it == 3) {
        if (!(it->first ^ next(it)->first ^ next(next(it))->first))
            perform(it);
    }

    return pos;
}

int main() {
    int t; read(t);
    while (t--) {
        int n; read(n);
        vector a(n, pair(false, 0));
        rep(i, n)
            read(a[i].first), a[i].second = i;

        bool par = false;
        trav(ai, a)
            par ^= ai.first;
        if (par) {
            println("NO");
            continue;
        }

        int lpar = false;
        vector<int> p1, p2, p3;
        bool pos = false;
        rep(i, n) {
            if (a[i].first) {
                lpar ^= 1;
                continue;
            }

            if (!lpar) {
                p1 = solve(rbegin(a) + (n - 1 - i), rend(a));
                p2 = solve(begin(a) + i, end(a));
                pos = true;
                break;
            }

            if (i + 1 < n && a[i + 1].first) {
                int j = i;
                // there is >=1 ones to the left since lpar == true
                while (!a[j - 1].first)
                    --j;
                if ((i - j + 1) % 2) {
                    while (j < i)
                        p1.push_back(j - 1), a[j].first ^= 1, a[j + 1].first ^= 1, j += 2;
                    p1.push_back(i - 1);
                    a[i - 1].first ^= 1;
                    a[i + 1].first ^= 1;
                    p2 = solve(rbegin(a) + (n - 1 - i), rend(a));
                    p3 = solve(begin(a) + i, end(a));
                    pos = true;
                    break;
                }
            }
        }

        if (pos) {
            copy(all(p2), back_inserter(p1));
            copy(all(p3), back_inserter(p1));
            trav(i, p1) ++i;
            printlns("YES", sz(p1), p1);
        } else
            println("NO");
    }
}