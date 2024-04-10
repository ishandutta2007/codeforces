#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> a(n);
    for (auto &v : a) {
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            v.insert(x);
        }
    }

    vector<vector<int>> ans(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (*a[i].begin() < *a[k].begin()) k = i;
        }
        ans[k][j] = *a[k].begin();
        a[k].erase(a[k].begin());

        for (int i = 0; i < n; i++) if (i != k) {
            ans[i][j] = *a[i].rbegin();
            a[i].erase(--a[i].end());
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
}