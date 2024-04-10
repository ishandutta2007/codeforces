#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].resize(i + 1);
        ans[i][i] = a[i];
    }

    vector<pii> p(n);
    for (int i = 0; i < n; i++) p[i] = {i, i};

    vector<int> cnt(a);
    for (int t = 0; t < n * (n + 1) / 2; t++) {
        for (int i = 0; i < n; i++) if (cnt[i] > 1) {
            auto &[x, y] = p[i];

            int d = x < n - 1 && ans[x + 1][y] == 0;
            int u = x && y < x && ans[x - 1][y] == 0;
            int l = y && ans[x][y - 1] == 0;
            int r = y < x && ans[x][y + 1] == 0;

            if (d + u + l + r == 1) {
                if (d) x++;
                if (u) x--;
                if (l) y--;
                if (r) y++;

                ans[x][y] = a[i];
                cnt[i]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (count(ans[i].begin(), ans[i].end(), 0)) {
            return cout << -1, void();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int x : ans[i]) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    while (tcs--) {
        solve();
    }
}