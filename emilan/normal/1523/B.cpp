#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        cout << 3 * n << '\n';
        for (int i = 0; i < n; i += 2) {
            cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
            cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
            cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
            cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
            cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
            cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
        }
    }
}