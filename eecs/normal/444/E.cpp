#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], b[maxn], c[maxn], x[maxn], fa[maxn];
vector<int> V[maxn];

namespace FLOW {
int V, cnt, head[maxn], lev[maxn], cur[maxn];
struct edge { int to, cap, nxt; } e[1000000];
queue<int> Q;

void init(int _V) {
    V = _V, cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int cap) {
    e[cnt] = (edge){v, cap, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, head[v]}, head[v] = cnt++;
}

int bfs(int s, int t) {
    fill(lev, lev + V + 1, 0);
    Q.push(s), lev[s] = 1;
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
        if (e[i].cap && lev[e[i].to] > lev[v]) {
            int d = dfs(e[i].to, t, min(e[i].cap, f - inc));
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
        copy(head, head + V + 1, cur);
        f += dfs(s, t, INT_MAX);
    }
    return f;
}
}  // namespae FLOW

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    auto chk = [&](int lim) {
        int s = 0, t = 4 * n + 1;
        FLOW::init(t);
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 1; i <= n; i++) {
            V[i].clear(), FLOW::add(s, i, x[i]);
            if (i < n && c[i] < lim) fa[find(a[i])] = find(b[i]);
        }
        for (int i = 1; i <= n; i++) {
            V[find(i)].push_back(i);
        }
        int lst = 2 * n + 1;
        for (int i = 1; i <= n; i++) if (!V[i].empty()) {
            FLOW::add(lst, i + n, n);
            int o = lst + 1;
            for (int j : V[i]) FLOW::add(j, o, n);
            FLOW::add(lst, o, n), lst = o;
            FLOW::add(i + n, t, V[i].size());
        }
        lst++;
        for (int i = n; i; i--) if (!V[i].empty()) {
            FLOW::add(lst, i + n, n);
            int o = lst + 1;
            for (int j : V[i]) FLOW::add(j, o, n);
            FLOW::add(lst, o, n), lst = o;
        }
        return FLOW::dinic(s, t) == n;
    };
    int l = 1, r = 10000, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}