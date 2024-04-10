#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int n, int m, int k) {
    int t = min(n, m);
    n -= t;
    m -= t;
    if (k < t) return 0;
    int want = n + m;
    int have = k - t;
    return (n % 2 == 0 && m % 2 == 0 && want % 2 == have % 2);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int n, m, k;
        cin >> n >> m >> k;

        if (k < max(n, m)) {
            cout << "-1\n";
        }
        else {
            if (check(n, m, k)) cout << k << '\n';
            else if (check(n - 1, m, k - 1)) cout << k - 1 << '\n';
            else if (check(n, m - 1, k - 1)) cout << k - 1 << '\n';
            else if (check(n - 1, m - 1, k - 2)) cout << k - 2 << '\n';
            else exit(1);
        }
    }

    return 0;
}