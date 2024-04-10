#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

#define allp(x)     (x)->begin(), (x)->end()

using ll = long long;
using pii = pair<int, int>;

const int maxn = 3e3 + 1, inf = 1 << 30;
vt<int> adj[maxn];
vt<int> *cant_go[maxn][maxn],
        *cant_go_rev[maxn][maxn];
int dist[maxn][maxn];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;

        if (!cant_go[a][b]) cant_go[a][b] = new vt<int>();
        cant_go[a][b]->push_back(c);

        if (!cant_go_rev[c][b]) cant_go_rev[c][b] = new vt<int>();
        cant_go_rev[c][b]->push_back(a);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cant_go[i][j]) sort(allp(cant_go[i][j]));
            if (cant_go_rev[i][j]) sort(allp(cant_go_rev[i][j]));
        }
    }

    fill_n(*dist, maxn * maxn, inf);
    queue<pii> q;
    dist[n][0] = 0;
    q.emplace(n, 0);
    while (!q.empty()) {
        int p = q.front().fi, u = q.front().se;
        q.pop();

        if (u == n - 1) break;

        for (int v : adj[u]) {
            if (cant_go[p][u] &&
                    binary_search(allp(cant_go[p][u]), v)) continue;
            if (dist[u][v] != inf) continue;

            dist[u][v] = dist[p][u] + 1;
            q.emplace(u, v);
        }
    }

    vt<int> path{n};
    for (int u = n - 1, p = n; u;) {
        int min_dist = inf, min_par = -1;
        for (int i = 0; i < n; i++) {
            if (cant_go_rev[p][u] &&
                    binary_search(allp(cant_go_rev[p][u]), i)) continue;

            if (min_dist > dist[i][u]) {
                min_dist = dist[i][u];
                min_par = i;
            }
        }

        if (~min_par) {
            path.push_back(min_par + 1);
            p = u;
            u = min_par;
        } else break;
    }

    if (sz(path) == 1) cout << -1;
    else {
        cout << sz(path) - 1 << '\n';
        reverse(all(path));
        for (int u : path) cout << u << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}