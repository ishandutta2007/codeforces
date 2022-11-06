// Contest: Educational Codeforces Round 84 (Rated for Div. 2) (https://codeforces.com/contest/1327)
// Problem: G: Letters and Question Marks (https://codeforces.com/contest/1327/problem/G)


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

template <class T, size_t... Is> struct arr_helper;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<typename arr_helper<T, Is...>::type, I>; };
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;

template <class T, class C>
void fillrec(C& c, T val) {
    if constexpr (is_assignable_v<C&, T>)
        c = val;
    else
        trav(i, c) fillrec(i, val);
}

struct AhoCorasick {
    static constexpr int K = 14;
    struct Node {
        array<int, K> next;
        int link, len;
        ll cost = 0;
        Node(int len) : len(len) { next.fill(-1); }
    };

    vector<Node> t = {Node(0)};

    void add(string_view s, ll cost) {
        int v = 0;
        for (auto ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = sz(t);
                t.emplace_back(t[v].len + 1);
            }
            v = t[v].next[c];
        }
        t[v].cost += cost;
    }

    void finalize() {
        t[0].link = 0;
        for (queue<int> q{{0}}; sz(q); q.pop()) {
            int v = q.front(), l = t[v].link;
            rep(i, K) {
                int g = t[v].next[i], ln = (v ? t[l].next[i] : 0);
                if (g == -1)
                    t[v].next[i] = ln;
                else {
                    t[g].link = ln;
                    q.push(g);
                    t[g].cost += t[ln].cost;
                }
            }
        }
    }
};

arr<ll, 1u << 14, 1005> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;
    AhoCorasick aho;
    rep(i, k) {
        string s; ll c; cin >> s >> c;
        aho.add(s, c);
    }
    aho.finalize();

    string s; cin >> s;
    int n = sz(aho.t);
    int c = 0;
    vector<array<pair<int, ll>, 15>> walk(n);
    rep(i, n) rep(j, 15) walk[i][j] = {i, 0};
    {
        int i = 0;
        while (i < sz(s)) {
            int j = i;
            while (j < sz(s) && s[j] != '?')
                ++j;
            rep(y, n) {
                for (int x = i; x < j; ++x) {
                    walk[y][c].first = aho.t[walk[y][c].first].next[s[x] - 'a'];
                    walk[y][c].second += aho.t[walk[y][c].first].cost;
                }
            }
            ++c;
            i = j + 1;
        }
    }
    --c;
    if (s.back() == '?')
        ++c;
    if (c == 0)
        cout << walk[0][0].second << '\n', exit(0);

    fillrec(dp, -INFL);
    dp[0][walk[0][0].first] = walk[0][0].second;
    for (u32 m = 0; m < (1u << 14) - 1; ++m) {
        if (__builtin_popcount(m) >= c) {
            rep(i, 14) {
                if ((m >> i) & 1)
                    continue;
                auto m2 = m | (1u << i);
                rep(j, n)
                    dp[m2][j] = max(dp[m2][j], dp[m][j]);
            }
            continue;
        }
        int walknum = __builtin_popcount(m) + 1;
        rep(i, 14) {
            if ((m >> i) & 1)
                continue;
            auto m2 = m | (1u << i);
            rep(j, n) {
                int v = aho.t[j].next[i];
                auto [v2, co] = walk[v][walknum];
                dp[m2][v2] = max(dp[m2][v2], dp[m][j] + aho.t[v].cost + co);
            }
        }
    }

    ll mx = -INFL;
    rep(i, n)
        mx = max(mx, dp[(1u << 14) - 1][i]);
    cout << mx << '\n';

    return 0;
}