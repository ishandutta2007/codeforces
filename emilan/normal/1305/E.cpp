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

    vt<int> ans;
    for (int i = 0; i < n && m; i++) {
        if (m >= i / 2) {
            ans.push_back(i + 1);
            m -= i / 2;
        } else if (m) {
            ans.push_back(i + 1 + 2 * (i / 2 - m));
            m = 0;
        }
    }

    for (int i = sz(ans); i < n; i++) {
        ans.push_back(100000 * i + 99999);
    }

    if (m) cout << -1;
    else for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}