#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

int u, d, l, r;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, sx, sy;
    cin >> n >> sx >> sy;
    vt<pii> p(4);
    for (int i = 0; i < 4; i++) p[i].se = i;
    while (n--) {
        int x, y;
        cin >> x >> y;
        x -= sx, y -= sy;
        if (x > 0) p[0].fi++;
        if (x < 0) p[1].fi++;
        if (y > 0) p[2].fi++;
        if (y < 0) p[3].fi++;
    }

    sort(rall(p));
    cout << p[0].fi << '\n';
    if (p[0].se == 0) cout << sx + 1 << ' ' << sy;
    if (p[0].se == 1) cout << sx - 1 << ' ' << sy;
    if (p[0].se == 2) cout << sx << ' ' << sy + 1;
    if (p[0].se == 3) cout << sx << ' ' << sy - 1;
}