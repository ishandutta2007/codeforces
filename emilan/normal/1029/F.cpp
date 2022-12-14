#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
    i64 x, y;
    cin >> x >> y;

    i64 ans = LLONG_MAX;
    i64 x_r = x, y_r = y;
    for (int i = 1; i64(i) * i <= x + y; i++) {
        if (x % i == 0) x_r = x / i;
        if (y % i == 0) y_r = y / i;
        if ((x + y) % i == 0) {
            i64 j = (x + y) / i;
            if (x_r <= j || y_r <= j) {
                ans = min(ans, 2 * (i + j));
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}