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
#endif
#if __cpp_lib_remove_cvref < 201711L
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif

namespace cp_lib_type_meta {
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
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>) {
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


namespace cp_lib_hash {
    template <bool HackSafe>
    struct Hash {
        template <class T>
        size_t operator()(const T& x) const noexcept {
            static const uint64_t RND = chrono::high_resolution_clock::now().time_since_epoch().count();
            constexpr uint64_t A = 0x9e3779b97f4a7c15, B = 0xbf58476d1ce4e5b9, C = 0x94d049bb133111eb;
            uint64_t h = 0;
            if constexpr (HackSafe && is_integral_v<T>) {
                h = uint64_t(x) + RND + A;
                (h ^= h >> 30) *= B;
                (h ^= h >> 27) *= C;
                return h ^ (h >> 31);
            } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>)
                return (*this)(uint64_t(x.raw()));
            else if constexpr (cp_lib_type_meta::is_tuple_like<T>) {
                apply([&](auto&&... items) { ((h ^= ((*this)(items) + A + (h << 6) + (h >> 2))), ...); }, x);
                return h;
            } else
                return hash<T>()(x);
        }
    };

    template <class K, class V, bool FastGcc, bool HackSafe>
    struct HashSelector : conditional<is_void_v<V>, unordered_set<K, Hash<HackSafe>>,
                                      unordered_map<K, V, Hash<HackSafe>>> {};
}

#if defined(__GNUC__) && !defined(__clang__)
#include <ext/pb_ds/assoc_container.hpp>
template <class K, class V, bool HackSafe>
struct cp_lib_hash::HashSelector<K, V, true, HackSafe> {
    using type = __gnu_pbds::gp_hash_table<K, conditional_t<is_void_v<V>, __gnu_pbds::null_type, V>,
                                           cp_lib_hash::Hash<HackSafe>>;
};
#endif

template <class K, class V, bool FastGcc = true, bool HackSafe = true>
using HashMap = typename cp_lib_hash::HashSelector<K, V, FastGcc, HackSafe>::type;
template <class K, bool FastGcc = true, bool HackSafe = true>
using HashSet = typename cp_lib_hash::HashSelector<K, void, FastGcc, HackSafe>::type;



template <class A, class M = identity,
          class = enable_if_t<!cp_lib_type_meta::is_tuple_like<remove_cvref_t<A>>>>
auto graph(A&& adj, M&& m = M()) { return make_tuple(ref(adj), sz(adj), m); }
template <class G, class = enable_if_t<cp_lib_type_meta::is_tuple_like<remove_cvref_t<G>>>>
auto graph(G g) { return g; }
namespace cp_lib_graph {
    template <class G> using AdjListIter = decltype(begin(get<0>(graph(declval<G>()))[0]));
}

template <bool Cycle, class G, class Iter = cp_lib_graph::AdjListIter<G>>
pair<int, vector<Iter>> euler_directed(G&& g) {
    auto [adj, n, to] = graph(forward<G>(g));
    vector<Iter> iter(n);
    vector diff(n, 0);
    rep(i, n) {
        iter[i] = begin(adj[i]);
        diff[i] += sz(adj[i]);
        trav(e, adj[i])
            --diff[to(e)];
    }

    int v0 = 0, off1 = 0, m = 0;
    rep(i, n) {
        m += sz(adj[i]);
        if (abs(diff[i]) > 1)
            return {-1, {}};
        off1 += bool(diff[i]);
        if (diff[i] == 1)
            v0 = i;
    }
    while (v0 < n && !sz(adj[v0]))
        ++v0;
    if (v0 == n || (off1 != 0 && (Cycle || off1 != 2)))
        return {-1, {}};

    vector<pair<int, Iter>> stack = {{v0, {}}};
    vector<Iter> path;
    while (sz(stack)) {
        if (int v = stack.back().first; iter[v] == end(adj[v]))
            path.push_back(stack.back().second), stack.pop_back();
        else
            stack.emplace_back(to(*iter[v]), iter[v]), ++iter[v];
    }

    path.pop_back();
    reverse(all(path));
    return sz(path) == m ? pair(v0, path) : pair(-1, decltype(path)());
}

int main() {
    int n; read(n);
    vector<string> s(n);
    read(s);

    HashMap<string_view, int> m;
    trav(si, s)
        rep(i, 2)
            m.insert(pair(string_view(si).substr(i, 2), sz(m)));
    vector<string_view> back(sz(m));
    for (auto [sv, i] : m)
        back[i] = sv;

    vector adj(sz(m), vector<int>());
    trav(si, s) {
        int v1 = m[si.substr(0, 2)], v2 = m[si.substr(1, 2)];
        adj[v1].push_back(v2);
    }

    auto [v0, path] = euler_directed<false>(adj);
    if (v0 == -1)
        println("NO"), exit(0);

    string ans(back[v0]);
    trav(it, path)
        ans.push_back(back[*it][1]);
    println("YES");
    println(ans);
}