#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll i = 1, t = 0;
    for (; i < n && i <= k; i *= 2, t++);
    if (i < n) t += (n - i + k - 1) / k;

    cout << t << '\n';
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