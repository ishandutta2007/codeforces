// Contest: Educational Codeforces Round 87 (Rated for Div. 2) (https://codeforces.com/contest/1354)
// Problem: E: Graph Coloring (https://codeforces.com/contest/1354/problem/E)


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

template <class T, class... Is> struct vec_helper;
template <class T>
struct vec_helper<T> {
    static auto f(T val) { return val; }
};
template <class T, class I, class... Is>
struct vec_helper<T, I, Is...> {
    static auto f(T val, I size, Is... sizes) {
        return vector(size, vec_helper<T, Is...>::f(val, sizes...));
    }
};
template <class T, class... Is>
auto vec(T val, Is... sizes) {
    return vec_helper<T, Is...>::f(val, sizes...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, n1, n2, n3; cin >> n >> m >> n1 >> n2 >> n3;
    vvi adj(n);
    rep(i, m) {
        int u, v; cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi col(n, -1);
    vector<array<int, 3>> comp;
    rep(i, n) {
        if (col[i] != -1)
            continue;
        comp.push_back({i, 1, 0});
        col[i] = 1;
        queue<int> q;
        q.push(i);
        while (sz(q)) {
            int v = q.front();
            q.pop();
            for (auto v2 : adj[v]) {
                if (col[v2] == -1)
                    col[v2] = 3 - col[v], comp.back()[col[v2]]++, q.push(v2);
                else if (col[v2] == col[v])
                    cout << "NO\n", exit(0);
            }
        }
    }

    auto dp = vec(-1, sz(comp) + 1, n2 + 1);
    dp[0][0] = 1;
    rep(i, sz(comp)) {
        auto[_, c1, c2] = comp[i];
        rep(j, n2 + 1) {
            if (j >= c1 && dp[i][j - c1] != -1)
                dp[i + 1][j] = 0;
            else if (j >= c2 && dp[i][j - c2] != -1)
                dp[i + 1][j] = 1;
        }
    }

    if (dp[sz(comp)][n2] == -1)
        cout << "NO\n", exit(0);

    int x = n2;
    vector<bool> invdone(n);
    for (int i = sz(comp); i; --i) {
        auto col2 = dp[i][x];
        if (x)
            x -= comp[i - 1][col2 + 1];
        if (!col2) {
            int v0 = comp[i - 1][0];
            col[v0] = 3 - col[v0];
            queue<int> q;
            q.push(v0);
            invdone[v0] = true;
            while (sz(q)) {
                int v = q.front();
                q.pop();
                for (auto v2 : adj[v])
                    if (!invdone[v2])
                        col[v2] = 3 - col[v2], invdone[v2] = true, q.push(v2);
            }
        }
    }

    rep(i, n)
        if (n3 && col[i] == 1)
            col[i] = 3, --n3;

    cout << "YES\n";
    trav(ci, col)
        cout << ci;
    cout << '\n';

    return 0;
}