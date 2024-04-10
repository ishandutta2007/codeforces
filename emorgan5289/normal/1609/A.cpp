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
        ll c = 0;
        for (int i = 0; i < n; i++) {
            while (a[i]%2 == 0)
                a[i] /= 2, c++;
        }
        sort(all(a));
        debug(a);
        while (c--) a[n-1] *= 2;
        debug(a);
        cout << accumulate(all(a), 0ll) << "\n";
    }
}