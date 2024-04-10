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

void solve() {
    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << "0\n";
    } else if (r == 1) {
        REP(j, c) cout << j + 2 << " \n"[j == c - 1];
    } else if (c == 1) {
        REP(i, r) cout << i + 2 << '\n';
    } else {
        REP(j, c) cout << j + 2 << " \n"[j == c - 1];
        for (int i = 1; i < r; i++) {
            REP(j, c) cout << (c + i + 1) * (j + 2) << " \n"[j == c - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}