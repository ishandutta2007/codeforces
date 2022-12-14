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
    int n, u, v;
    cin >> n >> u >> v;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    if (count(all(a), a[0]) == n) cout << min(v * 2, u + v);
    else {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) > 1) ok = false;
        }

        if (ok) cout << min(u, v);
        else cout << 0;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}