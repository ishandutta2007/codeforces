#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> r(n);
    r[0] = a;
    r[n / 2] = b;
    int p = n;
    for (int i = 1; i < n / 2 && p > a; i++) {
        if (p == b) {
            if (--p == a) break;
        }
        r[i] = p--;
    }

    while (p == a || p == b) p--;

    for (int i = n / 2 + 1; i < n && p < b; i++) {
        if (p == a) p--;
        r[i] = p--;
    }

    if (count(r.begin(), r.end(), 0)) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << r[i] << " \n"[i == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}