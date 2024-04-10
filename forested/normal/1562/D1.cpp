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
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (n); ++i)
#define REP3(i, m, n) for (i32 i = (m); i < (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (n) - 1; i >= 0; --i)
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

[[maybe_unused]] constexpr i32 inf = 1000000100;
[[maybe_unused]] constexpr i64 inf64 = 3000000000000000100;

struct SetIO {
    SetIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} set_io;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        Vec<i32> sum(n + 1, 0);
        REP(i, n) {
            i32 p;
            if (s[i] == '+') p = 1;
            else p = -1;
            if (i & 1) p *= -1;
            sum[i + 1] = sum[i] + p;
        }
        while (q--) {
            i32 l, r;
            cin >> l >> r;
            --l;
            if ((r - l) & 1) {
                cout << "1\n";
            } else if (sum[r] - sum[l] == 0) {
                cout << "0\n";
            } else {
                cout << "2\n";
            }
        }
    }
}