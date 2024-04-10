#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            s[i] = 'U';
        } else if (s[i] == 'U') {
            s[i] = 'D';
        }
    }

    cout << s << '\n';
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