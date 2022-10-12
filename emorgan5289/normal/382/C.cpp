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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    if (n == 1) {
        cout << "-1\n";
        return 0;
    }
    if (a[0] == a[n-1]) {
        cout << "1\n" << a[0] << "\n";
        return 0;
    }
    if (n == 2) {
        if ((a[1]+a[0])&1) {
            cout << "2\n" << 2*a[0]-a[1] << " " << 2*a[1]-a[0] << "\n";
        } else {
            cout << "3\n" << 2*a[0]-a[1] << " " << ((a[0]+a[1])/2) << " " << 2*a[1]-a[0] << "\n";
        }
        return 0;
    }
    map<ll, ll> f;
    for (int i = 0; i < n-1; i++)
        f[a[i+1]-a[i]]++;
    if (f.size() == 1) {
        cout << "2\n" << 2*a[0]-a[1] << " " << 2*a[n-1]-a[n-2] << "\n";
    } else if (f.size() == 2) {
        ll d = (--f.end())->first;
        if (f[d] != 1 || f.begin()->first*2 != d) {
            cout << "0\n"; return 0;
        }
        for (int i = 0; i < n-1; i++)
            if (a[i+1]-a[i] == d)
                cout << "1\n" << ((a[i+1]+a[i])/2) << "\n";
    } else {
        cout << "0\n";
    }
}