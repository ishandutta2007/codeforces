#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n, m, ans[maxn], a[maxn];
vector<int> G[maxn];

namespace FLOW {
int cnt, head[maxn], lev[maxn];
struct edge { int to, cap, nxt; } e[maxn * 200];

void init(int n) {
    fill(head, head + n + 1, -1), cnt = 0;
}

void add(int from, int to, int cap) {
    e[cnt] = (edge){to, cap, head[from]}, head[from] = cnt++;
    e[cnt] = (edge){from, 0, head[to]}, head[to] = cnt++;
}

bool bfs(int s, int t) {
    fill(lev, lev + t + 1, 0);
    queue<int> q; q.push(s), lev[s] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && !lev[e[i].to]) {
                q.push(e[i].to), lev[e[i].to] = lev[v] + 1;
            }
        }
    }
    return lev[t];
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    int add = 0;
    for (int i = head[v]; ~i && add < f; i = e[i].nxt) {
        if (e[i].cap && lev[e[i].to] == lev[v] + 1) {
            int d = dfs(e[i].to, t, min(e[i].cap, f - add));
            if (d) e[i].cap -= d, e[i ^ 1].cap += d, add += d;
            else lev[e[i].to] = -1;
        }
    }
    return add;
}

int dinic(int s, int t) {
    int f = 0;
    while (bfs(s, t)) f += dfs(s, t, INT_MAX);
    return f;
}

vector<bool> get(int s, int n) {
    vector<bool> ans(n + 1);
    queue<int> q; q.push(s), ans[s] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && !ans[e[i].to]) {
                q.push(e[i].to), ans[e[i].to] = 1;
            }
        }
    }
    return ans;
}
}  // namespace FLOW

int main() {
    scanf("%d %d", &n, &m);
    vector<int> val;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    }
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        V.push_back(i);
    }
    vector<pair<int, int>> E;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        E.emplace_back(u, v);
    }
    function<void(int, int, vector<int>, vector<pair<int, int>>)> solve =
        [&](int l, int r, vector<int> V, vector<pair<int, int>> E) {
        if (V.empty()) return;
        if (l == r) {
            for (int x : V) ans[x] = l;
            return;
        }
        int mid = (l + r) >> 1;
        int s = V.size(), t = V.size() + 1;
        FLOW::init(V.size() + 1);
        for (int i = 0; i < V.size(); i++) {
            int coef = a[V[i]] <= mid ? 2 : -2;
            if (coef < 0) FLOW::add(s, i, -coef);
            if (coef > 0) FLOW::add(i, t, coef);
        }
        for (auto p : E) {
            int u = lower_bound(V.begin(), V.end(), p.first) - V.begin();
            int v = lower_bound(V.begin(), V.end(), p.second) - V.begin();
            FLOW::add(u, v, INT_MAX);
        }
        FLOW::dinic(s, t);
        vector<int> VL, VR;
        vector<pair<int, int>> EL, ER;
        auto chk = FLOW::get(s, V.size() + 1);
        for (int i = 0; i < V.size(); i++) {
            if (!chk[i]) VL.push_back(V[i]);
            else VR.push_back(V[i]);
        }
        for (auto p : E) {
            int u = lower_bound(V.begin(), V.end(), p.first) - V.begin();
            int v = lower_bound(V.begin(), V.end(), p.second) - V.begin();
            if (!chk[u] && !chk[v]) EL.push_back(p);
            if (chk[u] && chk[v]) ER.push_back(p);
        }
        solve(l, mid, VL, EL), solve(mid + 1, r, VR, ER);
    };
    solve(0, val.size() - 1, V, E);
    for (int i = 1; i <= n; i++) {
        printf("%d ", val[ans[i]]);
    }
    return 0;
}