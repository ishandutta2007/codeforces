#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    swap(n, m);

    if (n == 0) {
        cout << "No\n";
        exit(0);
    }

    if (n == 1 && m) {
        cout << "No\n";
        exit(0);
    }

    if (n % 2 == m % 2) {
        cout << "No\n";
        exit(0);
    }

    if (m < n - 1) {
        cout << "No\n";
        exit(0);
    }

    cout << "Yes\n";
    return 0;
}