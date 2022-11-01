#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct PushRelabel {
    struct Edge {
        int dest, back;
        ll f, c;
    };
    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge*> cur;
    vector<vector<int>> hs;
    vector<int> H;
    
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
    
    void addEdge(int s, int t, ll cap, ll rcap=0) {
        if (s == t) return;
        g[s].push_back({t, (int) g[t].size(), 0, cap});
        g[t].push_back({s, (int) g[s].size() - 1, 0, rcap});
    }
    void addFlow(Edge& e, ll f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) 
            hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    ll maxFlow(int s, int t) {
        int v = (int)g.size(); 
        H[s] = v; 
        ec[t] = 1;
        
        vector<int> co(2*v); 
        co[0] = v-1;

        for (int i = 0; i < v; i++) cur[i] = g[i].data();
        for (Edge& e : g[s]) addFlow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty())
                if (!hi--) 
                    return -ec[s];
            
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0) { // discharge u
                if (cur[u] == g[u].data() + (int)g[u].size()) {
                    H[u] = 1e9;
                    for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
                    H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        for (int i = 0; i < v; i++) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1) {
                    addFlow(*cur[u], min(ec[u], cur[u]->c));
                } else ++cur[u];
            } 
        }
    }
    bool leftOfMinCut(int a) { return H[a] >= g.size(); }
};

typedef array<ll, 3> Edge;
vector<Edge> gomoryHu(int N, vector<Edge> ed) { // 1-INDEXED
    vector<Edge> tree;
    vector<int> par(N+1, 1);
    for (int i = 2; i <= N; i++) {
        PushRelabel D(N+1); // Dinic also works
        for (Edge t : ed) D.addEdge(t[0], t[1], t[2], t[2]);
        tree.push_back({i, par[i], D.maxFlow(i, par[i])});
        for (int j = i + 1; j <= N; j++)
            if (par[j] == par[i] && D.leftOfMinCut(j)) par[j] = i;
    }
    return tree;
}

int n, m, ans, maxi = -1, ma, mb, parent[220];

vector<pair<int, int>> adj[220];
vector<int> order;
priority_queue<pair<int, int>> nxt;

vector<Edge> edges, tree;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, a, b, c; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({a, b, c});
    }
    tree = gomoryHu(n, edges);

    for(Edge edge : tree) {
        ans += edge[2];
        if(maxi < edge[2]) {
            ma = edge[0];
            mb = edge[1];
            maxi = edge[2];
        }
        adj[edge[0]].emplace_back(edge[2], edge[1]);
        adj[edge[1]].emplace_back(edge[2], edge[0]);
    }

    order.push_back(ma);
    order.push_back(mb);
    
    for(auto ed : adj[ma]) if(ed.second != mb) nxt.push(ed), parent[ed.second] = ma;
    for(auto ed : adj[mb]) if(ed.second != ma) nxt.push(ed), parent[ed.second] = mb;

    while(!nxt.empty()) {
        int u = nxt.top().second; nxt.pop();
        order.push_back(u);
        for(auto ed : adj[u]) 
            if(ed.second != parent[u]) 
                nxt.push(ed), parent[ed.second] = u;
    }

    printf("%d\n", ans);
    for(int x : order) printf("%d ", x);
    return 0;
}

/*
3 3
1 2 5
1 3 10
2 3 7
*/