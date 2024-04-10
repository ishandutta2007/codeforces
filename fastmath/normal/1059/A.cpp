#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int a[MAXN], b[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, x;
    cin >> n >> l >> x;

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }   

    int ans = 0;
    ans += a[0] / x;
    for (int i = 0; i < n - 1; ++i) {
        ans += (a[i + 1] - a[i] - b[i]) / x;
    }
    ans += (l - a[n - 1] - b[n - 1]) / x;
    cout << ans << '\n';

    return 0;
}