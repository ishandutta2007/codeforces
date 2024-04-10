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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5;
int p[N], ans[N], v[N], c[N];

ll ceildiv(ll x, ll y) {
    return x == 0 ? 0 : (x-1)/y+1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    v[0] = 1;
    fill(ans, ans+N, -1);
    for (int i = 0; i < n; i++) {
        ll t, x, y; cin >> t >> x >> y;
        for (int j = 0; j <= m; j++)
            c[j] = v[j] ? 0 : inf;
        for (int j = 0; j <= m; j++) {
            ll k = t == 1 ? j+ceildiv(x, 100000) : ceildiv(j*x, 100000);
            if (k <= m) cmin(c[k], c[j]+1);
            if (c[j] <= y && !v[j])
                v[j] = 1, ans[j] = i+1;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " \n"[i == m];
}