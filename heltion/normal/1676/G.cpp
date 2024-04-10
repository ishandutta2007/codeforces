#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 2; i <= n; i += 1)
            cin >> a[i];
        string s;
        cin >> s;
        s = " " + s;
        int ans = 0;
        for (int i = n; i >= 1; i -= 1) {
            if (s[i] == 'W') b[i] += 1;
            else b[i] -= 1;
            ans += b[i] == 0;
            b[a[i]] += b[i];
        }
        cout << ans << "\n";
    }
}