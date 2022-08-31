#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 1010 * 1010 * 2;
struct edge {
    int v, f, nxt;
} e[M];
int head[N], curh[N], tot = 1, s, t;
void addedge(int u, int v, int f) {
    e[++tot] = {v, f, head[u]};
    head[u] = tot;
    e[++tot] = {u, 0, head[v]};
    head[v] = tot;
}
int qcnt, que[N], level[N];
int bfs() {
    for (int i = s; i <= t; i++) level[i] = 0;
    level[que[qcnt = 1] = s] = 1;
    for (int i = 1; i <= qcnt; i++) {
        int cur = que[i];
        for (int j = head[cur]; j; j = e[j].nxt) if (e[j].f && level[e[j].v] == 0) {
            level[e[j].v] = level[cur] + 1;
            que[++qcnt] = e[j].v;
            if (e[j].v == t) return 1;
        }
    }
    return 0;
}
int dfs(int cur, int limit) {
    if (cur == t) return limit;
    int ans = 0;
    for (int &i = curh[cur]; i; i = e[i].nxt) {
        if (e[i].f == 0 || level[e[i].v] != level[cur] + 1) continue;
        int tmp = dfs(e[i].v, min(limit, e[i].f));
        ans += tmp, limit -= tmp;
        e[i].f -= tmp, e[i ^ 1].f += tmp;
        if (limit == 0) return ans;
    }
    level[cur] = -1;
    return ans;
}
int dinic() {
    int ans = 0;
    while (bfs()) {
        for (int i = s; i <= t; i++) curh[i] = head[i];
        ans += dfs(s, 0x3f3f3f3f);
    }
    return ans;
}

int n, m;
vector < pair <int, int> > ans;
int a[1010], b[1010];
int n1, n2;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (3ll * x > m) a[++n1] = x;
        else b[++n2] = x;
    }
    s = 0, t = n1 + n2 + 1;
    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++) if (0ll + a[i] + a[i] + b[j] <= m && a[i] % b[j] == 0) addedge(i, j + n1, 1);
    for (int i = 1; i <= n1; i++) addedge(s, i, 1);
    for (int i = 1; i <= n2; i++) addedge(i + n1, t, 1);
    if (dinic() != n1) return puts("-1"), 0;
    for (int i = 2; i <= tot; i += 2) {
        if (e[i].v <= n1) continue;
        if (e[i].v == t) {
            if (e[i].f == 0) continue;
            int v = e[i ^ 1].v - n1;
            ans.push_back({3 * b[v], 2 * b[v]});
            continue;
        }
        if (e[i].f == 1) continue;
        int u = e[i ^ 1].v, v = e[i].v - n1;
        ans.push_back({a[u] + a[u] + b[v], a[u] + b[v]});
    }
    printf("%d\n", (int)ans.size());
    for (auto i : ans) printf("%d %d\n", i.first, i.second);
}