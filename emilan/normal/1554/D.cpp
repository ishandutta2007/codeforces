#include <bits/stdc++.h>

using namespace std;

using s = string;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 'a';
    } else if (n & 1) {
        cout << s(n / 2, 'a') << "bc" << s(n / 2 - 1, 'a');
    } else {
        cout << s(n / 2, 'a') << 'b' << s(n / 2 - 1, 'a');
    }
    cout << '\n';
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