#include <bits/stdc++.h>
using namespace std;

const int maxn = 2500;
int d, n, cnt, ans, a[maxn], head[maxn], popcnt[maxn], nxt[maxn], mark[maxn];
int dist[maxn], incf[maxn], inq[maxn], pre[maxn], id[maxn][maxn];
struct edge { int to, cap, cost, nxt; } e[200000];
char s[15];

void add(int u, int v, int cap, int cost) {
    e[cnt] = (edge){v, cap, cost, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, -cost, head[v]}, head[v] = cnt++;
}

bool spfa(int s, int t) {
    memset(dist, 0x3f, sizeof(dist));
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
    return dist[t] < 0;
}

void upd(int s, int t) {
    ans += incf[t] * dist[t];
    for (int i = t; i ^ s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap -= incf[t], e[pre[i] ^ 1].cap += incf[t];
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &d, &n);
    for (int i = 0; i < 1 << d; i++) {
        popcnt[i] = __builtin_popcount(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 0; j < d; j++) {
            if (s[j] == '1') a[i] |= 1 << j;
        }
        ans += popcnt[a[i]] + 1;
    }
    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        add(s, i, 1, 0), add(i + n, t, 1, 0);
    }
    memset(id, -1, sizeof(id));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i ^ j && (a[i] & a[j]) == a[i]) {
            add(i, j + n, 1, -(popcnt[a[i]] + 1)), id[i][j] = cnt - 2;
        }
    }
    while (spfa(s, t)) upd(s, t);
    printf("%d\n", ans - 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (~id[i][j] && !e[id[i][j]].cap) nxt[i] = j, mark[j] = 1;
        }
    }
    bool fir = 1;
    for (int i = 1; i <= n; i++) if (!mark[i]) {
        if (fir) fir = 0;
        else printf("R ");
        int S = 0;
        for (int j = i; j; j = nxt[j]) {
            for (int k = 0; k < d; k++) {
                if ((a[j] >> k & 1) && !(S >> k & 1)) printf("%d ", k);
            }
            S = a[j];
        }
    }
    return 0;
}