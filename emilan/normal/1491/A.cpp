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
    int n, q;
    cin >> n >> q;

    int f = 0;
    vt<int> a(n);
    for (int &x : a) {
        cin >> x;
        f += x;
    }

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            x--;
            f -= a[x];
            a[x] ^= 1;
            f += a[x];
        } else {
            cout << (f >= x ? 1 : 0) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}