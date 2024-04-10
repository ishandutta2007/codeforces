#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n <= 2) {
        cout << "-1\n";
        exit(0);
    }

    int a = n * n;

    if (a % 2) {
        cout << a / 2 << ' ' << a / 2 + 1 << '\n';
    }
    else {
        cout << a / 4 - 1 << ' ' << a / 4 + 1 << '\n';
    }

    return 0;
}