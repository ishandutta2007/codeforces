#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

struct tp {
    int x, y, idx;
};

const int inf = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    vt<tp> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].idx = i + 1;
    }
    
    vt<tp> sorted_hori(a), sorted_vert(a);
    sort(all(sorted_hori), [](tp s, tp t) {
        return s.x == t.x ? s.y < t.y : s.x < t.x;
    });
    sort(all(sorted_vert), [](tp s, tp t) {
        return s.y == t.y ? s.x < t.x : s.y < t.y;
    });

    vt<vt<pii>> adj(m + 2);
    for (int i = 1; i < m; i++) {
        adj[sorted_hori[i - 1].idx].emplace_back(
            sorted_hori[i].idx,
            sorted_hori[i].x - sorted_hori[i - 1].x
        );
        adj[sorted_hori[i].idx].emplace_back(
            sorted_hori[i - 1].idx,
            sorted_hori[i].x - sorted_hori[i - 1].x
        );

        adj[sorted_vert[i - 1].idx].emplace_back(
            sorted_vert[i].idx,
            sorted_vert[i].y - sorted_vert[i - 1].y
        );
        adj[sorted_vert[i].idx].emplace_back(
            sorted_vert[i - 1].idx,
            sorted_vert[i].y - sorted_vert[i - 1].y
        );
    }

    for (int i = 0; i < m; i++) {
        adj[0].emplace_back(
            i + 1,
            min(abs(sx - a[i].x), abs(sy - a[i].y))
        );

        adj[i + 1].emplace_back(
            m + 1,
            abs(ex - a[i].x) + abs(ey - a[i].y)
        );
    }

    adj[0].emplace_back(
        m + 1,
        abs(sx - ex) + abs(sy - ey)
    );

    vt<int> dist(m + 2, inf);
    priority_queue<pii> q;
    dist[0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        int u = q.top().se, d = -q.top().fi;
        q.pop();

        if (d != dist[u]) continue;
        if (u == m + 1) break;

        for (pii &e : adj[u]) {
            int v = e.fi, new_dist = d + e.se;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                q.emplace(-new_dist, v);
            }
        }
    }

    cout << dist.back();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}