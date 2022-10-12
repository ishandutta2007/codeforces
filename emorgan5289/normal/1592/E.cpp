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

const int N = 2e6+5;
vector<ll> f[2][N];
ll j[2][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for (ll k = 25; k >= 0; k--) {
        debug(k);
        for (int i = 0; i < N; i++) {
            f[0][i].clear();
            f[1][i].clear();
            j[0][i] = j[1][i] = 0;
        }
        ll p = 0;
        f[1][0].push_back(-1);
        ll x = 0;
        for (int i = 0; i < n; i++) {
            x ^= a[i]&~((1ll<<(k+1))-1);
            if (!(a[i]&(1ll<<k)))
                p = i+1;
            while (j[i%2][x] < f[i%2][x].size() && f[i%2][x][j[i%2][x]] < p-1)
                j[i%2][x]++;
            if (j[i%2][x] < f[i%2][x].size())
                cmax(ans, i-f[i%2][x][j[i%2][x]]);
            f[i%2][x].push_back(i);
        }
    }
    cout << ans << "\n";
}