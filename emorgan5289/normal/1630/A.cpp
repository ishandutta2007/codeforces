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
        if (k == n-1) {
            if (n == 4)
                cout << "-1\n";
            else {
                vector<int> a, b;
                for (int i = 0; i < n; i++) {
                    if (__builtin_popcount(i) == 1)
                        a.pb(i), b.pb((n-1)^i);
                }
                for (int i = 0; i < n/2; i++) {
                    if (__builtin_popcount(i) != 1 && __builtin_popcount(i) != __builtin_popcount((n-1))-1)
                        cout << i << " " << ((n-1)^i) << "\n";
                }
                debug(a, b);
                for (int i = 0; i < a.size(); i++)
                    cout << a[i] << " " << b[(i+1)%b.size()] << "\n";
            }
        } else if (k == 0) {
            for (int i = 0; i < n/2; i++)
                cout << i << " " << ((n-1)^i) << "\n";
        } else {
            for (int i = 1; i < n/2; i++) {
                if (i == k || i == ((n-1)^k))
                    continue;
                cout << i << " " << ((n-1)^i) << "\n";
            }
            cout << ((n-1)^k) << " " << 0 << "\n";
            cout << k << " " << (n-1) << "\n";
        }
    }
}