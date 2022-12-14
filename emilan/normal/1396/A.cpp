#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<ll> a(n);
    for (ll& i : a) cin >> i;

    if (n == 1) {
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
        cout << "1 1\n" << -a[0];
    } else {
        cout << "1 " << n << '\n';
        for (int i = 0; i < n; i++) {
            ll x = (n - 1) - a[i] % (n - 1);
            a[i] += x * n;
            cout << x * n << ' ';
        }
        cout << '\n';

        cout << "1 1\n";
        cout << -a[0] << '\n';

        cout << "2 " << n << '\n';
        for (int i = 1; i < n; i++) {
            cout << -a[i] << ' ';
        }
    }
}