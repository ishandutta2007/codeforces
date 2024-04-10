#ifndef LOCAL
#define FAST_IO
#endif

// ===== template.hpp =====
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
// ===== template.hpp =====

#ifdef DEBUGF
#include "cpl/template/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

void solve() {
    i32 n;
    cin >> n;
    Vec<i32> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    Vec<i32> b(n);
    REP(i, n) {
        cin >> b[i];
    }
    
    Vec<i32> fw(n, 0), bw(n, 0);
    REP(i, n - 1) {
        if (a[i] <= b[i + 1]) {
            fw[i] = 1;
        }
    }
    REP(i, 1, n) {
        if (a[i] <= b[i - 1]) {
            bw[i] = 1;
        }
    }
    Vec<i32> fwsum(n + 1), bwsum(n + 1);
    REP(i, n) {
        fwsum[i + 1] = fwsum[i] + fw[i];
        bwsum[i + 1] = bwsum[i] + bw[i];
    }
    
    REP(i, n) {
        i32 ok = i, ng = -1;
        while (ok - ng > 1) {
            i32 mid = (ok + ng) / 2;
            if (b[mid] >= a[i] && fwsum[i] - fwsum[mid] == i - mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << b[ok] - a[i] << " \n"[i + 1 == n];
    }
    REP(i, n) {
        i32 ok = i, ng = n;
        while (ng - ok > 1) {
            i32 mid = (ok + ng) / 2;
            if (bwsum[mid + 1] - bwsum[i + 1] == mid - i) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << b[ok] - a[i] << " \n"[i + 1 == n];
    }
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}