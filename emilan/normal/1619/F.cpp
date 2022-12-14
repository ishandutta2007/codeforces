#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

int ceil_div(int n, int d) {
    return (n + d - 1) / d;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int i = 0;
    while (k--) {
        REP(p, n % m) {
            cout << ceil_div(n, m);
            REP(q, ceil_div(n, m)) {
                cout << ' ' << i + 1;
                i = (i + 1) % n;
            }
            cout << '\n';
        }
        int j = i;
        REP(p, m - n % m) {
            cout << n / m;
            REP(q, n / m) {
                cout << ' ' << j + 1;
                j = (j + 1) % n;
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
        cout << '\n';
    }
}