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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    sort(all(a));
    ll k = pow(double(1e16), 1/double(n));
    ll ans = inf_ll;
    for (int c = 1; c <= k; c++) {
        ll r = 0, b = 1;
        for (int i = 0; i < n; i++)
            r += abs(b-a[i]), b *= c;
        ans = min(ans, r);
    }
    cout << ans << "\n";
}