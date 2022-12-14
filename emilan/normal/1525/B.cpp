#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    if (is_sorted(a.begin(), a.end())) cout << 0;
    else if (a[0] == 1 || a[n - 1] == n) cout << 1;
    else if (a[0] == n && a[n - 1] == 1) cout << 3;
    else cout << 2;
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