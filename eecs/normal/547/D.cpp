#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010, INF = 0x3f3f3f3f;
int n, r, b, x[maxn], y[maxn], d[maxn], num1[maxn], num2[maxn], id[maxn];
vector<int> V;
unordered_map<int, int> mp1, mp2;

namespace FLOW {
int V, cnt, head[maxn], lev[maxn], cur[maxn];
struct edge { int to, cap, nxt; } e[3000000];
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
    memset(lev, 0, sizeof(lev));
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

void dinic(int s, int t) {
    while (bfs(s, t)) {
        memcpy(cur, head, sizeof(cur));
        assert(dfs(s, t, INF));
    }
}
}  // namespae FLOW

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]), y[i] += 200000;
        V.push_back(x[i]), V.push_back(y[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    int s = 0, t = V.size() + 1, S = t + 1, T = S + 1;
    FLOW::init(T);
    for (int i = 1; i <= n; i++) {
        x[i] = lower_bound(V.begin(), V.end(), x[i]) - V.begin() + 1;
        y[i] = lower_bound(V.begin(), V.end(), y[i]) - V.begin() + 1;
        FLOW::add(x[i], y[i], 1), id[i] = FLOW::cnt - 2;
        num1[x[i]]++, num2[y[i]]++;
        mp1[x[i]] = 1, mp2[y[i]] = 1;
    }
    for (auto p : mp1) {
        int l = num1[p.first] / 2, r = (num1[p.first] + 1) / 2;
        if (l < r) FLOW::add(s, p.first, r - l);
        d[s] += l, d[p.first] -= l;
    }
    for (auto p : mp2) {
        int l = num2[p.first] / 2, r = (num2[p.first] + 1) / 2;
        if (l < r) FLOW::add(p.first, t, r - l);
        d[p.first] += l, d[t] -= l;
    }
    FLOW::add(t, s, INF);
    for (int i = s; i <= t; i++) {
        if (d[i] < 0) FLOW::add(S, i, -d[i]);
        if (d[i] > 0) FLOW::add(i, T, d[i]);
    }
    FLOW::dinic(S, T);
    for (int i = 1; i <= n; i++) {
        putchar(FLOW::e[id[i]].cap ? 'b' : 'r');
    }
    return 0;
}