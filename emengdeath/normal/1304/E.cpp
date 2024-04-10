#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int S = 17;
vector<int> g[N];
int deep[N], fa[N][S + 1];
int n, m;
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
int dis(int x, int y) {
    return deep[x] + deep[y] - 2 * deep[getlca(x, y)];
}
bool check(int x, int y) {
    return x <= y && !((x ^ y) & 1);
}
bool work(int a, int x, int y, int b, int k) {
    int disax = dis(a, x), disxy = dis(x, y), disyb = dis(y, b);
    return check(disax + 1 + disyb, k) || check(disax + 1 + disxy + 1 + disyb, k);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int T;
    scanf("%d", &T);
    while (T --) {
        int x, y, a, b, k;
        scanf("%d %d %d %d %d", &x, &y, &a, &b, &k);
        int v = dis(a, b);
        if (v <= k && !((v ^ k) & 1))
        {
            puts("YES");
            continue;
        }
        if (work(a, x, y, b, k) || work(a, y, x, b, k)) {
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}