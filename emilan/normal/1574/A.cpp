#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) s += "()";
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            swap(s[2 * i - 1], s[2 * i]);
        }
        cout << s << '\n';
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