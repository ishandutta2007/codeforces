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
    int n, u;
    cin >> n >> u;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    double ans = -1;
    for (int l = 0, r = 2; l < n - 2; l++) {
        while (r < n - 1 && a[r + 1] - a[l] <= u) r++;
        if (a[r] - a[l] <= u && r - l >= 2) {
            ans = max(double(a[r] - a[l + 1]) / (a[r] - a[l]), ans);
        }
    }

    if (ans == -1) cout << -1;
    else cout << setprecision(10) << fixed << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}