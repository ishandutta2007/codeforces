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

const int N = 6e5+5;
ll a[N], b[N];
pair<int, int> u[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b, b+n); sort(a, a+n);
    for (int i = 0; i < n; i++)
        b[i+n] = b[i]+m, b[i+2*n] = b[i]+2*m;
    ll x = 0, y = m/2;
    while (x < y) {
        ll k = (x+y)/2;
        int s = -inf, d = inf, l, r;
        for (int i = 0; i < 2*n; i++) {
            if (i < n) {
                ll p = a[i]-k+m;
                ll q = a[i]+k+m;
                l = lower_bound(b, b+3*n, p)-b;
                r = upper_bound(b, b+3*n, q)-b;
            } else {
                l = u[i-n].first+n;
                r = u[i-n].second+n;
            }
            u[i] = {l, r};
            s = max(s, l-i);
            d = min(d, r-i-s);
        }
        if (d <= 0)
            x = k+1;
        else
            y = k;
    }
    cout << x << "\n";
}