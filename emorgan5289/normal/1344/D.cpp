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

const ll N = 1e5+5;
ll n, k;
ll a[N], p[N], b[N], c[N];

ll qry(ll i, ll x) {
    return x*(a[i]-x*x);
}

ll ch(ll d) {
    ll r = 0;
    for (ll i = 0; i < n; i++) {
        ll x, y;
        if (k >= 0)
            x = 0, y = a[i]-p[i];
        else
            x = 0, y = p[i];
        while (x < y) {
            ll m = (x+y)/2;
            if (qry(i, p[i]+max(0ll, m-1)*(k >= 0 ? 1ll : -1ll))-qry(i, p[i]+m*(k >= 0 ? 1ll : -1ll)) < d)
                x = m+1;
            else y = m;
        }
        b[i] = p[i]+x*(k >= 0 ? 1ll : -1ll), r += x;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = round(sqrt(double(a[i])/3));
        if (qry(i, p[i]) < qry(i, p[i]+1))
            p[i]++;
        if (qry(i, p[i]) < qry(i, p[i]-1))
            p[i]--;
        p[i] = max(0ll, min(p[i], a[i]));
        k -= p[i];
    }
    ll x = 0, y = 4e18;
    while (x < y) {
        ll m = (x+y)/2;
        if (ch(m) < abs(k))
            x = m+1;
        else y = m;
    }
    ch(x);
    if (k != 0) {
        if (ch(x) != abs(k)) {
            for (ll i = 0; i < n; i++)
                c[i] = b[i];
            ll r = abs(k)-ch(x-1);
            for (ll i = 0; i < n; i++) {
                if (r == 0) break;
                if (c[i] != b[i])
                    b[i] = c[i], r--;
            }
        }
    }
    for (ll i = 0; i < n; i++)
        cout << b[i] << " \n"[i == n-1];
}