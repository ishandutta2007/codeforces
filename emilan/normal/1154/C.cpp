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
    vt<int> a(3);
    for (int &x : a) cin >> x;

    int ans = 0;
    for (int s = 0; s < 7; s++) {
        vt<int> b(a);
        for (int i = s; i < 7; i++) {
            if (i == 0 || i == 3 || i == 6) b[0]--;
            else if ( i == 1 || i == 5) b[1]--;
            else b[2]--;

            if (!~b[0] || !~b[1] || !~b[2]) {
                ans = max(ans, i - s);
                break;
            }
        }

        if (!~b[0] || !~b[1] || !~b[2]) continue;

        int weeks = min({b[0] / 3, b[1] / 2, b[2] / 2});
        b[0] -= weeks * 3;
        b[1] -= weeks * 2;
        b[2] -= weeks * 2;

        for (int i = 0; i < 7; i++) {
            if (i == 0 || i == 3 || i == 6) b[0]--;
            else if ( i == 1 || i == 5) b[1]--;
            else b[2]--;

            if (!~b[0] || !~b[1] || !~b[2]) {
                ans = max(ans, 7 - s + weeks * 7 + i);
                break;
            }
        }

        if (!~b[0] || !~b[1] || !~b[2]) continue;

        ans = max(ans, 7 - s + weeks * 7 + 7);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}