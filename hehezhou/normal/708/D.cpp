#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
    int u, v, f, c, nxt;
} e[100010];
int head[210];
int dis[210], pre[210];
int tot = 1;
inline void addedge(int u, int v, int f, int c) {
    e[++tot] = edge{u, v, f, c, head[u]};
    head[u] = tot;
    e[++tot] = edge{v, u, 0, -c, head[v]};
    head[v] = tot;
}
int s, t, inque[210], ansf;
inline int work() {
    memset(dis, 0x7f, sizeof dis);
    pre[s] = -1, dis[s] = 0;
    queue<int> q;
    q.push(s);
    inque[s] = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = head[now]; i; i = e[i].nxt) {
            if(e[i].f && dis[e[i].v] > dis[now] + e[i].c) {
                dis[e[i].v] = dis[now] + e[i].c;
                pre[e[i].v] = i;
                if(!inque[e[i].v]) inque[e[i].v] = 1, q.push(e[i].v);
            }
        }
        inque[now] = 0;
    }
    if(dis[t] > 2e9) return -1;
    int minF = 2e9;
    for(int i = t; i != s; i = e[pre[i]].u) minF = min(minF, e[pre[i]].f);
    for(int i = t; i != s; i = e[pre[i]].u) e[pre[i]].f -= minF, e[pre[i] ^ 1].f += minF;
    ansf += minF;
    return minF * dis[t];
}
int flow[110];
int main() {
    scanf("%d%d", &n, &m);
    addedge(n, 1, 2e9, 0);
    s = 0, t = n + 1;
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int u, v, f, c;
        scanf("%d%d%d%d", &u, &v, &c, &f);
        if(f <= c) {
            flow[v] += f;
            flow[u] -= f;
            addedge(u, v, c - f, 1);
            addedge(u, v, 2e9, 2);
            addedge(v, u, f, 1);
        }
        else {
            flow[v] += c;
            flow[u] -= c;
            ans += f - c;
            addedge(u, v, f - c, 0);
            addedge(v, u, c, 1);
            addedge(u, v, 2e9, 2);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(flow[i] < 0) addedge(i, t, -flow[i], 0);
        else addedge(s, i, flow[i], 0);
    }
    for(int tmp = work(); ~tmp; tmp = work()) ans += tmp;
    return cout << ans << endl, 0;
}