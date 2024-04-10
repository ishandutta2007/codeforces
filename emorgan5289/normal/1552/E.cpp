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

ll ceildiv(ll a, ll b) {
    return (a+b-1)/b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> a(n*k);
    for (int i = 0; i < n*k; i++)
        cin >> a[i], a[i]--;
    vector<vector<array<ll, 2>>> c(n);
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < n*k; j++) {
            if (a[j] == i) {
                if (p != -1)
                    c[i].pb({p, j});
                p = j;
            }
        }
        reverse(all(c[i]));
    }
    vector<array<ll, 2>> ans(n);
    for (ll l = 0; l < n; l += k-1) {
        ll r = min(l+k-1, n);
        vector<bool> v(n);
        for (int i = l; i < r; i++) {
            int b = -1;
            for (int j = l; j < r; j++)
                if (!v[j] && (b == -1 || c[j].back()[1] < c[b].back()[1]))
                    b = j;
            v[b] = 1;
            ans[b] = c[b].back();
            for (int j = l; j < r; j++)
                c[j].pop_back();
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i][0]+1 << " " << ans[i][1]+1 << "\n";
}