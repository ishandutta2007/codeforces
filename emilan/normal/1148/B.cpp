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

#define die return void(cout << -1)

void solve() {
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;

    if (k >= min(n, m)) die;

    vt<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int j = lower_bound(all(b), a[i] + ta) - b.begin();
        j += k - i;
        if (j >= m) die;

        ans = max(ans, b[j] + tb);
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