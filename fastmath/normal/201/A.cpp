#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w;
    cin >> w;

    if (w == 3) {
        cout << "5\n";
        exit(0);
    }

    int n = 1;
    while (n * n / 2 + 1 < w) n += 2;
    cout << n << '\n';

    return 0;
}