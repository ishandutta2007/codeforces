#include <bits/stdc++.h>

using namespace std;

const int kInf = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int k;
    cin >> k;

    for (int &x : a) x -= k;

    int ans = n;
    for (int i = 1; i < n; i++) {
        int sum = a[i];
        for (int j = i - 1; j >= max(i - 3, 0); j--) {
            sum += a[j];
            if (sum < 0) {
                ans--;
                a[i] = kInf;
                break;
            }
        }
    }
    cout << ans << '\n';
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