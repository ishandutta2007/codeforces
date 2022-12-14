#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int o = 0, e = 0;
    for (int d = 1; n > 0; d *= 10) {
        o += n % 10 * d;
        n /= 10;

        e += n % 10 * d;
        n /= 10;
    }

    cout << (o + 1) * (e + 1) - 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}