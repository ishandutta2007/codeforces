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
        ll n, h; cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = max_element(all(a))-a.begin();
        int j = -1;
        for (int k = 0; k < n; k++)
            if (k != i) {
                if (j == -1 || a[k] > a[j]) j = k;
            }
        ll ans = 2*(h/(a[i]+a[j]));
        h %= (a[i]+a[j]);
        if (h > 0) h -= a[i], ans++;
        if (h > 0) ans++;
        cout << ans << "\n";
    }
}