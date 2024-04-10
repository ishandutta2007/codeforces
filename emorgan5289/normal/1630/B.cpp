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
        vector<ll> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        b = a;
        sort(all(b));

        // need floor((n+k+1)/2)
        debug((n+k+1)/2);

        int j = 0;
        for (int i = 1; i < n-(n+k+1)/2+1; i++)
            if (b[i+(n+k+1)/2-1]-b[i] <= b[j+(n+k+1)/2-1]-b[j])
                j = i;
        ll x = b[j], y = b[j+(n+k+1)/2-1];

        debug(a, x, y);
        cout << x << " " << y << "\n";

        int l = 0, r = 0;
        for (int i = 0; i < k; i++) {
            int d = 0;
            while (d <= 0) {
                if (x <= a[r] && a[r] <= y)
                    d++;
                else
                    d--;
                r++;
            }
            cout << l+1 << " " << (i == k-1 ? n : r) << "\n";
            l = r;
        }
    }
}