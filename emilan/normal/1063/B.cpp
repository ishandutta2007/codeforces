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

const int inf = 1 << 30;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    int sx, sy;
    cin >> sx >> sy;
    sx--, sy--;
    int l, r;
    cin >> l >> r;
    vt<string> v(n);
    for (auto &i : v) cin >> i;

    vt<vt<int>> dist(n, vt<int>(m, inf));
    deque<pii> q;
    dist[sx][sy] = 0;
    q.emplace_back(sx, sy);
    while (!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop_front();

        int step = dist[x][y],
            ml = step + max(0, sy - y),
            mr = step + max(0, y - sy);

        auto mv = [&](int dx, int dy) {
            int s = x + dx, t = y + dy;
            if (s < 0 || t < 0 || s >= n || t >= m ||
                    v[s][t] == '*') return;

            int nextStep = step;
            if ((dy < 0 && y > sy) || (dy > 0 && y < sy)) nextStep++;
            if (nextStep >= dist[s][t]) return;

            dist[s][t] = nextStep;
            if (nextStep == step) q.emplace_front(s, t);
            else q.emplace_back(s, t);
        };

        mv(-1, 0);
        mv(1, 0);
        if (ml < l) mv(0, -1);
        if (mr < r) mv(0, 1);
    }

    int reach = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] != inf) reach++;
        }
    }

    cout << reach;
}