#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

ll a[100100];
ll X[100100], Y[100100];

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1) {
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        gcd(n, n - 1, X[i], Y[i]);
        X[i] *= -a[i];
        Y[i] *= -a[i];
    }

    cout << 1 << " " << n << endl;
    cout << 0; for (int i = 1; i < n; ++i) cout << ' ' << X[i] * n; cout << endl;

    cout << "1 1" << endl;
    cout << -a[0] << endl;

    cout << 2 << " " << n << endl;
    for (int i = 1; i < n; ++i) {
        if (i > 1) cout << ' ';
        cout << Y[i] * (n - 1);
    }
    cout << endl;
}