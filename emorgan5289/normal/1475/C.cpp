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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(n+5), b(m+5);
        for (int i = 0; i < k; i++) {
            int x; cin >> x; a[x]++;
        }
        for (int i = 0; i < k; i++) {
            int x; cin >> x; b[x]++;
        }
        ll ans = 0;
        for (int i = 0; i < n+5; i++) {
            ans -= a[i]*(a[i]-1)/2;
        }
        for (int i = 0; i < m+5; i++) {
            ans -= b[i]*(b[i]-1)/2;
        }
        cout << ((k)*(k-1)/2+ans) << "\n";
    }
}