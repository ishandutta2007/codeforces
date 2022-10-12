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

ll r0[100], r1[100];

void dfs(vector<ll>& a, ll k) {
    debug(a, k);
    vector<ll> b, c;
    ll y = 0, z = 0, r = 0, n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i]&1ll<<k) {
            y++, b.pb(a[i]);
            r1[k] += z;
        } else {
            z++, c.pb(a[i]);
            r0[k] += y;
        }
    }
    if (k > 0) {
        if (b.size()) dfs(b, k-1);
        if (c.size()) dfs(c, k-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll ans = 0, x = 0;
    dfs(a, 31);
    for (int i = 0; i < 32; i++) {
        ans += min(r1[i], r0[i]);
        debug(r0[i], r1[i]);
        if (r1[i] < r0[i]) x |= 1ll<<i;
    }
    cout << ans << " " << x << "\n";
}