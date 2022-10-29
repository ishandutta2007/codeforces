#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int S = 15;
const int N = 3001;
long long f[N][N];
int lca[N][N];
int deep[N], fa[N][S + 1];
int n, sz[N];
vector<int>g[N];
struct node{
    int x, y;
    long long v;
    node(int x = 0, int y = 0, long long v = 0) :x(x), y(y), v(v){}
};
vector<node> d[N];
void dfs(int x) {
    deep[x] ++;
    sz[x] = 1;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
            sz[x] += sz[u];
        }
}
int getlca(int x, int y) {
    int i = S;
    if (deep[x] < deep[y]) swap(x, y);
    while (deep[x] != deep[y]) {
        while (deep[fa[x][i]] < deep[y]) i --;
        x = fa[x][i];
    }
    i = S;
    while (x != y) {
        while (i && fa[x][i] == fa[y][i]) i --;
        x = fa[x][i], y = fa[y][i];
    }
    return x;
}
int up(int x, int dep) {
    int i = S;
    while (deep[x] > dep) {
        while (deep[fa[x][i]] < dep) i --;
        x = fa[x][i];
    }
    return x;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n ; i ++)
        for (int j = i + 1; j <= n; j ++) {
            lca[i][j] = getlca(i, j);
            long long v = sz[i] * sz[j];
            if (lca[i][j] == i)
                v = sz[j] * (n - sz[up(j, deep[i] + 1)]);
            else
                if (lca[i][j] == j)
                    v = sz[i] * (n - sz[up(i, deep[j] + 1)]);
            d[deep[i] + deep[j] - 2 * deep[lca[i][j]]].push_back(node(i, j, v));
        }
    long long ans = 0;
    for (int len = 1; len <= n - 1; len ++)
        for (auto u:d[len]) {
            int x = fa[u.x][0], y = fa[u.y][0];
            if (lca[u.x][u.y] == u.x)
                x = up(u.y, deep[u.x] + 1);
            if (lca[u.x][u.y] == u.y)
                y = up(u.x, deep[u.y] + 1);
            f[u.x][u.y] = f[u.y][u.x] = max(f[u.x][y], f[x][u.y]) + u.v;
            ans = max(ans, f[u.x][u.y]);
        }
    printf("%lld\n", ans);
    return 0;
}