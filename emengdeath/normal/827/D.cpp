#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
const int S = 18;
int ans[N];
int n, m;
struct node{
    int x, y, v;
    int id;
}e[N];
int deep[N], fa[N][S + 1], f[N][S + 1], uni[N];
vector<pair<int, pair<int, int> > > g[N];
int mn[N];
vector<node> d;
int fa1[N];
int get(int x) {
    return uni[x] == x? x : uni[x] = get(uni[x]);
}
void dfs(int x) {
    deep[x] ++;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i +1] = fa[fa[x][i]][i], f[x][i + 1] = max(f[x][i], f[fa[x][i]][i]);
    for (auto u:g[x])
        if (u.first != fa[x][0]){
            fa[u.first][0] = x;
            f[u.first][0] = u.second.first;
            deep[u.first] = deep[x];
            dfs(u.first);
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
int get(int x, int step) {
    int v = 0;
    for (int i = S; i >= 0; i --)
        if ((step>>i) & 1)
            v = max(f[x][i], v), x = fa[x][i];
    return v;
}
void dfs1(int x) {
    for (auto u:g[x])
        if (u.first != fa[x][0]){
            dfs1(u.first);
            if (mn[u.first] == 2e9) ans[u.second.second] = -1;
            else
            ans[u.second.second] = mn[u.first] -1;
        }
}
int getfa1(int x) {
    return x == fa1[x] ? x : fa1[x] = getfa1(fa1[x]);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++)
        scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v), e[i].id = i;
    sort(e + 1, e + m + 1, [](const node&a, const node&b) {return a.v < b.v;});
    for (int i = 1; i <= n; i ++) uni[i] = i, mn[i] = 2e9, fa1[i] = i;
    for (int i = 1; i <= m; i ++) {
        if (get(e[i].x) != get(e[i].y)) {
            g[e[i].x].push_back({e[i].y, {e[i].v, e[i].id}});
            g[e[i].y].push_back({e[i].x, {e[i].v, e[i].id}});
            uni[uni[e[i].x]] = e[i].y;
        } else {
            d.push_back(e[i]);
        }
    }
    dfs(1);
    sort(d.begin(), d.end(), [](const node&a, const node&b) {
       return a.v < b.v;
    });
    for (auto u:d) {
        int lca = getlca(u.x, u.y);
        ans[u.id] = max(get(u.x, deep[u.x] - deep[lca]), get(u.y, deep[u.y] - deep[lca])) - 1;
        int x = getfa1(u.x);
        while (deep[x] > deep[lca]) mn[x] = u.v, fa1[x] = fa[x][0], x = getfa1(fa[x][0]);
        x = getfa1(u.y);
        while (deep[x] > deep[lca]) mn[x] = u.v, fa1[x] = fa[x][0], x = getfa1(fa[x][0]);
    }
    dfs1(1);
    for (int i = 1; i <= m; i ++) {
        printf("%d%c", ans[i], " \n"[i == m]);
    }
    return 0;
}