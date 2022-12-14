#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.rbegin(), a.rend());

    ll dist = 0;
    int p = 1;
    vector<int> ans(n + 1);
    for (auto [x, i] : a) {
        ans[i] = p;
        dist += 2ll * x * abs(p);

        if (p > 0) p = -p;
        else p = -p + 1;
    }

    cout << dist << "\n";
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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