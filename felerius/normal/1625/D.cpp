// Binary Spiders (https://codeforces.com/contest/1625/problem/D)
#pragma GCC optimize("fast-math")

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


#ifdef CP_LIB_DEBUG
#define cp_lib_assert(expr) \
    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << #expr << " (" << __FILE__ << ':' << __LINE__ << ")\n"; \
        ::abort(); \
    } } while (0)
#else
#define cp_lib_assert(expr)
#endif


#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif

namespace cp_lib_type_meta {
    struct NoOp { template <class... Args> void operator()(Args&&...) const noexcept {} };
    template <class T, class = void> constexpr bool is_tuple_like = false;
    template <class T> constexpr bool is_tuple_like<T, void_t<tuple_element_t<0, T>>> = true;
}


namespace cp_lib_modint { struct ModIntTag {}; }
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
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T2>)
            return print(decltype(T2::mod())(val));
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
        do {
            for (; iptr != iend && *iptr <= ' '; ++iptr);
            if (iend - iptr < 64)
                refill();
        } while (*iptr <= ' ');

        auto read_other = [&](auto other) {
            read(other);
            return other;
        };

        if constexpr (is_same_v<T, char>)
            val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            val = bool(read_other(uint8_t()));
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>) {
            val = T(read_other(ll()));
        } else if constexpr (is_integral_v<T>) {
            if (is_signed_v<T> && *iptr == '-')
                ++iptr, val = T(-read_other(make_unsigned_t<T>()));
            else
                for (val = 0; iptr != iend && *iptr > ' '; val = T(10 * val + (*iptr++ & 15)));
        } else if constexpr (is_floating_point_v<T>)
            val = T(strtold(iptr, &iptr));
        else if constexpr (is_same_v<T, string>) {
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


template <int W>
class BinaryTrie {
    static_assert(1 <= W && W <= 64);
    vector<array<int, 2>> t{2, array{0, 0}};
    int free_list_tail = 1;

 public:
    void add(uint64_t x) {
        for (int v = 0, i = W - 1; i >= 0; --i) {
            uint64_t bit = (x >> i) & 1;
            if (!t[v][bit]) {
                if (free_list_tail == 1)
                    t[v][bit] = sz(t), t.push_back({0, 0});
                else
                    t[v][bit] = exchange(free_list_tail, t[free_list_tail][0]), t[t[v][bit]].fill(0);
            }
            v = t[v][bit];
        }
    }

    bool remove(uint64_t x) {
        array<int, W + 1> v{};
        repr(i, W - 1)
            if (!(v[i] = t[v[i + 1]][(x >> i) & 1]))
                return false;
        rep(i, W) {
            t[free_list_tail][1] = v[i];
            t[v[i]][0] = exchange(free_list_tail, v[i]);
            t[v[i + 1]][(x >> i) & 1] = 0;
            if (t[v[i + 1]][((x >> i) & 1) ^ 1])
                break;
        }
        return true;
    }

    uint64_t xor_min(uint64_t x) const {
        uint64_t ans = 0;
        for (int i = W - 1, v = 0; i >= 0; --i) {
            uint64_t bit = (x >> i) & 1, choice = (bit ^ !t[v][bit]);
            v = t[v][choice];
            ans ^= (bit ^ choice) << i;
        }
        return ans;
    }
    uint64_t xor_max(uint64_t x) const { return ~xor_min(~x) << (64 - W) >> (64 - W); }
};

int main() {
    int n, k; read(n, k);
    if (k == 0) {
        println(n);
        rep(i, n)
            print(i + 1);
        println();
        return 0;
    }

    vector a(n, 0);
    read(a);
    map<int, int> idx;
    rep(i, n)
        idx[a[i]] = i;
    sort(all(a));

    int high_bit = 1 << (31 - __builtin_clz(k));
    int high_mask = ~((high_bit << 1) - 1);

    vector<int> ans;
    for (int l = 0; l < n;) {
        int r = l;
        while (r < n && (a[l] & high_mask) == (a[r] & high_mask))
            ++r;

        int m = l;
        BinaryTrie<30> trie;
        while (m < r && (a[m] & high_bit) == 0)
            trie.add(a[m++]);

        auto p = pair(-1, -1);
        rep(i, m, r) {
            auto xo = int(trie.xor_max(a[i]));
            if (xo >= k)
                p = pair(idx[a[i]], idx[a[i] ^ xo]);
        }

        if (p.first == -1)
            ans.push_back(idx[a[l]]);
        else
            ans.push_back(p.first), ans.push_back(p.second);

        l = r;
    }

    if (sz(ans) < 2)
        println(-1), exit(0);

    println(sz(ans));
    trav(i, ans)
        ++i;
    println(ans);
}