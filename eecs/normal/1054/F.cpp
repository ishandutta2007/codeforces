#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, tot, num, all, col[maxn], bel[maxn], id[maxn], tmp[maxn][maxn];
pair<int, int> p1[maxn], p2[maxn];

namespace FLOW {
int V, cnt, head[maxn], lev[maxn], vis[maxn];
struct edge { int to, cap, nxt; } e[3000000];

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

void dinic(int s, int t) {
    while (bfs(s, t)) dfs(s, t, INT_MAX);
    queue<int> Q;
    Q.push(s), vis[s] = 1;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && !vis[e[i].to]) {
                Q.push(e[i].to), vis[e[i].to] = 1;
            }
        }
    }
}
}  // namespae FLOW

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p1[i].first, &p1[i].second), p2[i] = p1[i];
    }
    sort(p1 + 1, p1 + n + 1);
    sort(p2 + 1, p2 + n + 1, [&](pair<int, int> a, pair<int, int> b) {
        return make_pair(a.second, a.first) < make_pair(b.second, b.first);
    });
    FLOW::init(2 * n + 1);
    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        FLOW::add(s, i, 1), id[i] = FLOW::cnt - 2;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        FLOW::add(i, t, 1), id[i] = FLOW::cnt - 2;
    }
    memset(tmp, -1, sizeof(tmp));
    for (int i = 1; i < n; i++) if (p1[i].first == p1[i + 1].first) {
        for (int j = 1; j < n; j++) if (p2[j].second == p2[j + 1].second) {
            if (p2[j].second <= p1[i].second || p2[j].second >= p1[i + 1].second) continue;
            if (p1[i].first <= p2[j].first || p1[i].first >= p2[j + 1].first) continue;
            FLOW::add(i, j + n, 1), tmp[i][j] = FLOW::cnt - 2;
        }
    }
    FLOW::dinic(s, t);
    for (int i = 1; i <= 2 * n; i++) {
        if (i <= n && FLOW::vis[i] || i > n && !FLOW::vis[i]) col[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) if (~tmp[i][j]) {
            assert(!col[i] || !col[j + n]);
        }
    }
    vector<tuple<int, int, int, int>> V;
    for (int i = 1, j; i <= n; i = j) {
        for (j = i + 1; p2[i].second == p2[j].second && col[n + j - 1]; j++);
        V.emplace_back(p2[i].first, p2[i].second, p2[j - 1].first, p2[i].second);
    }
    printf("%d\n", V.size());
    for (auto &p : V) {
        printf("%d %d %d %d\n", get<0>(p), get<1>(p), get<2>(p), get<3>(p));
    }
    V.clear();
    for (int i = 1, j; i <= n; i = j) {
        for (j = i + 1; p1[i].first == p1[j].first && col[j - 1]; j++);
        V.emplace_back(p1[i].first, p1[i].second, p1[i].first, p1[j - 1].second);
    }
    printf("%d\n", V.size());
    for (auto &p : V) {
        printf("%d %d %d %d\n", get<0>(p), get<1>(p), get<2>(p), get<3>(p));
    }
    return 0;
}