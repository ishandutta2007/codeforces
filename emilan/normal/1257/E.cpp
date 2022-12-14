#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    vector<int> m(3);
    for (int &x : m) cin >> x;
    int n = accumulate(m.begin(), m.end(), 0);
    vector<int> a(n + 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < m[i]; j++) {
            int p;
            cin >> p;
            a[p] = i;
        }
    }

    int l = m[1] + m[2];
    int r = m[1] + m[2];
    int ans = m[1] + m[2];
    for (int i = n; i > 0; i--) {
        if (a[i] == 0) l++, r++;
        if (a[i] == 1) r--;
        if (a[i] == 2) l--;

        r = min(r, l);
        ans = min(ans, r);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}