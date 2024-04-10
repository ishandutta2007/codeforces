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
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int j = 0;
    ll x = 0;
    for (int i = 0; i < m; i++) {
        ll b; cin >> b;
        while (b-x-1 >= a[j])
            x += a[j++];
        cout << j+1 << " " << b-x << "\n";
    }
}