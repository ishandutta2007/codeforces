#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5, K = 20;
int a[N], c[K], g[N], res[N];

void solve(vector<array<int, 3>>& v, int l, int r) {
    if (l == r) return;
    vector<array<int, 3>> p, q;
    int m = (l+r)/2;

    fill(c, c+K, 0);
    for (int i = m+1; i <= r; i++) {
        g[i] = a[i];
        for (int k = 0; k < K; k++)
            if (a[i]&(1<<k)) g[i] |= c[k];
        for (int k = 0; k < K; k++)
            if (a[i]&(1<<k)) c[k] = g[i];
    }

    fill(c, c+K, 0);
    for (int i = m; i >= l; i--) {
        g[i] = a[i];
        for (int k = 0; k < K; k++)
            if (a[i]&(1<<k)) g[i] |= c[k];
        for (int k = 0; k < K; k++)
            if (a[i]&(1<<k)) c[k] = g[i];
    }

    for (auto& [x, y, i] : v) {
        if (y <= m)
            p.pb({x, y, i});
        else if (x > m)
            q.pb({x, y, i});
        else {
            // debug(x, y);
            // debug(vector(g+l, g+r+1));
            for (int k = 0; k < K; k++)
                res[i] |= g[x]&g[y];
        }
    }
    solve(p, l, m), solve(q, m+1, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<array<int, 3>> v;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        v.pb({x-1, y-1, i});
    }
    solve(v, 0, n-1);
    for (int i = 0; i < q; i++)
        cout << (res[i] ? "Shi" : "Fou") << "\n";
}