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
        vector<ll> a(n+1);
        for (int i = 0; i < n; i++)
            cin >> a[i+1];
        vector<int> ans(n);
        vector<int> d(n);
        iota(all(d), 0);
        sort(all(d), [&](int x, int y){
            return a[x+1]-a[x] < a[y+1]-a[y];
        });
        debug(d);
        for (int i = 0; i < n; i++)
            ans[n-1-i] = d[i];
        for (int i = 0; i < n; i++)
            cout << ans[i]+1 << " \n"[i == n-1];
    }
}