#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, maxm = 1010, INF = 0x3f3f3f3f;
int n, m, s, t, u[maxm], v[maxm], g[maxm], id[maxm];
int cnt, head[maxn], lev[maxn], d[maxn], bel[maxn];
struct edge { int v, cap, nxt; } e[maxm << 2];

void add(int u, int v, int cap) {
    e[cnt] = (edge){v, cap, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, head[v]}, head[v] = cnt++;
}

bool bfs(int s, int t) {
    memset(lev, 0, sizeof(lev));
    queue<int> Q; Q.push(s), lev[s] = 1;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && !lev[e[i].v]) {
                Q.push(e[i].v), lev[e[i].v] = lev[v] + 1;
            }
        }
    }
    return lev[t];
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    int inc = 0;
    for (int i = head[v]; ~i && inc < f; i = e[i].nxt) {
        if (e[i].cap && lev[e[i].v] == lev[v] + 1) {
            int d = dfs(e[i].v, t, min(f - inc, e[i].cap));
            if (d) e[i].cap -= d, e[i ^ 1].cap += d, inc += d;
            else lev[e[i].v] = -1;
        }
    }
    return inc;
}

int dinic(int s, int t) {
    int f = 0;
    while (bfs(s, t)) f += dfs(s, t, INT_MAX);
    return f;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &g[i]);
        if (!g[i]) add(u[i], v[i], INF);
        else add(u[i], v[i], 1), id[i] = cnt - 1, add(v[i], u[i], INF);
    }
    printf("%d\n", dinic(s, t));
    for (int i = 1; i <= n; i++) {
        if (!lev[i]) bel[i] = 1;
    }
    cnt = 0, memset(head, -1, sizeof(head));
    int S = 0, T = n + 1;
    for (int i = 1; i <= m; i++) if (g[i]) {
        add(u[i], v[i], INF), id[i] = cnt - 1;
        d[u[i]]--, d[v[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] > 0) add(S, i, d[i]);
        if (d[i] < 0) add(i, T, -d[i]);
    }
    dinic(S, T);
    for (int i = 1; i <= m; i++) {
        if (!g[i]) { puts("0 1"); continue; }
        int f = e[id[i]].cap + 1;
        printf("%d %d\n", f, f + !(!bel[u[i]] && bel[v[i]]));
    }
    return 0;
}