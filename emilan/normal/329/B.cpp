#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

vector<ii> adj{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    vector<string> m(r);
    rep(i, r) cin >> m[i];

    int sx, sy;
    rep(i, r) rep(j, c) if (m[i][j] == 'E') sx = i, sy = j;

    int foundDist = 1 << 30;
    int bat = 0;

    vvi dist(r, vi(c, -1));
    queue<ii> q;

    dist[sx][sy] = 0;
    q.emplace(sx, sy);

    while (!q.empty()) {
        ii cur = q.front();
        q.pop();

        int step = dist[cur.fi][cur.se];
        if (step > foundDist) break;

        char ch = m[cur.fi][cur.se];
        if (ch == 'S') foundDist = step;
        else if (ch > '0' && ch <= '9') bat += ch - '0';

        for (ii& i : adj) {
            int x = cur.fi + i.fi, y = cur.se + i.se;
            if (x < 0 || y < 0 || x == r || y == c) continue;
            if (m[x][y] == 'T' || dist[x][y] != -1) continue;

            dist[x][y] = step + 1;
            q.emplace(x, y);
        }
    }

    cout << bat;

    return 0;
}