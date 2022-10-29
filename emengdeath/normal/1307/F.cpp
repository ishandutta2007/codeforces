#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int N = 4e5 + 10;
const int S = 19;
int n, m;
int fa[N][S + 1], deep[N], dis[N], f[N];
vector<int>g[N];
int getf(int x) {
    return f[x] == x? x : f[x] = getf(f[x]);
}
void dfs(int x) {
    deep[x] ++;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
        }
}
int up(int x, int y){
    for (int i = S; i >= 0; i --)
        if (y >= (1 << i))
            y -= (1 << i), x = fa[x][i];
    return x;
}
int getlca(int x, int y) {
    if (deep[x] < deep[y])
        swap(x, y);
    x = up(x, deep[x] - deep[y]);
    for (int i = S; i >= 0; i --)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return x != y ? fa[x][0] : x;
}
int walk(int x, int y, int len) {
    int lca = getlca(x, y);
    if (deep[x] - deep[lca] >= len)
        return up(x, len);
    len -= (deep[x] - deep[lca]);
    return up(y, (deep[y] - deep[lca]) - len);
}
int main() {
    int r;
    scanf("%d %d %d", &n, &m, &r);
    for (int i= 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(i + n);
        g[y].push_back(i + n);
        g[i + n].push_back(x), g[i + n].push_back(y);
    }
    dfs(1);
    for (int i = 1; i <= n + n; i ++)
        dis[i] = 1e9, f[i] = i;
    queue<int>d;
    while (r --){
        int x;
        scanf("%d", &x);
        dis[x] = 0;
        d.push(x);
    }
    while (!d.empty()) {
        int x = d.front();
        d.pop();
        if (dis[x] == m) continue;
        for (auto u:g[x]) {
            f[getf(u)] = getf(x);
            if (dis[u] == 1e9)
                dis[u] = dis[x] + 1, d.push(u);
        }
    }
    scanf("%d", &r);
    while (r --) {
        int x, y;
        scanf("%d %d", &x, &y);
        int lca = getlca(x, y);
        if (deep[x] + deep[y] - deep[lca] * 2<= 2 * m) {
            puts("YES");
            continue;
        }
        getf(walk(x, y, m)) == getf(walk(y, x, m)) ? puts("YES") : puts("NO");
    }
    return 0;
}