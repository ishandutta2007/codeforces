// Contest: Codeforces Round #644 (Div. 3) (https://codeforces.com/contest/1360)
// Problem: E: Polygon (https://codeforces.com/contest/1360/problem/E)


// region boilerplate
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
//endregion

// region dimvec
template <class T, class... Is> struct vec_helper;
template <class T> struct vec_helper<T> { static auto f(T val) { return val; } };
template <class T, class I, class... Is> struct vec_helper<T, I, Is...> {
    static auto f(T val, I size, Is... sizes) {
        return vector(size, vec_helper<T, Is...>::f(val, sizes...));
    }
};
template <class T, class... Is> auto vec(T val, Is... sizes) { return vec_helper<T, Is...>::f(val, sizes...); }
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    string l;
    while (t--) {
        int n; cin >> n;
        auto g = vec(0, n, n);
        trav(row, g) {
            cin >> l;
            rep(i, n)
                row[i] = l[i] - '0';
        }
        auto vis = vec(false, n, n);
        queue<pi> q;
        rep(i, n) {
            if (g[i][n-1])
                vis[i][n-1] = true, q.emplace(i, n-1);
            if (g[n-1][i])
                vis[n-1][i] = true, q.emplace(n-1, i);
        }
        while (sz(q)) {
            auto [x, y] = q.front(); q.pop();
            if (x && g[x-1][y] && !vis[x-1][y])
                vis[x-1][y] = true, q.emplace(x-1,y);
            if (y && g[x][y-1] && !vis[x][y-1])
                vis[x][y-1] = true, q.emplace(x,y-1);
        }
        bool a = true;
        rep(i, n) rep(j, n)
            a &= !g[i][j] || vis[i][j];
        cout << (a ? "YES\n" : "NO\n");
    }

    return 0;
}