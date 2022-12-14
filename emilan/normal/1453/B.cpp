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
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<int> d(n);
    adjacent_difference(all(a), d.begin());

    int mx = max(abs(d[1]), abs(d[n - 1]));
    for (int i = 2; i < n; i++) {
        if ((d[i - 1] ^ d[i]) < 0) {
            mx = max(mx, min(abs(d[i - 1]), abs(d[i])) * 2);
        }
    }

    cout << accumulate(1 + all(d), 0ll, [](ll x, int y) {
        return x + abs(y);
    }) - mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}