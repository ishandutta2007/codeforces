// ===== template.hpp =====
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
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

[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;

struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} fast_io;
// ===== template.hpp =====

#ifdef DEBUGF
#include  "../new_library/other/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

void solve() {
    i32 n;
    cin >> n;
    Vec<i32> a(n), b(n);
    REP(i, n) {
        cin >> a[i];
        --a[i];
    }
    REP(i, n) {
        cin >> b[i];
        --b[i];
    }
    
    Vec<i32> cnt(n, 0);
    i32 it = 0;
    REP(i, n) {
        while (it < n && a[it] != b[i]) {
            ++cnt[a[it]];
            ++it;
        }
        if (it == n) {
            cout << "NO\n";
            return;
        }
        ++it;
        while (i < n - 1 && b[i + 1] == b[i] && cnt[b[i]] > 0) {
            ++i;
            --cnt[b[i]];
        }
    }
    cout << "YES\n";
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}