#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e17;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 1e4+5;
ll p[N], a[N], dp0[N], dp1[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, c; cin >> n >> c;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        cin >> p[i], ans += p[i];
    for (ll i = 0; i < n; i++)
        cin >> a[i], a[i] -= p[i];
    fill(dp0, dp0+n+1, inf_ll);
    dp0[0] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 1, k = c; j <= n; j++, k += c)
            dp1[j] = min(dp0[j]+k, dp0[j-1]+a[i]);
        copy(dp1+1, dp1+n+1, dp0+1);
    }
    cout << ans+*min_element(dp0, dp0+n+1) << "\n";
}