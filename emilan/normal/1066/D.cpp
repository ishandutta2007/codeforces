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
    int n, m, k;
    cin >> n >> m >> k;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, r = n - 1;
    while (l < r) {
        int mi = (l + r) / 2;

        int i = mi;
        for (int j = 0; j < m && i < n; j++) {
            int cur = 0;
            while (i < n && cur + a[i] <= k) {
                cur += a[i];
                i++;
            }
        }

        if (i < n) l = mi + 1;
        else r = mi;
    }

    cout << n - l;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}