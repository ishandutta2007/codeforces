#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &y : a) cin >> y;
    sort(a.begin(), a.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == x) {
            if (a[i] == a[n - 1]) {
                return cout << "NO\n", void();
            } else {
                swap(a[i], a[n - 1]);
                break;
            }
        }
    }

    cout << "YES\n";
    for (int y : a) cout << y << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}