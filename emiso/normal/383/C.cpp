#include <bits/stdc++.h>
#define MN 200100
#define MAGIC 1400

using namespace std;

int st[MN], ft[MN], t = 1, dist[MN];
vector<int> adj[MN];

void dfs(int node, int parent = -1) {
    st[node] = t++;
    for(int v : adj[node]) {
        if(v == parent) continue;
        dist[v] = dist[node] + 1;
        dfs(v, node);
    }
    ft[node] = t;
}

int upd[MN], val[MN];
void refresh(int node, int parent = -1) {
    val[node] = val[node] + upd[node];
    for(int v : adj[node]) {
        if(v == parent) continue;
        upd[v] -= upd[node];
        refresh(v, node);
    }
    upd[node] = 0;
}

vector<pair<int, int> > buffer;
void update(int node, int v) {
    buffer.emplace_back(node, v);
    if(buffer.size() >= MAGIC) {
        for(auto &b : buffer)
            upd[b.first] += b.second;
        refresh(1);
        buffer.clear();
    }
}

int query(int node) {
    int ret = val[node];
    for(auto &b : buffer) {
        int no = b.first, v = b.second;
        if(st[node] < st[no] || st[node] >= ft[no]) continue;
        int parity = (dist[node] - dist[no]) & 1;
        ret += v * (parity ? -1 : 1);
    }
    return ret;
}

int n, m, a, b, tp, x, y;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &val[i]);

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &tp, &x);
        if(tp == 1) {
            scanf("%d", &y);
            update(x, y);
        } else {
            printf("%d\n", query(x));
        }
    }
    return 0;
}