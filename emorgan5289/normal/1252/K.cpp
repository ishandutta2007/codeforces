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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    map<ll, ll> f;
    for (ll x : a) f[x]++;
    for (auto& [x, y] : f)
        if (y >= k) cout << "0\n", exit(0);
    reverse(all(a));
    for (ll& x : a) x = -x;
    ll s = 0, ans = inf_ll;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (i >= k-1) cmin(ans, (i+1)*a[i]-s-(i-k+1));
    }
    reverse(all(a));
    for (ll& x : a) x = -x;
    s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        debug(a[i], k, s);
        if (i >= k-1) cmin(ans, (i+1)*a[i]-s-(i-k+1));
    }
    s = 0;
    for (ll x : a) s += abs(x-a[n/2]);
    cmin(ans, s-(n-k));
    cout << ans << "\n";
}