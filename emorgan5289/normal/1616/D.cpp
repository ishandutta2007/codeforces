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
        ll x; cin >> x;
        for (int i = 0; i < n; i++)
            a[i] -= x;
        debug(a);
        ll pi = -1;
        ll ans = 0;
        ll m = -inf;
        vector<ll> s = {0};
        for (int i = 0; i < n; i++) {
            s.pb(s.back()+a[i]);
            if (s.size() >= 3)
                cmax(m, s[s.size()-3]);
            if (s.back() < m) {
                ans++;
                s = {0};
                m = -inf;
            }
        }
        cout << n-ans << "\n";
    }
}