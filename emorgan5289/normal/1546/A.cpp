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
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        ll ans = 0, x = 0, y = 0;
        vector<int> p, q;
        for (int i = 0; i < n; i++) {
            x += a[i], y += b[i];
            ll k = a[i]-b[i];
            for (int j = 0; j < k; j++) p.pb(i);
            for (int j = 0; j < -k; j++) q.pb(i);
        }
        if (x == y) {
            cout << p.size() << "\n";
            for (int i = 0; i < p.size(); i++)
                cout << p[i]+1 << " " << q[i]+1 << "\n";
        } else {
            cout << "-1\n";
        }
    }
}