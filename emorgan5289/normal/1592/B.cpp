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
        ll n, x; cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            if (i >= x || (n-1-i) >= x)
                v[i] = 1;
        vector<ll> b;
        for (int i = 0; i < n; i++)
            if (v[i]) b.pb(a[i]);
        sort(all(b));
        int j = 0;
        for (int i = 0; i < n; i++)
            if (v[i]) a[i] = b[j++];
        debug(a);
        cout << (is_sorted(all(a)) ? "YES" : "NO") << "\n";
    }
}