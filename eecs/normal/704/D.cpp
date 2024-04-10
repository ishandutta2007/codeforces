#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, r, b, x[maxn], y[maxn], d[maxn], num1[maxn], num2[maxn], id[maxn];
vector<int> V;
map<int, int> mp1, mp2;

namespace FLOW {
int V, cnt, head[maxn], lev[maxn];
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
}  // namespae FLOW

int main() {
    scanf("%d %d %d %d", &n, &m, &r, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]), y[i] += 1000000000;
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
    }
    while (m--) {
        int op, l, d;
        scanf("%d %d %d", &op, &l, &d);
        if (op == 1) {
            if (!binary_search(V.begin(), V.end(), l)) continue;
            l = lower_bound(V.begin(), V.end(), l) - V.begin() + 1;
            d = min(d, num1[l]);
            if (!mp1.count(l) || mp1[l] > d) mp1[l] = d;
        } else {
            l += 1000000000;
            if (!binary_search(V.begin(), V.end(), l)) continue;
            l = lower_bound(V.begin(), V.end(), l) - V.begin() + 1;
            d = min(d, num2[l]);
            if (!mp2.count(l) || mp2[l] > d) mp2[l] = d;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!mp1.count(x[i])) mp1[x[i]] = num1[x[i]];
        if (!mp2.count(y[i])) mp2[y[i]] = num2[y[i]];
    }
    for (auto p : mp1) {
        int l = (num1[p.first] - p.second + 1) / 2, r = (num1[p.first] + p.second) / 2;
        if (l > r) puts("-1"), exit(0);
        FLOW::add(s, p.first, r - l);
        d[s] += l, d[p.first] -= l;
    }
    for (auto p : mp2) {
        int l = (num2[p.first] - p.second + 1) / 2, r = (num2[p.first] + p.second) / 2;
        if (l > r) puts("-1"), exit(0);
        FLOW::add(p.first, t, r - l);
        d[p.first] += l, d[t] -= l;
    }
    int need = 0;
    for (int i = s; i <= t; i++) {
        if (d[i] < 0) FLOW::add(S, i, -d[i]), need -= d[i];
        else FLOW::add(i, T, d[i]);
    }
    FLOW::add(t, s, INT_MAX);
    if (FLOW::dinic(S, T) ^ need) puts("-1"), exit(0);
    int num = FLOW::dinic(s, t);
    bool flag = 0;
    if (r > b) swap(r, b), flag = 1;
    printf("%lld\n", 1LL * num * r + 1LL * (n - num) * b);
    for (int i = 1; i <= n; i++) {
        putchar((FLOW::e[id[i]].cap ^ flag) ? 'b' : 'r');
    }
    return 0;
}