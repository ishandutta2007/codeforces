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
    int n, x;
    string s;
    cin >> n >> x >> s;

    vt<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int d = s[i] == '0' ? 1 : -1;
        a[i + 1] = a[i] + d;
    }
    int c = a[n];

    map<int, int> d;
    if (c < 0) {
        c = -c;
        x = -x;
        for (int i = 0; i < n; i++) {
            d[-a[i]]++;
        }
    } else {
        for (int i = 0; i < n; i++) {
            d[a[i]]++;
        }

        if (!c) {
            if (d[x]) cout << -1;
            else cout << 0;
            cout << '\n';

            return;
        }
    }

    int st = max((x - d.rbegin()->fi + c - 1) / c * c, 0),
        en = x - d.begin()->fi;
    ll ans = 0;
    for (int i = st; i <= en; i += c) {
        if (d.count(x - i)) ans += d[x - i];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}