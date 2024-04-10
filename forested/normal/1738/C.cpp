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
    
}

int main() {
    constexpr i32 mx = 100;
    
    i32 dp[2][2][mx + 1][mx + 1];
    REP(i, mx + 1) REP(j, mx + 1) REP(t, 2) REP(s, 2)  {
        if (j == 0) {
            if (t == 0) {
                dp[t][s][i][j] = (s == 0);
            } else {
                dp[t][s][i][j] = (s == 1);
            }
        } else if (i == 0) {
            dp[t][s][i][j] = !(dp[t ^ 1][s ^ (i32)(t == 0)][i][j - 1]);
        } else {
            dp[t][s][i][j] = !(dp[t ^ 1][s][i - 1][j]) || !(dp[t ^ 1][s ^ (i32)(t == 0)][i][j - 1]);
        }
    }
    
    i32 t = 1;
    cin >> t;
    REP(ti, t) {
        i32 n;
        cin >> n;
        Vec<i32> a(n);
        REP(i, n) {
            cin >> a[i];
        }
        
        i32 ev = 0;
        REP(i, n) {
            if (abs(a[i]) % 2 == 0) {
                ++ev;
            }
        }
        
        i32 alice = dp[0][0][ev][n - ev];
        cout << (alice ? "Alice\n" : "Bob\n");
    }
}