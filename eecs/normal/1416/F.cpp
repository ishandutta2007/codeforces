#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int T, n, m, a[maxn], b[maxn], d[maxn], mpx[maxn], mpy[maxn];
char c[maxn];

int id(int x, int y) {
    return (x - 1) * m + y;
}

namespace FLOW {
int V, cnt, head[maxn], lev[maxn], vis[maxn], cur[maxn];
struct edge { int to, cap, nxt; } e[1000000];

void init(int _V) {
    V = _V, cnt = 0;
    fill(head, head + V + 1, -1);
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

vector<pair<int, int>> get() {
    vector<pair<int, int>> E;
    for (int i = 1; i <= V; i++) {
        for (int j = head[i]; ~j; j = e[j].nxt) {
            if (!(j & 1) && !e[j].cap) E.emplace_back(i, e[j].to);
        }
    }
    return E;
}
}  // namespae FLOW

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[id(i, j)]);
                mpx[id(i, j)] = i, mpy[id(i, j)] = j;
            }
        }
        int s = n * m + 1, t = s + 1, S = t + 1, T = S + 1;
        FLOW::init(T);
        fill(d, d + t + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                bool need = 1;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (!x || x > n || !y || y > m || a[id(x, y)] > a[id(i, j)]) continue;
                    if (a[id(i, j)] ^ a[id(x, y)]) need = 0;
                    else if ((i + j) & 1) FLOW::add(id(i, j), id(x, y), 1);
                    else FLOW::add(id(x, y), id(i, j), 1);
                }
                if (need) {
                    if ((i + j) & 1) d[s]++, d[id(i, j)]--;
                    else d[id(i, j)]++, d[t]--;
                } else {
                    if ((i + j) & 1) FLOW::add(s, id(i, j), 1);
                    else FLOW::add(id(i, j), t, 1);
                }
            }
        }
        FLOW::add(t, s, INT_MAX);
        int need = 0;
        for (int i = 1; i <= t; i++) {
            if (d[i] > 0) need += d[i], FLOW::add(i, T, d[i]);
            else FLOW::add(S, i, -d[i]);
        }
        if (FLOW::dinic(S, T) ^ need) { puts("NO"); continue; }
        fill(c, c + n * m + 1, 0);
        for (auto e : FLOW::get()) if (e.first <= n * m && e.second <= n * m) {
            int x1 = mpx[e.first], y1 = mpy[e.first];
            int x2 = mpx[e.second], y2 = mpy[e.second];
            b[e.first] = 1, b[e.second] = a[e.first] - 1;
            if (x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2), swap(e.first, e.second);
            if (x1 == x2) c[e.first] = 'R', c[e.second] = 'L';
            else c[e.first] = 'D', c[e.second] = 'U';
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (!c[id(i, j)]) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (!x || x > n || !y || y > m || a[id(x, y)] >= a[id(i, j)]) continue;
                    b[id(i, j)] = a[id(i, j)] - a[id(x, y)];
                    c[id(i, j)] = "LRUD"[k]; break;
                }
            }
        }
        puts("YES");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d%c", b[id(i, j)], " \n"[j == m]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%c%c", c[id(i, j)], " \n"[j == m]);
            }
        }
    }
    return 0;
}