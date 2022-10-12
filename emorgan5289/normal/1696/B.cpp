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
        int x = 0, y = n-1;
        while (x < n && a[x] == 0) x++;
        while (y >= 0 && a[y] == 0) y--;
        ll z = 0;
        for (int i = x; i <= y; i++)
            if (a[i] == 0) z = 1;
        debug(x, y, z);
        if (x > y)
            cout << "0\n";
        else if (z)
            cout << "2\n";
        else
            cout << "1\n";
    }
}