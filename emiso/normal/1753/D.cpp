#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

const ll INF = LLONG_MAX/2;
ll n, m, a, b, ans;
char s[1000100];

vector<vector<char>> g;
vector<vector<ll>> dist;

// .LURD#
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#';
}

priority_queue<pair<ll, pair<int, int>>> q;

void relax(int x, int y, ll nd) {
    assert(valid(x, y));
    if (dist[x][y] > nd) {
        dist[x][y] = nd;
        q.push({-dist[x][y], {x, y}});
    }
}

void dijkstra(int par) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (g[i][j] == '.' && ((i + j) % 2 == par)) {
                dist[i][j] = 0;
                q.push({-dist[i][j], {i, j}});
            }
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.top().second;
        ll d = -q.top().first; q.pop();
        if(dist[x][y] != d) continue;

        // conferir input correto

        // right
        if (valid(x, y+1) && g[x][y+1] == 'L') {
            relax(x, y+2, d + b);
        }
        if (valid(x, y+1) && g[x][y+1] == 'U') {
            relax(x+1, y+1, d + a);
        }
        if (valid(x, y+1) && g[x][y+1] == 'D') {
            relax(x-1, y+1, d + a);
        }

        // left
        if (valid(x, y-1) && g[x][y-1] == 'R') {
            relax(x, y-2, d + b);
        }
        if (valid(x, y-1) && g[x][y-1] == 'U') {
            relax(x+1, y-1, d + a);
        }
        if (valid(x, y-1) && g[x][y-1] == 'D') {
            relax(x-1, y-1, d + a);
        }

        // down
        if (valid(x + 1, y)) {
            if (g[x+1][y] == 'U') {
                relax(x+2, y, d + b);
            }
            if (g[x+1][y] == 'L') {
                relax(x+1, y+1, d + a);
            }
            if (g[x+1][y] == 'R') {
                relax(x+1, y-1, d + a);
            }
        }

        // up
        if (valid(x - 1, y)) {
            if (g[x-1][y] == 'D') {
                relax(x-2, y, d + b);
            }
            if (g[x-1][y] == 'L') {
                relax(x-1, y+1, d + a);
            }
            if (g[x-1][y] == 'R') {
                relax(x-1, y-1, d + a);
            }
        }
    }
}

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    g = vector<vector<char>>(n + 2, vector<char>(m + 2, '#'));
    dist = vector<vector<ll>>(n + 2, vector<ll>(m + 2, INF));

    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j];
        }
    }

    dijkstra(0);
    dijkstra(1);

    ans = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (valid(i, j-1)) ans = min(ans, dist[i][j] + dist[i][j-1]);
            if (valid(i, j+1)) ans = min(ans, dist[i][j] + dist[i][j+1]);
            if (valid(i-1, j)) ans = min(ans, dist[i][j] + dist[i-1][j]);
            if (valid(i+1, j)) ans = min(ans, dist[i][j] + dist[i+1][j]);
        }
    }

    if (ans >= INF) puts("-1");
    else printf("%lld\n", ans);

    return 0;
}