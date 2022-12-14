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

    vt<pii> p;
    int d = n;
    for (int i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            p.emplace_back(i, 0);
            while (d % i == 0) {
                p.back().se++;
                d /= i;
            }
        }
    }
    if (d != 1) p.emplace_back(d, 1);

    if (sz(p) > 0 && p[0].se >= 6) {
        int x = p[0].fi;
        cout << "YES\n";
        cout << x << ' ' << x * x << ' ' << n / x / x / x;
    } else if ((sz(p) > 1 && p[0].se + p[1].se >= 4) || sz(p) > 2) {
        int x = p[0].fi, y = p[1].fi;
        cout << "YES\n";
        cout << x << ' ' << y << ' ' << n / x / y;
    } else {
        cout << "NO";
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