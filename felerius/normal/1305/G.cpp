// Contest: Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!) (https://codeforces.com/contest/1305)
// Problem: G: Kuroni and Antihype (https://codeforces.com/contest/1305/problem/G)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

struct DSU {
    vi p;
    int c;
    explicit DSU(int n) : p(n, -1), c(n) {}

    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    bool same(int i, int j) { return find(i) == find(j); }
    int size(int i) { return -p[find(i)]; }
    bool join(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return false;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j], p[j] = i, --c;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi a(n);
    trav(ai, a) cin >> ai;
    a.push_back(0);
    ++n;

    DSU dsu(n);
    ll res = 0;
    while (dsu.c > 1) {
        pi none(-1, -1);
        auto merge = [&](auto a, auto b) {
            auto [a1, a2] = a;
            auto [b1, b2] = b;
            auto best = max(a1, b1);
            auto secondbest = none;
            for (auto& p : {a1, a2, b1, b2})
                if (p.second != -1 && !dsu.same(best.second, p.second))
                    secondbest = max(secondbest, p);
            return pair(best, secondbest);
        };

        vector<pair<pi, pi>> dp(1u << 18, pair(none, none));
        rep(i, n)
            dp[a[i]] = merge(dp[a[i]], pair(pi(a[i], i), none));
        for (u32 m = 1; m < 1u << 18; ++m)
            rep(i, 18)
                dp[m] = merge(dp[m], dp[m & ~(1u << i)]);

        vpi best(n);
        rep(i, n) {
            auto [x, y] = dp[~(u32)a[i] & ((1u << 18) - 1)];
            auto partner = dsu.same(i, x.second) ? y : x;
            if (partner.second != -1)
                best[dsu.find(i)] = max(best[dsu.find(i)], pair(partner.first + a[i], dsu.find(partner.second)));
        }

        rep(i, n) {
            if (dsu.find(i) != i)
                continue;
            if (dsu.join(i, best[i].second))
                res += best[i].first;
        }
    }

    trav(ai, a)
        res -= ai;
    cout << res << '\n';

    return 0;
}