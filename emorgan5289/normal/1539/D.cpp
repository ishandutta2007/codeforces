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
    ll n; cin >> n;
    vector<array<ll, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][1] >> a[i][0];
    sort(all(a));
    ll l = 0, r = n-1;
    ll x = 0, ans = 0;
    vector<ll> v(n, 0);
    debug(a);
    while (l <= r) {
        if (x >= a[l][0]) {
            ans += a[l][1]-v[l];
            x += a[l][1]-v[l];
            v[l] = a[l][1];
            l++;
        } else if (a[l][0]-x < a[r][1]-v[r]) {
            ll y = a[l][0]-x;
            x += y;
            ans += 2*y;
            v[r] += y;
        } else {
            ans += 2*(a[r][1]-v[r]);
            x += a[r][1]-v[r];
            v[r] = a[r][1];
            r--;
        }
        debug(ans);
        debug(v);
    }
    cout << ans << "\n";
}