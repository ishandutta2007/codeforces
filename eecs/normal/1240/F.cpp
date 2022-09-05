#include <bits/stdc++.h>
using namespace std;

const int maxn = 210, maxm = 1010;
int n, m, K, u[maxm], v[maxm], d[maxn], ans[maxm], id[maxm];

namespace MCMF {
int cnt, head[maxn], dist[maxn], inq[maxn], pre[maxn];
queue<int> Q;
struct edge { int to, cap, cost, nxt; } e[3000];

void init(int n) {
    cnt = 0, fill(head, head + n + 1, -1);
}

void add(int u, int v, int cap, int cost) {
    e[cnt] = (edge){v, cap, cost, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, -cost, head[v]}, head[v] = cnt++;
}

bool spfa(int s, int t) {
    fill(dist, dist + t + 1, INT_MAX);
    Q.push(s), dist[s] = 0;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(), inq[v] = 0;
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && dist[e[i].to] > dist[v] + e[i].cost) {
                dist[e[i].to] = dist[v] + e[i].cost, pre[e[i].to] = i;
                if (!inq[e[i].to]) Q.push(e[i].to), inq[e[i].to] = 1;
            }
        }
    }
    return dist[t] < INT_MAX;
}

void upd(int s, int t) {
    for (int i = t; i ^ s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap--, e[pre[i] ^ 1].cap++;
    }
}

void EK(int s, int t) {
    while (spfa(s, t)) upd(s, t);
}
} // namespce MCMF

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%*d");
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]), v[i] += n;
        d[u[i]]++, d[v[i]]++;
    }
    for (; K; K--) {
        int s = 0, t = 2 * n + 1;
        MCMF::init(t);
        for (int i = 1; i <= n; i++) {
            MCMF::add(s, i, d[i] / K, 0);
            if (d[i] % K) MCMF::add(s, i, 1, 1);
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            MCMF::add(i, t, d[i] / K, 0);
            if (d[i] % K) MCMF::add(i, t, 1, 1);
        }
        for (int i = 1; i <= m; i++) if (!ans[i]) {
            MCMF::add(u[i], v[i], 1, 0), id[i] = MCMF::cnt - 2;
        }
        MCMF::EK(s, t);
        for (int i = 1; i <= m; i++) if (!ans[i] && !MCMF::e[id[i]].cap) {
            ans[i] = K, d[u[i]]--, d[v[i]]--;
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}