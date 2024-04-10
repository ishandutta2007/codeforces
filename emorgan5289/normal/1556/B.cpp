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
        ll f[2] = {0, 0};
        for (int i = 0; i < n; i++)
            cin >> a[i], a[i] %= 2, f[a[i]]++;
        debug(a);
        if (abs(f[0]-f[1]) > 1)
            cout << "-1\n";
        else {
            ll x = 0, y = 0;
            int j = 0;
            for (int i = 0; i < n; i++)
                if (a[i]) x += abs(i-j), j += 2;
            j = 1;
            for (int i = 0; i < n; i++)
                if (a[i]) y += abs(i-j), j += 2;
            if (n%2 == 0)
                cout << min(x, y) << "\n";
            else if (f[1] > f[0])
                cout << x << "\n";
            else
                cout << y << "\n";
        }
    }
}