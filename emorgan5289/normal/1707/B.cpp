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
        vector<ll> a(n), b(n-1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0) {
                b[i-1] = a[i]-a[i-1];
            }
        }
        sort(all(b));

        if (n == 2) {
            cout << b[0] << "\n";
            continue;
        }

        ll z = 0;
        vector<ll> c;
        for (int i = 0; i < n-2; i++) {
            if (b[i] == b[i+1]) z++;
            else c.pb(b[i+1]-b[i]);
        }
        sort(all(c), greater<>());
        while (z+c.size() > 1) {
            debug(c, z);
            for (int i = 0; i+1 < c.size(); i++)
                c[i] -= c[i+1];
            if (z == 0)
                c.pop_back();
            else z--;
            sort(all(c), greater<>());
        }
        cout << (z > 0 ? 0 : c[0]) << "\n";
    }
}