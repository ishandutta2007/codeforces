#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<int SZ> struct Dinic {
    typedef ll F;
    struct Edge {
        int to, rev;
        F flow, cap;
    };
    int N, s, t;
    vector<Edge> adj[SZ];
    typename vector<Edge> ::iterator cur[SZ];
    void addEdge(int u, int v, F cap) {
        assert(cap >= 0);
        Edge a {v, (int)adj[v].size(), 0, cap}, b {u, (int)adj[u].size(), 0, 0};
        adj[u].push_back(a), adj[v].push_back(b);
    }
    int level[SZ];
    bool bfs() {
        // level = shortest distance from source
        // after computing flow, edges {u,v} such that level[u] != - 1 and level[v] = -1 are part of min cut
        for(int i = 0; i < N; i++) level[i] = -1, cur[i] = begin(adj[i]);
        queue<int> q({s});
        level[s] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &e : adj[u]) if (level[e.to] < 0 && e.flow < e.cap)
                q.push(e.to), level[e.to] = level[u] + 1;
        }
        return level[t] >= 0;
    }
    F sendFlow(int v, F flow) {
        if (v == t) return flow;
        for (; cur[v] != end(adj[v]); cur[v]++) {
            Edge &e = *cur[v];
            if (level[e.to] != level[v] + 1 || e.flow == e.cap) continue;
            auto df = sendFlow(e.to, min(flow, e.cap - e.flow));
            if (df) { // saturated at least one edge
                e.flow += df;
                adj[e.to][e.rev].flow -= df;
                return df;
            }
        }
        return 0;
    }
    F maxFlow(int n, int _s, int _t) {
        N = n, s = _s, t = _t;
        if (s == t) return -1;
        F tot = 0;
        while (bfs())
            while (auto df = sendFlow(s, numeric_limits<F> ::max())) tot += df;
        return tot;
    }
};

#define MN 200010
int color[MN];
vector<int> adj[MN];
Dinic<MN> G;

void dfs(int no, int c = 1) {
    if(color[no] == c) return;
    assert(color[no] == 0);
    color[no] = c;
    for(int v : adj[no])
        dfs(v, 3 - c); /// 1 or 2
}

int vertex_cover(int n) {
    int source = n+1, sink = n+2;
    for(int i = 0; i <= n; i++) {
        if(!color[i]) dfs(i);
        if(color[i] == 1) {
            G.addEdge(source, i, 1);
            for(int v : adj[i])
                G.addEdge(i, v, 2*MN); //inf
        }
        else G.addEdge(i, sink, 1);
    }
    return G.maxFlow(n + 3, source, sink);
}

int n, m, id[404][404], cnt, ans;
char g[202][202];

int main() {
    scanf("%d %d", &n, &m);
    memset(g, '.', sizeof g);
    for(int i = 1; i <= n; i++)
        scanf("%s", g[i] + 1);

    vector<pair<int, int>> dir({{-1, 0}, {0, 1},  {1, 0}, {0, -1}});
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] == '#') ans++;
            for(auto d : dir) {
                int x = 2*i + d.first, y = 2*j + d.second;
                if(g[i][j] == '#' && g[i+d.first][j+d.second] == '#' && !id[x][y]) id[x][y] = ++cnt;
            }
            for(int d = 0; d < 4; d++) {
                int x = 2*i + dir[d].first, y = 2*j + dir[d].second;
                int nx = 2*i + dir[(d+1)%4].first, ny = 2*j + dir[(d+1)%4].second;
                if(!id[x][y] || !id[nx][ny]) continue;
                adj[id[x][y]].push_back(id[nx][ny]);
                adj[id[nx][ny]].push_back(id[x][y]);
            }
        }
    }

    printf("%d\n", ans - cnt + vertex_cover(cnt));
    return 0;
}