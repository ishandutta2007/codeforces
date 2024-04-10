#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N = 1e5 +1;
int fa[N][18], mx[N][18], deep[N];
struct node{
    int x, y, z, id;
}a[N * 10];
int n, m;
int faa[N], ans[N * 10];
vector<pair<int, int> > g[N];
int getfa(int x) {return x == faa[x]?x:faa[x] = getfa(faa[x]);}
void dfs(int x) {
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i], mx[x][i + 1] = max(mx[x][i], mx[fa[x][i]][i]);
    deep[x] ++;
    for (auto u:g[x])
        if (u.first != fa[x][0]) {
            fa[u.first][0] = x;
            mx[u.first][0] = u.second;
            deep[u.first] = deep[x];
            dfs(u.first);
        }
}
int getlca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int i = 17;
    while (deep[x] != deep[y]) {
        while (deep[fa[x][i]] < deep[y]) i --;
        x = fa[x][i];
    }
    i = 17;
    while (x != y) {
        while (i && fa[x][i] == fa[y][i]) i --;
        x = fa[x][i], y = fa[y][i];
    }
    return x;
}
int up(int x, int step) {
    int i = 17;
    while (step) {
        while ((1 << i) > step) i --;
        step -= (1 << i);
        x = fa[x][i];
    }
    return x;
}
int get(int x, int fa) {
    int y = 0, dis = deep[x] - deep[fa];
    while ((1 << (y + 1)) <= dis) y++;
    int z = up(x, dis - (1 << y));
    return max(mx[x][y], mx[z][y]);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ; i ++) {
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
        a[i].id = i;
    }
    for (int i = 1;  i <= n ;  i++) faa[i] = i;
    sort(a + 1, a + m + 1, [](node a, node b) {return a.z < b.z;});

    for (int i = 1; i <= m ; i ++) {
        int x = getfa(a[i].x), y = getfa(a[i].y);
        if (x != y) {
            g[a[i].x].push_back(make_pair(a[i].y, a[i].z));
            g[a[i].y].push_back(make_pair(a[i].x, a[i].z));
            faa[x] = y;
            a[i].id = 0;
        }
    }
    dfs(1);
    for (int i = 1; i <= m ; i ++)
        if (a[i].id) {
            int x =  a[i].x, y = a[i].y;
            int fa = getlca(x, y);
            int v = 0;
            if (fa != x) {
                v = max(get(x, fa), v);
            }

            if (fa != y) {
                v = max(get(y, fa), v);
            }
            ans[a[i].id] = v + 1;
        }
    for (int i = 1; i <= m; i ++)
        if (ans[i])
        printf("%d\n", ans[i]- 1);
    return 0;
}