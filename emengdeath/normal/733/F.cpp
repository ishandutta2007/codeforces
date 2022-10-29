#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 4e5 + 10;
const int S = 20;
vector<pair<int, int> >g[N];
struct node{
    int x, y;
    int w, c;
}edge[N];
vector<int>used;
int id[N], bel[N];
int fa[N][S + 1], e_id[N][S+1];
int deep[N];
int n, m, cnt;
int getfa(int x) {
    return x == bel[x] ? x :bel[x] = getfa(bel[x]);
}

void dfs(int x) {
    deep[x] ++;
    for (int i = 0; fa[fa[x][i]][i]; i ++)  {
        if (edge[e_id[x][i]].w > edge[e_id[fa[x][i]][i]].w)
            e_id[x][i+1] = e_id[x][i];
        else
            e_id[x][i+1] = e_id[fa[x][i]][i];
        fa[x][i + 1] = fa[fa[x][i]][i];
    }
    for (auto u:g[x])
        if (u.first != fa[x][0]) {
            fa[u.first][0] = x;
            e_id[u.first][0] = u.second;
            deep[u.first] = deep[x];
            dfs(u.first);
        }
}
int up(int x, int y){
    int v = e_id[x][0];
    for (int i = S; i >= 0; i --)
        if (y >= (1 << i)) {
            if (edge[e_id[x][i]].w > edge[v].w) v = e_id[x][i];
            y -= (1 << i), x = fa[x][i];
        }
    return v;
}
int up_lca(int x, int y){
    for (int i = S; i >= 0; i --)
        if (y >= (1 << i)) {
            y -= (1 << i), x = fa[x][i];
        }
    return x;
}
int getlca(int x, int y) {
    if (deep[x] < deep[y])
        swap(x, y);
    x = up_lca(x, deep[x] - deep[y]);
    for (int i = S; i >= 0; i --)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return x != y ? fa[x][0] : x;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        bel[i] = i;
    for (int i = 1; i <= m; i ++)
        scanf("%d", &edge[i].w), id[i] = i;
    for (int i = 1; i <= m; i ++)
        scanf("%d", &edge[i].c);

    for (int i = 1; i <= m; i ++)
        scanf("%d %d", &edge[i].x, &edge[i].y);
    sort(id + 1, id + m + 1, [](int x, int y) {
        return edge[x].w < edge[y].w;
    });
    long long all = 0;
    for (int i = 1;i <= m; i ++) {
        int x = getfa(edge[id[i]].x), y = getfa(edge[id[i]].y);
        if (x != y) {
            bel[x] = y;
            used.push_back(id[i]);
            all += edge[id[i]].w;
            g[edge[id[i]].x].push_back({edge[id[i]].y, id[i]});
            g[edge[id[i]].y].push_back({edge[id[i]].x, id[i]});
        }
    }
    dfs(1);
    int ansx = 1, ansy = 0;
    long long ansv = 1e18;
    scanf("%d", &cnt);
    for (int i = 1; i <= m; i ++) {
        int x = edge[i].x, y = edge[i].y;
        int lca = getlca(x, y);
        if (deep[x] > deep[y]) swap(x, y);
        int v = up(y, deep[y] - deep[lca]);
        if (x != lca) {
            int w = up(x, deep[x] - deep[lca]);
            if (edge[w].w > edge[v].w) v = w;
        }
        long long vv = all - edge[v].w + edge[i].w - (cnt/edge[i].c);
        if (vv < ansv)
            ansv = vv, ansx = i, ansy = v;
    }
    printf("%lld\n", ansv);
    for (auto u:used)
        if (u != ansy ) {
            printf("%d %d\n", u, edge[u].w);
        }
    printf("%d %d\n", ansx, edge[ansx].w - cnt / edge[ansx].c);
    return 0;
}