#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<ll> a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, d, m; cin >> n >> d >> m;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (x > m) b.pb(x);
        else a.pb(x);
    }
    sort(all(a), greater<>()), sort(all(b), greater<>());
    for (int i = 1; i < a.size(); i++)
        a[i] += a[i-1];
    for (int i = 1; i < b.size(); i++)
        b[i] += b[i-1];
    ll ans = -inf_ll;
    for (int i = 0; i < d; i++)
        a.pb(a.empty() ? 0 : a.back());
    for (int i = 0; i <= b.size(); i++) {
        if (i == 0) {
            if (a.size() >= n) ans = a[n-1];
        } else {
            ll j = n-1-(d+1)*(i-1);
            if (j <= a.size())
                ans = max(ans, b[i-1]+(j == 0 ? 0 : a[j-1]));
        }
    }
    cout << ans << "\n";
}