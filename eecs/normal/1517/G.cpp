#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1010;
int n, x[maxn], y[maxn], w[maxn], type[maxn];

namespace FLOW {
int V, cnt, head[maxn << 1], lev[maxn << 1];
struct edge { int to, cap, nxt; } e[100000];

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

ll dinic(int s, int t) {
    ll f = 0;
    while (bfs(s, t)) f += dfs(s, t, INT_MAX);
    return f;
}
}  // namespae FLOW

int main() {
    scanf("%d", &n);
    FLOW::init(2 * n + 1);
    int s = 0, t = 2 * n + 1;
    ll all = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &w[i]);
        if (y[i] & 1) type[i] = 2 | (x[i] & 1);
        else type[i] = x[i] & 1 ^ 1;
        if (!type[i]) FLOW::add(s, i, INT_MAX);
        if (type[i] == 3) FLOW::add(i + n, t, INT_MAX);
        FLOW::add(i, i + n, w[i]), all += w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (type[j] == type[i] + 1) {
            if (1LL * abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 1) FLOW::add(i + n, j, INT_MAX);
        }
    }
    printf("%lld\n", all - FLOW::dinic(s, t));
    return 0;
}