#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <ll> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vector <ll> y(m);
    for (int i = 0; i < m; ++i) cin >> y[i];
    ll g = 0;
    for (int i = 1; i < n; ++i) {
        g = gcd(g, x[i] - x[i - 1]);
    }
    for (int i = 0; i < m; ++i) {
        if (g % y[i] == 0) {
            cout << "YES\n";
            cout << x[0] << ' ' << i + 1 << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}