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

// ============

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include <functional>

template <typename T, typename F = std::less<T>>
class SparseTable {
    std::vector<std::vector<T>> table;
    int s;
    const F f;

    int log2(int n) const {
        return 31 - __builtin_clz(n);
    }
    
    T min2(const T &x, const T &y) const {
        if (f(x, y)) {
            return x;
        } else {
            return y;
        }
    }

public:
    SparseTable(std::vector<T> arr, const F &f = F()) : s((int) arr.size()), f(f) {
        if (s == 0) {
            return;
        }
        int m = log2(s);
        table.resize(m + 1);
        table[0] = std::move(arr);
        for (int i = 1; i <= m; ++i) {
            int w = 1 << i;
            table[i].resize(s - w + 1);
            for (int j = 0; j < (int) table[i].size(); ++j) {
                table[i][j] = min2(table[i - 1][j], table[i - 1][j + (w >> 1)]);
            }
        }
    }

    int size() const {
        return s;
    }

    // not empty
    T min(int l, int r) const {
        assert(l >= 0 && l < r && r <= s);
        int m = log2(r - l);
        return min2(table[m][l], table[m][r - (1 << m)]);
    }
};

// ============

bool possible(i32 n, i32 k, Vec<i64> a) {
    Vec<i64> sum(n + 1, 0);
    REP(i, n) {
        sum[i + 1] = sum[i] + a[i];
    }
    
    Vec<i32> lft(n, -1), rgt(n, n);
    REP(i, 1, n) {
        i32 cur = i - 1;
        while (cur != -1 && sum[cur] > sum[i]) {
            cur = lft[cur];
        }
        lft[i] = cur;
    }
    PER(i, n - 1) {
        i32 cur = i + 1;
        while (cur != n && sum[cur + 1] < sum[i + 1]) {
            cur = rgt[cur];
        }
        rgt[i] = cur;
    }
    
    SparseTable<i64> mn(sum);
    SparseTable<i64, greater<i64>> mx(sum);
    
    Vec<i64> lft_cost(n, -1), rgt_cost(n, -1);
    REP(i, 1, n) {
        if (lft[i] != -1) {
            lft_cost[i] = mx.min(lft[i], i + 1) - sum[i];
        }
    }
    REP(i, n - 1) {
        if (rgt[i] != n) {
            rgt_cost[i] = sum[i + 1] - mn.min(i, rgt[i] + 1);
        }
    }
    
    DBG(a);
    DBG(sum);
    DBG(lft);
    DBG(rgt);
    DBG(lft_cost);
    DBG(rgt_cost);
    
    i32 l = k, r = k;
    i64 h = a[k];
    while (l > 0) {
        bool ch = false;
        while (l > 0 && lft[l] != -1 && lft_cost[l] <= h) {
            h += sum[l] - sum[lft[l]];
            l = lft[l];
            ch = true;
        }
        while (r < n - 1 && rgt[r] != n && rgt_cost[r] <= h) {
            h += sum[rgt[r] + 1] - sum[r + 1];
            r = rgt[r];
            ch = true;
        }
        if (!ch) {
            break;
        }
    }
    while (l > 0 && h + a[l - 1] >= 0) {
        h += a[l - 1];
        --l;
    }
    return l == 0;
}

void solve() {
    i32 n, k;
    cin >> n >> k;
    --k;
    Vec<i64> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    bool ans = false;
    if (possible(n, k, a)) {
        ans = true;
    }
    k = n - 1 - k;
    reverse(ALL(a));
    if (possible(n, k, a)) {
        ans = true;
    }
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    i32 t;
    cin >> t;
    REP(ti, t) {
        solve();
    }
}