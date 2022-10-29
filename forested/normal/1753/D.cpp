#ifndef LOCAL
#define FAST_IO
#endif

// ============
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)
#define REP3(i, m, n) for (i32 i = (i32) (m); i < (i32) (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)
#define ALL(x) begin(x), end(x)

using namespace std;

using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;
using i32 = signed int;
using i64 = signed long long;
using i128 = __int128_t;
using f64 = double;
using f80 = long double;

template <typename T>
using Vec = vector<T>;

template <typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

istream &operator>>(istream &is, i128 &x) {
    i64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, i128 x) {
    os << (i64) x;
    return os;
}
istream &operator>>(istream &is, u128 &x) {
    u64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, u128 x) {
    os << (u64) x;
    return os;
}

[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;
struct SetUpIO {
    SetUpIO() {
#ifdef FAST_IO
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
#endif
        cout << fixed << setprecision(15);
    }
} set_up_io;
// ============

#ifdef DEBUGF
#else
#define DBG(x) (void) 0
#endif

int main() {
    i32 n, m;
    cin >> n >> m;
    i64 p, q;
    cin >> p >> q;
    Vec<string> s(n);
    REP(i, n) {
        cin >> s[i];
    }
    
    Vec<Vec<pair<i32, i64>>> g(n * m);
    REP(i, n) REP(j, m) {
        if (i + 1 < n && s[i][j] == 'U' && s[i + 1][j] == 'D') {
            if (i - 1 >= 0) {
                g[(i - 1) * m + j].emplace_back((i + 1) * m + j, q);
            }
            if (i + 2 < n) {
                g[(i + 2) * m + j].emplace_back(i * m + j, q);
            }
            if (j - 1 >= 0) {
                g[i * m + j - 1].emplace_back((i + 1) * m + j, p);
                g[(i + 1) * m + j - 1].emplace_back(i * m + j, p);
            }
            if (j + 1 < m) {
                g[i * m + j + 1].emplace_back((i + 1) * m + j, p);
                g[(i + 1) * m + j + 1].emplace_back(i * m + j, p);
            }
        }
        if (j + 1 < m && s[i][j] == 'L' && s[i][j + 1] == 'R') {
            if (j - 1 >= 0) {
                g[i * m + j - 1].emplace_back(i * m + j + 1, q);
            }
            if (j + 2 < m) {
                g[i * m + j + 2].emplace_back(i * m + j, q);
            }
            if (i - 1 >= 0) {
                g[(i - 1) * m + j].emplace_back(i * m + j + 1, p);
                g[(i - 1) * m + j + 1].emplace_back(i * m + j, p);
            }
            if (i + 1 < n) {
                g[(i + 1) * m + j].emplace_back(i * m + j + 1, p);
                g[(i + 1) * m + j + 1].emplace_back(i * m + j, p);
            }
        }
    }
    
    Vec<i64> dist(n * m, INF64);
    priority_queue<pair<i64, i32>> pq;
    REP(i, n) REP(j, m) {
        if (s[i][j] == '.') {
            dist[i * m + j] = 0;
            pq.emplace(0, i * m + j);
        }
    }
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        d *= -1;
        if (d > dist[v]) {
            continue;
        }
        for (auto [u, w] : g[v]) {
            if (chmin(dist[u], d + w)) {
                pq.emplace(-dist[u], u);
            }
        }
    }
    
    DBG(dist);
    
    i64 ans = INF64;
    REP(i, n) REP(j, m) {
        if (i + 1 < n) {
            chmin(ans, dist[i * m + j] + dist[(i + 1) * m + j]);
        }
        if (j + 1 < m) {
            chmin(ans, dist[i * m + j] + dist[i * m + j + 1]);
        }
    }
    if (ans == INF64) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}