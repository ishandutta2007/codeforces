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
        vector<ll> a(n+2);
        ll ans = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i+1];
        for (int i = 0; i < n+1; i++)
            ans += abs(a[i]-a[i+1]);
        for (int i = 1; i < n+1; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1])
                ans -= a[i]-max(a[i-1], a[i+1]);
        }
        cout << ans << "\n";
    }
}