#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

const auto dirs = {
    pii{0, 1},
    pii{0, -1},
    pii{1, 0},
    pii{-1, 0}
};

const ll kInf = LLONG_MAX / 2;

void solve() {
    int n, m;
    cin >> n >> m;
    int p, q;
    cin >> p >> q;
    vector a(n + 2, vector<char>(m + 2, '#'));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    array<pii, 128> offs = {};
    offs['L'] = {0, 1};
    offs['R'] = {0, -1};
    offs['U'] = {1, 0};
    offs['D'] = {-1, 0};

    struct pq_state {
        int x, y;
        ll d;
        bool operator<(const pq_state &o) const {
            return d > o.d;
        }
    };

    vector dist(n + 2, vector<ll>(m + 2, kInf));
    priority_queue<pq_state> pq;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') {
                dist[i][j] = 0;
                pq.push({i, j, 0});
            }
        }
    }

    while (!empty(pq)) {
        auto [x, y, d] = pq.top();
        pq.pop();
        if (d != dist[x][y]) continue;

        for (auto [dx1, dy1] : dirs) {
            int x1 = x + dx1;
            int y1 = y + dy1;
            if (a[x1][y1] == '#') continue;
            if (a[x1][y1] == '.') continue;

            auto [dx2, dy2] = offs[a[x1][y1]];
            int x2 = x1 + dx2;
            int y2 = y1 + dy2;
            if (x == x2 && y == y2) continue;

            int cost = abs(dx1) == abs(dx2) ? q : p;
            if (ll nd = d + cost; nd < dist[x2][y2]) {
                dist[x2][y2] = nd;
                pq.push({x2, y2, nd});
            }
        }
    }

    ll ans = kInf;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = min({ans,
                    dist[i][j] + dist[i + 1][j],
                    dist[i][j] + dist[i][j + 1]});
        }
    }
    if (ans == kInf) cout << -1;
    else cout << ans;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}