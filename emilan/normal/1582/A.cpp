#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x + z) % 2 << '\n';
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