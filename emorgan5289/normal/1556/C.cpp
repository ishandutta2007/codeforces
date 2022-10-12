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
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ll d = 0;
        for (int j = i+1; j < n; j++) {
            if ((j-i)%2 == 1 && c[j] >= d) {
                debug(i, j, d, c[i], c[j]);
                ans += 1+min(c[i], c[j]-max(d, 0ll));
                if (j == i+1) ans--;
            }
            debug(d, j, c[j]);
            if (j%2 == 0) d += c[j];
            else d -= c[j];
            if (d < 0) {
                c[i] += d;
                d = 0;
            }
            if (c[i] < 0) break;
        }
    }
    cout << ans << "\n";
}