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
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<ll> s(n), f(n+2);
        vector<vector<ll>> stk(n+2);
        ll m = 0;
        for (int j = n-1; j >= 0; j--) {
            f[a[j]]++;
            while (f[m] != 0) m++;
            s[j] = m;
            stk[a[j]].pb(j);
        }
        vector<ll> b;
        ll k = 0;
        while (k < n) {
            m = s[k];
            b.pb(m);
            ll nk = k+1;
            for (int i = 0; i < m; i++)
                nk = max(nk, stk[i].back()+1);
            while (k < nk) {
                stk[a[k]].pop_back();
                k++;
            }
        }
        cout << b.size() << "\n";
        for (auto& x : b)
            cout << x << " ";
        cout << "\n";
        debug(s);
    }
}