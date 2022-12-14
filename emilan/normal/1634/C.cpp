#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << '\n';
        }
    } else if (n & 1) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < k; j++) {
                cout << i * k + 2 * j + 1 << " \n"[j == k - 1];
            }
            for (int j = 0; j < k; j++) {
                cout << i * k + 2 * j + 2 << " \n"[j == k - 1];
            }
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