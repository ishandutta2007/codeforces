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
        ll n, k; cin >> n >> k;
        vector<ll> a(k+1);
        ll s = 0;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            a[x%k]++;
            s += x/k;
        }
        ll p = 0;
        for (int i = 0; i < (k+1)/2; i++) {
            p += a[k-i], a[k-i] = 0;
            ll x = min(p, a[i]);
            s += x, p -= x, a[i] -= x;
        }
        if (k%2 == 0) p += a[k/2];
        s += p/2;
        cout << s << "\n";
    }
}