#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    m++;

    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        bool N = n >> i & 1, M = m >> i & 1;
        if (N && !M) break;
        if (!N && M) ans |= 1 << i;
    }

    cout << ans << '\n';
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