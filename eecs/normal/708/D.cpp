#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, cnt, ans, d[maxn];
int head[maxn], incf[maxn], inq[maxn], pre[maxn], dist[maxn];
struct edge { int to, cap, cost, nxt; } e[100000];

void add_edge(int from, int to, int cap, int cost) {
    e[cnt] = (edge){to, cap, cost, head[from]}, head[from] = cnt++;
    e[cnt] = (edge){from, 0, -cost, head[to]}, head[to] = cnt++;
}

bool spfa(int s, int t) {
    fill(dist, dist + n + 2, INT_MAX);
    queue<int> Q; Q.push(s), dist[s] = 0, incf[s] = INT_MAX;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(), inq[v] = 0;
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && dist[e[i].to] > dist[v] + e[i].cost) {
                dist[e[i].to] = dist[v] + e[i].cost, pre[e[i].to] = i;
                incf[e[i].to] = min(incf[v], e[i].cap);
                if (!inq[e[i].to]) Q.push(e[i].to), inq[e[i].to] = 1;
            }
        }
    }
    return dist[t] < INT_MAX;
}

pair<int, int> EK(int s, int t) {
    int flow = 0, ans = 0;
    while (spfa(s, t)) {
        flow += incf[t], ans += incf[t] * dist[t];
        for (int i = t; i ^ s; i = e[pre[i] ^ 1].to) {
            e[pre[i]].cap -= incf[t], e[pre[i] ^ 1].cap += incf[t];
        }
    }
    return make_pair(flow, ans);
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    int s = 0, t = n + 1;
    while (m--) {
        int u, v, c, f;
        scanf("%d %d %d %d", &u, &v, &c, &f);
        if (c >= f) {
            add_edge(u, v, c - f, 1);
            d[u] -= f, d[v] += f;
            add_edge(u, v, INT_MAX, 2);
            add_edge(v, u, f, 1);
        } else {
            ans += f - c;
            add_edge(u, v, f - c, 0);
            d[u] -= c, d[v] += c;
            add_edge(u, v, INT_MAX, 2);
            add_edge(v, u, c, 1);
        }
    }
    add_edge(n, 1, INT_MAX, 0);
    for (int i = 1; i <= n; i++) {
        if (d[i] > 0) add_edge(s, i, d[i], 0);
        else add_edge(i, t, -d[i], 0);
    }
    printf("%d\n", ans + EK(s, t).second);
    return 0;
}