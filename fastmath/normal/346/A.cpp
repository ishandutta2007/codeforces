#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int mx = -1;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d = __gcd(d, a[i]);
        mx = max(mx, a[i]);
    }

    int h = mx / d - n;
    if (h % 2) cout << "Alice\n";
    else cout << "Bob\n";

    return 0;
}