#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int k = __lg(n - 1);

    vector<int> ans;
    for (int i = n - 1; i >= 1 << k; i--) {
        cout << i << ' ';
    }
    for (int i = 0; i < 1 << k; i++) {
        cout << i << " \n"[i == (1 << k) - 1];
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