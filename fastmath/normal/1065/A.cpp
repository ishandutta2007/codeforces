#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int s, a, b, c;
        cin >> s >> a >> b >> c;
        int ans = (a + b) * (s / (a * c));
        s %= (a * c);
        ans += s / c;
        cout << ans << '\n';
    }               

    return 0;
}