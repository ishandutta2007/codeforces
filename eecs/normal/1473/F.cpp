#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int n, a[maxn], b[maxn], fir[110];

namespace FLOW {
int V, cnt, head[maxn], lev[maxn], vis[maxn];
struct edge { int to, cap, nxt; } e[600000];

void init(int _V) {
    V = _V, fill(head, head + V + 1, -1);
}

void add(int u, int v, int cap) {
    e[cnt] = (edge){v, cap, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, head[v]}, head[v] = cnt++;
}

bool bfs(int s, int t) {
    fill(lev, lev + V + 1, 0);
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
    for (int i = head[v]; ~i && inc < f; i = e[i].nxt) {
        if (e[i].cap && lev[e[i].to] == lev[v] + 1) {
            int d = dfs(e[i].to, t, min(e[i].cap, f - inc));
            if (d) e[i].cap -= d, e[i ^ 1].cap += d, inc += d;
            else lev[e[i].to] = -1;
        }
    }
    return inc;
}

int dinic(int s, int t) {
    int f = 0;
    while (bfs(s, t)) f += dfs(s, t, INT_MAX);
    return f;
}
}  // namespae FLOW

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    int s = 0, t = n + 1, ans = 0;
    FLOW::init(n + 1);
    for (int i = 1; i <= n; i++) {
        if (b[i] > 0) ans += b[i], FLOW::add(s, i, b[i]);
        else FLOW::add(i, t, -b[i]);
    }
    for (int i = 1; i <= n; i++) {
        memset(fir, 0, sizeof(fir));
        for (int j = i + 1; j <= n; j++) if (!(a[j] % a[i])) {
            int x = a[j] / a[i];
            if (fir[x]) continue;
            FLOW::add(j, i, INT_MAX);
            for (int k = x; k <= 100; k += x) fir[k] = 1;
        }
    }
    printf("%d\n", ans - FLOW::dinic(s, t));
    return 0;
}