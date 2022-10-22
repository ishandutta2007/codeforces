#include <bits/stdc++.h>

using namespace std;

string a, b;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (a[i] != b[i]);
    }

    int u = 0;
    while (u < n - 1) {
        if (a[u] != b[u] && a[u + 1] != b[u + 1] && a[u] != a[u + 1]) {
            --ans;
            u += 2;
        }
        else {
            ++u;
        }
    }

    cout << ans << '\n';
    return 0;
}