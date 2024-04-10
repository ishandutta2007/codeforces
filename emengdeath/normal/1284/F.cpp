#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 250001;
int n;
vector<int>g[N], gg[N];
int deep[N], deepp[N], id[N];
int fa[N][20], faa[N], father[N];
void dfs(int x){
    deep[x] ++;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            deep[u] = deep[x];
            fa[u][0] = x;
            dfs(u);
        }
}
void dfs1(int x) {
    deepp[x] ++;
    for (auto u:gg[x])
        if (u != faa[x]) {
            deepp[u] = deepp[x];
            faa[u] = x;
            dfs1(u);
        }
}
int getlca(int x, int y) {
    int i = 19;
    if (deep[x] < deep[y]) swap(x, y);
    while (deep[x] != deep[y]) {
        while (deep[fa[x][i]] < deep[y]) i --;
        x = fa[x][i];
    }
    i = 19;
    while (x != y) {
        while (i && fa[x][i] == fa[y][i]) i --;
        x = fa[x][i], y = fa[y][i];
    }
    return x;
}
int getfa(int x){
    return x == father[x]? x: father[x] = getfa(father[x]);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        gg[x].push_back(y);
        gg[y].push_back(x);
    }
    dfs(1);
    dfs1(1);
    for (int i = 1; i <= n ; i ++)
        father[i] = i, id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y){
        return deepp[x] > deepp[y];
    });
    printf("%d\n", n - 1);
    for (int i = 1; i < n; i ++) {
        int x = id[i], y = faa[id[i]];
        int lca = getlca(x, y);
        int xx, yy;
        if (getfa(lca) == getfa(x)) {
            yy = y;
            for (int i = 19; i >= 0; i --)
                if (deep[fa[yy][i]] >= deep[lca] && getfa(fa[yy][i]) != getfa(x))
                    yy = fa[yy][i];
            xx = fa[yy][0];
        } else {
            xx = x;
            for (int i = 19; i >= 0; i --)
                if (deep[fa[xx][i]] >= deep[lca] && getfa(fa[xx][i]) == getfa(x))
                    xx = fa[xx][i];
            yy = fa[xx][0];
        }
        father[getfa(x)] = getfa(yy);
        printf("%d %d %d %d\n", xx, yy, x, y);
    }
    return 0;
}