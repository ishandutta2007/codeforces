#include <bits/stdc++.h>
using namespace std;
int n, m;
vector < int > e[300010], son[300010];
int vis[300010], tag[300010];
int u[300010], v[300010];
void dfs(int x) {
    vis[x] = 1;
    for (auto i : e[x]) {
        if (vis[i]) continue;
        dfs(i);
        son[x].push_back(i);
        son[i].push_back(x);
    }
}
vector < int > cur;
int dfs2(int x, int fa, int y) {
    if (x == y) {
        cur.push_back(x);
        return 1;
    }
    for (auto i : son[x]) {
        if (i == fa) continue;
        if (dfs2(i, x, y)) {
            cur.push_back(x);
            return 1;
        }
    }
    return 0;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", u + i, v + i);
        tag[u[i]] ^= 1, tag[v[i]] ^= 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += tag[i];
    if (sum) printf("NO\n%d\n", sum / 2);
    else {
        puts("YES");
        for (int i = 1; i <= q; i++) {
            cur.clear();
            dfs2(v[i], 0, u[i]);
            printf("%d\n", cur.size());
            for (auto j : cur) printf("%d ", j);
            puts("");
        }
    }
}