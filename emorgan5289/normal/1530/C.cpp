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
        sort(all(a));
        sort(all(b));
        debug(a), debug(b);
        for (int i = 1; i < n; i++)
            a[i] += a[i-1], b[i] += b[i-1];
        for (int i = 0; 1; i++) {
            int x = (n+i)/4-i, y = (n+i)/4;
            a.pb(100), b.pb(0);
            if (100*i+a[n-1]-(y <= 0 ? 0 : a[y-1]) >= b[n-1]-(x <= 0 ? 0 : b[x-1])) {
                cout << i << "\n";
                break;
            }
        }
    }
}