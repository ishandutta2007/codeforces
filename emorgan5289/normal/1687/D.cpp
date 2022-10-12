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
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> lb(8e6), ub(8e6);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll m = a[0]-1;
    for (int i = 0; i < n; i++) {
        a[i] -= m;
        lb[a[i]] = ub[a[i]] = a[i];
    }
    for (ll i = 1; i < 8e6; i++)
        if (lb[i] == 0) lb[i] = lb[i-1];
    ub.back() = inf_ll;
    for (ll i = 8e6-2; i >= 0; i--)
        if (ub[i] == 0) ub[i] = ub[i+1];
    vector<ll> x = {0, 0};
    for (ll i = 1; i*i <= a[n-1]; i++)
        x.pb(i*i), x.pb(i*i+i);
    debug(a);
    for (ll i = 1; 1; i++) {
        ll l = 0, r = inf_ll;
        for (ll j = 2; j < x.size(); j += 2) {
            cmax(l, x[j]-ub[x[j-1]+1]);
            cmin(r, x[j+1]-lb[x[j+1]]);
        }
        debug(i, x, i*i+l-1);
        debug(l, r);
        if (l <= r && i*i+r-1-m >= 0) {
            cout << max(0ll, i*i+l-1-m) << "\n";
            break;
        }
        for (ll j = 3; j < x.size(); j++)
            x[j] += j-2;
        while (x.size() > 2 && x[x.size()-3] >= a[n-1])
            x.pop_back(), x.pop_back();
    }
}