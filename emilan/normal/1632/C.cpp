#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int k = __lg(b) + 1;

    int ans = b - a;
    for (int y = b; y < 1 << k; y++) {
        int x = a;
        for (int i = 0; i < k; i++) {
            if (x >> i & 1 && ~y >> i & 1) {
                x += (1 << i) - (x & ((1 << i) - 1));
            }
        }
        ans = min(ans, x - a + y - b + (x != y));
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