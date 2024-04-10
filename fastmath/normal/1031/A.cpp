#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += 2 * (n + m) - 4;
        n -= 4;
        m -= 4;
    }

    cout << ans << '\n';
    return 0;
}