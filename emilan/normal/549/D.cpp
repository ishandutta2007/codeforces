#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vt<vt<int>> a(n, vt<int>(m));
    for (auto &v : a) {
        cin >> ws;
        for (int &x : v) {
            char c;
            cin >> c;
            x = 2 * (c == 'W') - 1;
        }
    }

    vt<vt<int>> lazy(n, vt<int>(m));
    int ans = 0;
    for (int i = n - 1; ~i; i--) {
        for (int j = m - 1; ~j; j--) {
            if (a[i][j] + lazy[i][j]) {
                lazy[i][j] = -a[i][j];
                ans++;
            }

            if (i) lazy[i - 1][j] += lazy[i][j];
            if (j) lazy[i][j - 1] += lazy[i][j];
            if (i && j) lazy[i - 1][j - 1] -= lazy[i][j];
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}