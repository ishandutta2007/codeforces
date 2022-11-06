// Bridge Club (https://codeforces.com/contest/1572/problem/D)
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
// begin "cp-lib/graph/flow/ssp.hpp"
// begin "_detail.hpp"
template <class Flow>
struct FlowEdge {
    int to, rev;
    Flow rem_cap, cap;
    Flow flow() const { return cap - rem_cap; }
};

template <class Flow, class Cost>
struct CostFlowEdge : FlowEdge<Flow> { Cost cost; };

namespace cp_lib_flow {
    template <class Flow, class Cost = void>
    struct FlowGraph {
        static_assert(is_signed_v<Flow> && (is_void_v<Cost> || is_signed_v<Cost>));
        using Edge = conditional_t<is_void_v<Cost>, FlowEdge<Flow>, CostFlowEdge<Flow, Cost>>;
        vector<vector<Edge>> adj;

        explicit FlowGraph(int n) : adj(n) {}

        Flow calc_flow(int s, int t, Flow limit = numeric_limits<Flow>::max());
        vector<pair<Flow, vector<Edge*>>> decompose(int s, int t);
        vector<bool> calc_cut(int s);
    };
}
// end "_detail.hpp"

template <class Flow = ll, class Cost = ll>
struct SuccessiveShortestPathFlowGraph : cp_lib_flow::FlowGraph<Flow, Cost> {
 private:
    using Base = cp_lib_flow::FlowGraph<Flow, Cost>;
    static constexpr auto mcmf_limiter = [](auto, auto, auto aug, auto) { return aug; };

    vector<Cost> bellman_ford() {
        vector<uint8_t> inq(sz(Base::adj), true);
        vector<Cost> dist(sz(Base::adj));
        queue<int> q;
        rep(v, sz(Base::adj))
            q.push(v);

        while (sz(q)) {
            int v = q.front(); q.pop();
            inq[v] = false;
            trav(e, Base::adj[v]) {
                if (!e.rem_cap || dist[v] + e.cost >= dist[e.to])
                    continue;
                dist[e.to] = dist[v] + e.cost;
                if (!inq[e.to])
                    inq[e.to] = true, q.push(e.to);
            }
        }

        return dist;
    }

 public:
    using Base::Base;

    int add_edge(int s, int t, Flow cap, Cost cost) {
        int idx = sz(Base::adj[s]), idx_rev = (s == t ? idx + 1 : sz(Base::adj[t]));
        Base::adj[s].push_back(typename Base::Edge{{t, idx_rev, cap, cap}, cost});
        Base::adj[t].push_back(typename Base::Edge{{s, idx, Flow(0), Flow(0)}, -cost});
        return idx;
    }

    template <class F = decltype(mcmf_limiter), class TotalCost = ll>
    tuple<Flow, TotalCost, vector<Cost>>
    calc_cost_flow(int s, int t, F limiter = mcmf_limiter, bool negative_edges = true) {
        int n = sz(Base::adj);
        auto pi = (negative_edges ? bellman_ford() : vector(n, Cost(0)));
        vector dist(n, numeric_limits<Cost>::max());
        vector<int> seen;
        vector<typename Base::Edge*> inc(n);
        Flow flow{0};
        TotalCost total_cost{0};

        while (true) {
            priority_queue<pair<Cost, int>> q;
            q.emplace(Cost(0), s);
            fill(all(dist), numeric_limits<Cost>::max());
            dist[s] = Cost(0);
            seen.clear();

            while (sz(q) && q.top().second != t) {
                auto [d, v] = q.top(); q.pop(); d = -d;
                if (d > dist[v])
                    continue;
                seen.push_back(v);
                d += pi[v];
                trav(e, Base::adj[v]) {
                    auto new_dist = d + e.cost - pi[e.to];
                    if (e.rem_cap && new_dist < dist[e.to])
                        dist[e.to] = new_dist, q.emplace(-new_dist, e.to), inc[e.to] = &e;
                }
            }

            if (!sz(q)) break;
            auto dt = -q.top().first;
            trav(v, seen)
                pi[v] += dist[v] - dt;

            Flow bottleneck = numeric_limits<Flow>::max();
            Cost aug_cost{0};
            for (int v = t; v != s; v = Base::adj[inc[v]->to][inc[v]->rev].to)
                bottleneck = min(bottleneck, inc[v]->rem_cap), aug_cost += inc[v]->cost;

            auto aug = limiter(flow, total_cost, bottleneck, aug_cost);
            flow += aug;
            total_cost += TotalCost(aug) * TotalCost(aug_cost);
            for (int v = t; v != s; v = Base::adj[inc[v]->to][inc[v]->rev].to)
                inc[v]->rem_cap -= aug, Base::adj[inc[v]->to][inc[v]->rev].rem_cap += aug;
            if (aug < bottleneck)
                break;
        }

        return {flow, total_cost, move(pi)};
    }
};
// end "cp-lib/graph/flow/ssp.hpp"

int main() {
    int n, k; read(n, k);
    vector a(1 << n, 0);
    read(a);

    vector<array<int, 3>> e;
    e.reserve((1 << n) * n / 2);
    rep(i, 1 << n)
        rep(j, n)
            if (i & (1 << j))
                e.push_back({a[i] + a[i ^ (1 << j)], i, i ^ (1 << j)});
    auto it = end(e) - min(sz(e), 2 * n * k);
    nth_element(begin(e), it, end(e));
    e.erase(begin(e), it);

    vector<int> nodes;
    for (auto [_, u, v] : e)
        nodes.push_back(u), nodes.push_back(v);
    sort(all(nodes));
    nodes.erase(unique(all(nodes)), end(nodes));

    SuccessiveShortestPathFlowGraph<> g(sz(nodes) + 2);
    int s = sz(nodes), t = s + 1;
    rep(i, sz(nodes)) {
        if (__builtin_popcount(nodes[i]) % 2)
            g.add_edge(i, t, 1, 0);
        else
            g.add_edge(s, i, 1, 0);
    }
    for (auto [w, u, v] : e) {
        if (__builtin_popcount(u) % 2)
            swap(u, v);
        u = int(lower_bound(all(nodes), u) - begin(nodes));
        v = int(lower_bound(all(nodes), v) - begin(nodes));
        g.add_edge(u, v, 1, int(2e6) - w);
    }

    auto [matched, cost, _1] = g.calc_cost_flow(s, t, [&](auto flow, auto, auto bottleneck, auto) {
        return min(k - flow, bottleneck);
    }, false);
    println(matched * int(2e6) - cost);
}