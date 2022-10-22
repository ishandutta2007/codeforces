#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mx = -1;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += mx - a[i];
    }

    if (m <= sum) {
        cout << mx << ' ';
    }
    else {
        cout << mx + (m - sum - 1) / n + 1 << ' ';
    }

    cout << mx + m << '\n';

    return 0;
}