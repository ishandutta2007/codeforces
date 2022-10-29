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

void solve() {
    i64 n, m;
    cin >> n >> m;
    --m;
    
    const i64 d = 63;
    //const i64 d = 3;
    
    i64 dp[d][2][2][2];
    REP(i, d) REP(j, 2) REP(k, 2) REP(l, 2) {
        dp[i][j][k][l] = 0;
    }
    dp[0][1][0][0] = 1;
    REP(i, d - 1) REP(j, 2) REP(k, 2) REP(l, 2) {
        i64 ni = !!(n & (1LL << i));
        i64 mi = !!(m & (1LL << i));
        REP(nd, 2) {
            i64 nj = (j ? nd <= mi : nd < mi);
            i64 nk = k;
            i64 nl = 0;
            i64 add = ni + nd + l;
            if (add >= 2) {
                add -= 2;
                nl = 1;
            }
            if (nd != add) {
                nk ^= 1;
            }
            dp[i + 1][nj][nk][nl] += dp[i][j][k][l];
        }
        if (dp[i][j][k][l] != 0) {
            //cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l] << '\n';
        }
    }
    
    i64 ans = dp[d - 1][1][1][0] + dp[d - 1][1][1][1];
    cout << ans << '\n';
}

int main() {
    i32 t;
    cin >> t;
    REP(ti, t) {
        solve();
    }
}