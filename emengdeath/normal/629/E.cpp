#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int S = 17;
const int N = 1e5 + 10;
int fa[N][S +1];
int deep[N];
struct node{
    long long all_down_len, all_up_len;
    int size;
}f[N];
vector<int>g[N];
int n, m;

void dfs(int x) {
    deep[x] ++;
    f[x].size = 1;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
            f[x].all_down_len += f[u].all_down_len + f[u].size;
            f[x].size += f[u].size;
        }
}
void dfs(int x, long long up_len) {
    f[x].all_up_len = up_len;
    for (auto u:g[x])
        if (u!=fa[x][0]) {
            dfs(u, up_len + f[x].all_down_len - f[u].all_down_len - f[u].size + n - f[u].size);
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
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    dfs(1, 0);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        int lca = getlca(x, y);
        if (deep[x] < deep[y]) swap(x, y);
        double len = deep[x] + deep[y] - deep[lca] * 2 + 1;
        if (lca == y) {
            int z = up(x, deep[x] - deep[y] - 1);
            len += ((double) f[x].size * (f[y].all_up_len + f[y].all_down_len - f[z].all_down_len - f[z].size) + (double)(n - f[z].size) * f[x].all_down_len) / ((double)f[x].size * (n - f[z].size));
        } else {
            len += ((double) f[x].size * f[y].all_down_len + (double)f[y].size * f[x].all_down_len) / ((double)f[x].size * f[y].size);
        }
        printf("%.10f\n", len);
    }
    return 0;
}