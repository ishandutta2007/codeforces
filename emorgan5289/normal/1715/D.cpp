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
    ll n, q; cin >> n >> q;
    vector<array<ll, 3>> e(q);
    for (int i = 0; i < q; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        e[i][0]--, e[i][1]--;
        if (e[i][0] >= e[i][1])
            swap(e[i][0], e[i][1]);
    }
    vector<ll> ans(n);
    for (int k = 0; k < 30; k++) {
        vector<int> a(n, -1);
        vector<vector<int>> p(n);

        for (auto& [x, y, w] : e) {
            if (x == y)
                a[x] = (w&(1<<k) ? 1 : 0);
            else if (w&(1<<k))
                p[x].pb(y);
            else
                a[x] = a[y] = 0;
        }

        for (auto& [x, y, w] : e) {
            if (x != y && (w&(1<<k)) && a[x] == 0)
                a[y] = 1;
            if (x != y && (w&(1<<k)) && a[y] == 0)
                a[x] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == -1)
                a[i] = 0;
            if (a[i] == 0)
                for (int j : p[i])
                    a[j] = 1;
        }

        for (int i = 0; i < n; i++)
            ans[i] |= a[i]<<k;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n-1];
}