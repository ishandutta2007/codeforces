#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (s == string(s.rbegin(), s.rend())) {
        return 1;
    } else if (k >= 1) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}