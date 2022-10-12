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
        if (!a[n-1]) {
            for (int i = 1; i <= n+1; i++)
                cout << i << "\n";
        } else if (a[0]) {
            cout << n+1 << "\n";
            for (int i = 1; i <= n; i++)
                cout << i << "\n";
        } else {
            for (int j = 0; j < n-1; j++)
                if (!a[j] && a[j+1]) {
                    for (int i = 1; i <= j+1; i++)
                        cout << i << "\n";
                    cout << n+1 << "\n";
                    for (int i = j+2; i <= n; i++)
                        cout << i << "\n";
                    break;
                }
        }
    }
}