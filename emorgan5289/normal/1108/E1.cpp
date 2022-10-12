#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e9+10;
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> a(n), s = {0, n}, p, l, r;
    vector<array<ll, 2>> b(m);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++) {
        cin >> b[i][0] >> b[i][1];
        b[i][0]--, b[i][1]--;
        s.pb(b[i][0]);
        s.pb(b[i][1]+1);
    }
    ll ans = 0;
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    debug(s);
    for (ll i = 0; i+1 < s.size(); i++) {
        l.pb(inf), r.pb(-inf), p.pb(s[i]);
        for (ll j = s[i]; j < s[i+1]; j++)
            cmin(l.back(), a[j]), cmax(r.back(), a[j]);
        cmax(ans, r.back()-l.back());
    }
    debug(l);
    debug(r);
    debug(p);
    ll k = p.size();
    vector<ll> tt;
    for (ll i = 0; i < k; i++)
        for (ll j = 0; j < k; j++) {
            ll z = 0;
            vector<ll> t;
            for (ll q = 0; q < m; q++) {
                auto [x, y] = b[q];
                if (x <= p[i] && p[i] <= y && !(x <= p[j] && p[j] <= y))
                    z++, t.pb(q);
            }
            debug(z, l[i], r[j]);
            if (z+r[j]-l[i] > ans)
                tt = t, ans = z+r[j]-l[i];
        }
    cout << ans << "\n" << tt.size() << "\n";
    for (ll i = 0; i < tt.size(); i++)
        cout << tt[i]+1 << " ";
    cout << "\n";
}