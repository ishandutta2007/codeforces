#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      (a).begin(), (a).end()
#define RALL(a)     (a).rbegin(), (a).rend()

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

int solve() {
    int n, p;
    cin >> n >> p;
    for (int k = 1; k <= 30; k++) {
        int x = n - k * p;
        if (x < k) continue;
        if (__builtin_popcount(x) <= k) return k;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << '\n';
}