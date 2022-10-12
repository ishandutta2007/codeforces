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
    ll n, k; cin >> n >> k;

    vector<vector<array<int, 2>>> p(n*n+1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            p[x].pb({i, j});
        }

    vector<array<int, 4>> q;

    for (int i = 1; i <= n*n; i++) {
        if (p[i].empty()) continue;
        int lx = inf, ly = inf, rx = -inf, ry = -inf;
        for (auto& [x, y] : p[i]) {
            lx = min(lx, x);
            ly = min(ly, y);
            rx = max(rx, x);
            ry = max(ry, y);
        }
        q.pb({lx, ly, rx, ry});
    }

    if (q.size() <= k) {
        cout << k-q.size() << "\n";
        return 0;
    }

    vector<vector<int>> a(n, vector<int>(n));

    for (int w = 1; w <= n; w++) {

        for (int i = 0; i < n; i++)
            a[i].assign(n, 0);

        for (auto& [lx, ly, rx, ry] : q) {
            if (rx-lx+1 > w || ry-ly+1 > w)
                continue;
            a[lx][ly]++;
            if (ry >= w) a[lx][ry-w]--;
            if (rx >= w) a[rx-w][ly]--;
            if (ry >= w && rx >= w) a[rx-w][ry-w]++;
        }

        for (int i = 0; i < n; i++)
            for (int j = n-2; j >= 0; j--)
                a[i][j] += a[i][j+1];

        for (int i = 0; i < n; i++)
            for (int j = n-2; j >= 0; j--)
                a[j][i] += a[j+1][i];

        for (int i = 0; i <= n-w; i++)
            for (int j = 0; j <= n-w; j++)
                if (q.size()-a[i][j] == k || q.size()-a[i][j]+1 == k) {
                    debug(i, j, w, q.size(), a[i][j], k);
                    cout << "1\n";
                    return 0;
                }
    }

    cout << "2\n";
}