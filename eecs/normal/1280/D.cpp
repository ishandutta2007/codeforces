#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3010;
int T, n, m, w[maxn], sz[maxn];
pair<int, ll> f[maxn][maxn], g[maxn];
vector<int> G[maxn];

void chk(pair<int, ll> &x, pair<int, ll> y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x), w[i] = -x;
        }
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x), w[i] += x;
        }
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            fill(f[i], f[i] + n + 1, make_pair(-1, -1e18));
        }
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        function<void(int, int)> dfs = [&](int v, int fa) {
            f[v][0] = make_pair(0, w[v]), sz[v] = 1;
            for (int u : G[v]) if (u ^ fa) {
                dfs(u, v);
                fill(g, g + sz[v] + sz[u], make_pair(-1, -1e18));
                for (int i = 0; i < sz[v]; i++) {
                    for (int j = 0; j < sz[u]; j++) {
                        chk(g[i + j], make_pair(f[v][i].first + f[u][j].first, f[v][i].second + f[u][j].second));
                        chk(g[i + j + 1], make_pair(f[v][i].first + f[u][j].first + (f[u][j].second > 0), f[v][i].second));
                    }
                }
                sz[v] += sz[u], copy(g, g + sz[v], f[v]);
            }
        };
        dfs(1, 0);
        printf("%d\n", f[1][m - 1].first + (f[1][m - 1].second > 0));
    }
    return 0;
}