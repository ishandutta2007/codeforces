#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 100010;
int n, m, s, pre[maxn][2], f[maxn][2], vis[maxn];
vector<int> ans, G[maxn];
queue<pair<int, bool> > q;

void dfs(int v) {
    if (vis[v]) printf("Draw\n"), exit(0);
    vis[v] = 1;
    for (int u : G[v]) dfs(u);
    vis[v] = 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, c; i <= n; i++) {
        scanf("%d", &c);
        for (int j = 1, k; j <= c; j++) {
            scanf("%d", &k), G[i].push_back(k);
        }
    }
    scanf("%d", &s);
    q.push({s, 0}), f[s][0] = 1;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        if (p.y && !G[p.x].size()) {
            printf("Win\n");
            while (1) {
                ans.push_back(p.x);
                if (p.x == s && !p.y) break;
                p = {pre[p.x][p.y], !p.y};
            }
            reverse(ans.begin(), ans.end());
            for (int x : ans) printf("%d ", x);
            exit(0);
        }
        for (int u : G[p.x]) if (!f[u][!p.y]) {
            pre[u][!p.y] = p.x;
            q.push({u, !p.y}), f[u][!p.y] = 1;
        }
    }
    dfs(s), printf("Lose\n");
    return 0;
}