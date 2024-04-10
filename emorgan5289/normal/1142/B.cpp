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
    ll n, m, q; cin >> n >> m >> q;
    vector<int> p(n), v(n, -1), a(m), b(m);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        p[x] = i;
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x; x--;
        a[i] = v[(p[x]-1+n)%n];
        v[p[x]] = b[i] = i;
    }
    for (int x = 1; x <= n; x *= 2) {
        for (int i = m-1; i >= 0; i--) {
            if ((n-1)&x) b[i] = b[i] == -1 ? -1 : a[b[i]];
            a[i] = a[i] == -1 ? -1 : a[a[i]];
        }
    }
    for (int i = 1; i < m; i++)
        b[i] = max(b[i], b[i-1]);
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << (b[r] >= l ? 1 : 0);
    }
    cout << "\n";
}