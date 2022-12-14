#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    auto f = [&]() { return x > y ? x + y : y - y % x / 2; };
    cout << f() << '\n';
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