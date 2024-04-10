#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (n == 4) {
        cout << "-1\n";
        exit(0);
    }

    if (k < n + 1) {
        cout << "-1\n";
        exit(0);
    }

    vector <int> v;
    for (int i = 0; i < n; ++i) {
        if (i + 1 != a && i + 1 != b && i + 1 != c && i + 1 != d) {
            v.push_back(i);
        }   
    }

    cout << a << ' ' << c << ' ';
    for (int e : v) cout << e + 1 << ' ';
    cout << d << ' ' << b << '\n';

    cout << c << ' ' << a << ' ';
    for (int e : v) cout << e + 1 << ' ';
    cout << b << ' ' << d << '\n';

    return 0;
}