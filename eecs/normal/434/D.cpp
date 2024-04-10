#include <bits/stdc++.h>
using namespace std;

const int maxn = 20000;
int n, m, a[55], b[55], c[55], l[55], r[55];
int tot, cnt, id[55][210], head[maxn], cur[maxn], lev[maxn];
struct edge { int to, cap, nxt; } e[500000];

void add(int u, int v, int cap) {
    e[cnt] = (edge){v, cap, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, head[v]}, head[v] = cnt++;
}

bool bfs(int s, int t) {
    fill(lev, lev + tot + 1, 0);
    queue<int> Q; Q.push(s), lev[s] = 1;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && !lev[e[i].to]) {
                Q.push(e[i].to), lev[e[i].to] = lev[v] + 1;
            }
        }
    }
    return lev[t];
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    int inc = 0;
    for (int &i = cur[v]; ~i; i = e[i].nxt) {
        if (e[i].cap && lev[e[i].to] == lev[v] + 1) {
            int d = dfs(e[i].to, t, min(f - inc, e[i].cap));
            if (d) e[i].cap -= d, e[i ^ 1].cap += d, inc += d;
            else lev[e[i].to] = -1;
            if (inc == f) break;
        }
    }
    return inc;
}

int dinic(int s, int t) {
    int f = 0;
    while (bfs(s, t)) {
        memcpy(cur, head, sizeof(cur));
        f += dfs(s, t, INT_MAX);
    }
    return f;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    int s = ++tot, t = ++tot;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        int lst = s;
        id[i][r[i] - l[i] + 1] = s;
        for (int j = r[i]; j >= l[i]; j--) {
            id[i][j - l[i]] = ++tot;
            add(lst, tot, 250000 - (a[i] * j * j + b[i] * j + c[i])), lst = tot;
        }
        add(lst, t, INT_MAX);
    }
    while (m--) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        for (int i = l[v]; i <= r[v]; i++) {
            int j = i + d;
            if (j > r[u]) continue;
            if (j < l[u]) { add(id[v][i - l[v] + 1], t, INT_MAX); continue; }
            add(id[v][i - l[v] + 1], id[u][j - l[u] + 1], INT_MAX);
        }
    }
    printf("%d\n", 250000 * n - dinic(s, t));
    return 0;
}