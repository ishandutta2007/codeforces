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

const ll N = 1e6+5;
ll n, q, m = 0, a[N];

void upd(ll i, ll k) {
    i ^= m; a[i+(1<<n)] = k;
    for (i = (i+(1<<n))/2; i > 0; i /= 2)
        a[i] = a[2*i]+a[2*i+1];
}

ll qry(ll l, ll r, ll i = 1, ll d = n) {
    if (l <= 0 && r >= (1<<d)-1) return a[i];
    if (l >= 1<<d || r < 0) return 0;
    ll x = (m>>d-1)&1, y = 1<<d-1;
    return qry(l, r, 2*i+x, d-1)+qry(l-y, r-y, 2*i+1-x, d-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1<<n; i < 1<<n+1; i++)
        cin >> a[i];
    for (int i = (1<<n)-1; i > 0; i--)
        a[i] = a[2*i]+a[2*i+1];
    while (q--) {
        ll t, x, k; cin >> t;
        if (t == 1) cin >> x >> k, upd(x-1, k);
        if (t == 2) cin >> k, m ^= (1<<k)-1;
        if (t == 3) cin >> k, m ^= 1<<k;
        if (t == 4) cin >> x >> k, cout << qry(x-1, k-1) << "\n";
    }
}