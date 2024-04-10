#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        a += '0', b += '0';
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            x[i] = a[i] != a[i+1];
            y[i] = b[i] != b[i+1];
        }
        debug(x);
        debug(y);
        vector<int> p, q;
        for (int i = 0; i < n; i++) {
            if (x[i]) p.pb(i);
            if (y[i]) q.pb(i);
        }
        if (p.size() == q.size() && x[n-1] == y[n-1]) {
            ll ans = 0;
            for (int i = 0; i < p.size(); i++) {
                ans += abs(q[i]-p[i]);
            }
            cout << ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
}