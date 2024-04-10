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

typedef long double ld;

ll solve(ll a, ll b, ll c, ll d) {
    if (a > b*c) return -1;
    if (d >= c) return a;
    ld x = ld(a)/(b*d)+0.5;
    ll ans = 0;
    debug(x);
    for (ll i = x-3; i < x+4; i++) {
        debug(i, a*i-i*(i-1)/2*b*d);
        ans = max(ans, a*i-i*(i-1)/2*b*d);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << "\n";
    }
}