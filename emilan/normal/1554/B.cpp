#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1ll << 60;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    ll ans = -INF;
    for (int i = max(n - 250, 0); i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, ll(i + 1) * (j + 1) - k * ll(a[i] | a[j]));
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