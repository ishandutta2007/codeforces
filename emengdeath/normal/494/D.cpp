#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int S = 17;
vector<pair<int, int> >  g[N];
int fa[N][S + 1], deep[N];
int dis[N];
int n, m;
struct node{
    int v2, v, sum;
}f[N], h[N];
const int mod = 1e9 + 7;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
node operator+(node a, node b) {
    a.v2 = add(a.v2, b.v2);
    a.v = add(a.v, b.v);
    a.sum = add(a.sum, b.sum);
    return a;
}
node operator-(node a, node b) {
    a.v2 = sub(a.v2, b.v2);
    a.v = sub(a.v, b.v);
    a.sum = sub(a.sum, b.sum);
    return a;
}
node link(node a, int x) {
    a.v2 = add(a.v2, add(mul(mul(2, a.v), x), mul(a.sum, mul(x, x))));
    a.v = add(a.v, mul(x, a.sum));
    return a;
}
void dfs(int x) {//
    deep[x] ++;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    f[x].sum = 1;
    for (auto u:g[x])
        if (u.first != fa[x][0]) {
            fa[u.first][0] = x;
            deep[u.first] = deep[x];
            dis[u.first ] = add(dis[x], u.second);
            dfs(u.first);
            f[x] = f[x] + link(f[u.first], u.second);
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
void dfs(int x, node up) {
    h[x] = f[x] + up;
    for (auto u:g[x])
        if (u.first!= fa[x][0]) {
            dfs(u.first, link(up + f[x] - link(f[u.first], u.second), u.second) );
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    dfs(1);
    dfs(1, node{0, 0, 0});
    scanf("%d", &m);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == y) {
            int a = h[x].v2, b = f[x].v2;
            printf("%d\n",  sub(mul(b, 2), a));
        } else {
            int lca = getlca(x, y);
            int v = sub(add(dis[x], dis[y]), mul(dis[lca], 2));
            if (lca == y) {
                int a = h[x].v2, b = link(h[y] - f[y], v).v2;
                printf("%d\n",  sub(a, mul(b, 2)));
            } else {
                int a = h[x].v2, b = link(f[y], v).v2;
                printf("%d\n",  sub(mul(b, 2), a));
            }
        }
    }
    return 0;
}