#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll j = 0; j < t; j++) {
        ll n;
        cin >> n;
        vector<ll> x(n, 0), y(n, 0);
        for (ll i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (n%2 == 0) {
            cout << (x[n/2]-x[n/2-1]+1) * (y[n/2]-y[n/2-1]+1) << endl;
        } else {
            cout << 1 << endl;
        }
    }
}