#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 30;
ll n;
ll a[N][N];

vector<pair<ll, ll>> walk(ll k) {
    ll x = 0, y = 0;
    vector<pair<ll, ll>> r;
    while (x != n-1 || y != n-1) {
        k -= a[x][y];
        r.pb({x, y});
        if (x == n-1) y++;
        else if (y == n-1) x++;
        else {
            if (a[x][y+1] == 0) {
                if (a[x+1][y] <= k) x++;
                else y++;
            } else {
                if (a[x][y+1] <= k) y++;
                else x++;
            }
        }
    }
    r.pb({n-1, n-1});
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (ll i = 2*n-2, k = 1; i >= 0; i--, k <<= 1)
        for (ll j = 1; j < n; j += 2)
            if (i-j >= 0 && i-j < n)
                a[j][i-j] = k;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    ll q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        for (auto& [x, y] : walk(k))
            cout << x+1 << " " << y+1 << endl;
    }
}