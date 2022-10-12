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
    ll m; cin >> m;
    vector<ll> a, n(m);
    for (int i = 0; i < m; i++) {
        cin >> n[i];
        for (int j = 0; j < n[i]; j++) {
            ll x; cin >> x;
            a.pb(x);
        }
    }
    ll k = a.size();
    map<ll, ll> r;
    vector<ll> x(k), c(k);
    for (int i = 0; i < k; i++) {
        if (r.count(a[i])) {
            x[r[a[i]]] = i;
            x[i] = r[a[i]];
            r.erase(r.find(a[i]));
        }
        else r[a[i]] = i;
    }
    if (!r.empty()) {
        cout << "NO\n";
    } else {

        for (int i = 0; i < k; i++) {
            for (int j = i; c[j] == 0; j = x[j^1])
                c[j] = 1, c[j^1] = 2;
            debug(c);
        }

        cout << "YES\n";
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (n[i]--)
                cout << (c[j++] == 1 ? 'L' : 'R');
            cout << "\n";
        }
    }
}