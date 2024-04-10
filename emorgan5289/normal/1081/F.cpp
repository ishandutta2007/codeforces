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
// #include "../../debug.cpp"
#endif

ll qry(ll x, ll y) {
    cout << "? " << x+1 << " " << y+1 << endl;
    ll r; cin >> r;
    if (r == -1) exit(-1);
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, t; cin >> n >> t;
    vector<ll> p(n, -1);
    if (n%2 == 1) {
        for (int i = 1; i < n; i += 2) {
            while (1) {
                ll y = qry(i, n-1);
                ll z = qry(i, n-1);
                if ((y+t)%2 == 0)
                    p[i-1] = t-(n-i-y+t)/2;
                if (p[i-1] != -1 && z == t)
                    break;
            }
        }
        for (int i = 1; i < n; i += 2) {
            while (1) {
                ll y = qry(0, i);
                ll z = qry(0, i);
                if ((y+t)%2 == 0)
                    p[i] = (i+1-y+t)/2;
                if (p[i] != -1 && z == t)
                    break;
            }
        }
    } else {
        for (int i = 1; i < n; i += 2) {
            while (1) {
                ll y = qry(i, n-1);
                ll z = qry(i, n-1);
                if ((y+t)%2 == 1)
                    p[i-1] = t-(n-i-y+t)/2;
                if (p[i-1] != -1 && z == t)
                    break;
            }
        }
        for (int i = 1; i < n-1; i += 2) {
            while (1) {
                ll y = qry(i, i);
                ll z = qry(i, i);
                if ((y+t)%2 == 0)
                    p[i] = (i+1-y+t)/2;
                if (p[i] != -1 && z == t)
                    break;
            }
        }
    }
    p[n-1] = t;
    cout << "! " << p[0];
    for (int i = 1; i < n; i++)
        cout << p[i]-p[i-1];
    cout << endl;
}