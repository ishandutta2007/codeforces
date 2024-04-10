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
            if (df) {
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

int n, odd, use[502], resp;
vector<int> v, ans[502];

void dfs(Dinic<500>& g, int no, int comp, int pai = -1) {
    use[no] = 1;
    ans[comp].push_back(no);
    for(auto &ed : g.adj[no]) {
        if(ed.to < n && ed.to != pai && !use[ed.to]) {
            if(v[no] % 2 == 1 && ed.flow ==  1) dfs(g, ed.to, comp, no);
            if(v[no] % 2 == 0 && ed.flow == -1) dfs(g, ed.to, comp, no);
        }
    }
}

bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
    scanf("%d", &n);

    Dinic<500> g;
    v.resize(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        odd += (v[i] % 2);
        if(v[i] % 2) g.addEdge(404, i, 2);
        else g.addEdge(i, 405, 2);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(v[i] % 2 == 1 && v[j] % 2 == 0 && is_prime(v[i] + v[j]))
                g.addEdge(i, j, 1);

    int flow = g.maxFlow(500, 404, 405);
    if(2*odd != n || flow != n) {
        puts("Impossible");
        return 0;
    }

    for(int i = 0; i < n; i++) {
        if(use[i]) continue;
        dfs(g, i, resp++);
    }

    printf("%d\n", resp);
    for(int i = 0; i < resp; i++) {
        printf("%d", ans[i].size());
        for(int x : ans[i]) printf(" %d", x + 1);
        puts("");
    }

    return 0;
}