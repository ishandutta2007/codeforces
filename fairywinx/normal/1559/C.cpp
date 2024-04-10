#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (a[0] == 1) {
        cout << n + 1 << ' ';
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    if (a[n - 1] == 0) {
        for (int i = 1; i <= n + 1; ++i)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 0 && a[i + 1] == 1) {
            for (int j = 1; j <= i + 1; ++j)
                cout << j << ' ';
            cout << n + 1 << ' ';
            for (int j = i + 2; j <= n; ++j)
                cout << j << ' ';
            cout << '\n';
            return;
        }
    }
    exit(1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}