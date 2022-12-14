#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> s(a);
    sort(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        if (a[i] != s[i] && n - x <= i && i < x) {
            cout << "nO\n";
            return;
        }
    }

    cout << "yES\n";
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