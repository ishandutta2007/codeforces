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

constexpr i32 MAX = 100000;
array<bool, MAX + 1> prime;

void sieve() {
    fill(ALL(prime), true);
    prime[1] = false;
    for (i32 i = 2; i <= MAX; ++i) {
        if (!prime[i]) continue;
        for (i32 j = i * 2; j <= MAX; j += i) prime[j] = false;
    }
}

array<array<i32, 10>, MAX + 1> dcnt;
array<i32, MAX + 1> digits;

void count() {
    REP(i, MAX + 1) {
        fill(ALL(dcnt[i]), 0);
        i32 cur = i;
        digits[i] = 0;
        while (cur) {
            ++dcnt[i][cur % 10];
            cur /= 10;
            ++digits[i];
        }
    }
}

// s is in t
bool issubstr(const string &s, const string &t) {
    i32 idx = 0;
    for (char c : t) {
        if (c == s[idx]) {
            if (++idx == s.size()) return true;
        }
    }
    return false;
}

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    
    string t;
    for (char c : s) {
        int n = c - '0';
        if (n != 2 && n != 3 && n != 5 && n != 7) {
            cout << "1\n" << n << "\n";
            return;
        }
        t.push_back(c);
    }
    
    REP(i, 1, t.size()) {
        int n = t[i] - '0';
        if (n == 2 || n == 5) {
            cout << "2\n" << t[0] << n << '\n';
            return;
        }
    }
    
    REP(i, 1, MAX + 1) {
        if (prime[i]) continue;
        if (issubstr(to_string(i), t)) {
            cout << digits[i] << "\n" << i << "\n";
            return;
        }
    }
    assert(false);
}

int main() {
    int t;
    cin >> t;
    sieve();
    count();
    while (t--) solve();
}