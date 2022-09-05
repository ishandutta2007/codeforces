#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int T, n, m, rt, d[maxn], mark[maxn], dist[maxn], par[maxn], vis[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    auto vertex = [&]() { // 0
        if (n == 1) return 0;
        fill(mark + 1, mark + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (!d[i]) return mark[i] = 1;
        }
        return 0;
    };
    auto cycle = [&]() { // 22
        if (rt > n && n == m) return 0;
        fill(mark + 1, mark + n + 1, 0);
        fill(dist + 1, dist + n + 1, -1);
        for (int i = 1; i <= n; i++) if (d[i] == 2 && !~dist[i]) {
            queue<int> Q;
            Q.push(i), dist[i] = 0;
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                for (int v : G[u]) if (d[v] == 2) {
                    if (!~dist[v]) {
                        Q.push(v), dist[v] = dist[par[v] = u] + 1;
                    } else if (par[u] != v) {
                        int x = u, y = v;
                        while (x ^ y) {
                            if (dist[x] < dist[y]) swap(x, y);
                            mark[x] = 1, x = par[x];
                        }
                        return mark[x] = 1;
                    }
                }
            }
        }
        return 0;
    };
    auto path = [&]() { // 121
        fill(mark + 1, mark + n + 1, 0);
        fill(dist + 1, dist + n + 1, -1);
        queue<int> Q;
        Q.push(rt), dist[rt] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int v : G[u]) if (!~dist[v]) {
                Q.push(v), dist[v] = dist[par[v] = u] + 1;
                if (d[v] == 1 && dist[v] < n - 1) {
                    for (int x = v; x ^ rt; x = par[x]) mark[x] = 1;
                    return mark[rt] = 1;
                }
            }
        }
        return 0;
    };
    auto component = [&]() { // 122
        fill(mark + 1, mark + n + 1, 0);
        fill(vis + 1, vis + n + 1, 0), vis[rt] = 1;
        fill(dist + 1, dist + n + 1, -1);
        function<void(int)> dfs = [&](int u) {
            for (int v : G[u]) if (!~dist[v]) {
                dist[v] = dist[par[v] = u] + 1, dfs(v);
            }
        };
        dist[rt] = 0, dfs(rt);
        sort(G[rt].begin(), G[rt].end(), [&](int u, int v) { return dist[u] < dist[v]; });
        bool flag = 0;
        for (int u : G[rt]) if (dist[u] > 1 && !vis[u]) {
            for (int x = u; x ^ rt; x = par[x]) mark[x] = 1;
            if (flag) break;
            function<void(int)> dfs = [&](int u) {
                vis[u] = 1;
                for (int v : G[u]) if (!vis[v]) dfs(v);
            };
            dfs(u), flag = 1;
        }
        return mark[rt] = 1;
    };
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            G[i].clear(), d[i] = 0;
        }
        for (int i = 1, u, v; i <= m; i++) {
            scanf("%d %d", &u, &v);
            ++d[u] %= 3, ++d[v] %= 3;
            G[u].push_back(v), G[v].push_back(u);
        }
        for (rt = 1; rt <= n && d[rt] ^ 1; rt++);
        if (vertex() || cycle() || rt <= n && (path() || G[rt].size() > 4 && component())) {
            vector<int> V;
            for (int i = 1; i <= n; i++) {
                if (!mark[i]) V.push_back(i);
            }
            printf("YES\n%d\n", V.size());
            for (int x : V) printf("%d ", x);
            putchar('\n');
        } else {
            puts("No");
        }
    }
    return 0;
}