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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        vector<array<ll, 2>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i][0], a[i][1] = i;
        sort(all(a));
        ll w = 0;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            w += a[i][0];
            if (w == x) {
                if (i == n-1) {
                    ok = 0;
                    break;
                }
                swap(a[i], a[i+1]);
                break;
            }
        }
        if (ok) {
            cout << "Yes\n";
            for (int i = 0; i < n; i++)
                cout << a[i][0] << " \n"[i == n-1];
        } else {
            cout << "No\n";
        }
    }
}