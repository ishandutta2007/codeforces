#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int w = i ^ j;
            ans += (j <= w && w < i + j && w <= n);
        }
    }

    cout << ans << '\n';
    return 0;
}