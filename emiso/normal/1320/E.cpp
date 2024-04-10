#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MN 200010
#define LG 20

struct lca_tree {
    vector<vector<pair<int, ll> > > adj;
    vector<int> parent[LG], depth, st;
    vector<ll> dist;
    int lg, n, built = 0, root, tt;

    lca_tree(int root_, int sz) {
        n = sz, root = root_;
        tt = 0;
        for(lg = 1; (1 << lg) <= MN; lg++); lg--;
        assert(lg < LG);
        for(int i = 0; i <= lg; i++) parent[i].resize(n+1);
        depth.resize(n+1); dist.resize(n+1); adj.resize(n+1); st.resize(n+1);
    }

    void dfs(int u, int p = -1) {
        st[u] = ++tt;
        for (auto e : adj[u]) {
            int v = e.first;
            if (v != p) {
                dist[v] = e.second + dist[u];
                depth[v] = 1 + depth[u];
                parent[0][v] = u;
                dfs(v, u);
            }
        }
    }

    void build(int node) {
        dist[node] = depth[node] = 0;
        dfs(node);
        parent[0][node] = node;
        for(int j = 1; j <= lg; j++)
            for(int i = 0; i <= n; i++)
                parent[j][i] = parent[j-1][parent[j-1][i]];
        built = 1;
    }

    int get_lca(int x, int y) {
        if(!built) build(root);
        if(depth[x] < depth[y]) swap(x,y);

        for(int i = lg; i >= 0; i--)
            if(depth[x] - depth[y] >= (1 << i))
                x = parent[i][x];

        if(x == y) return x;

        for(int i = lg; i >= 0; i--)
            if(parent[i][x] != parent[i][y]) {
                x = parent[i][x];
                y = parent[i][y];
            }

        return parent[0][x];
    }

    ll distance(int x, int y) {
        if(!built) build(root);
        return dist[x] + dist[y] - 2LL*dist[get_lca(x, y)];
    }
};

struct D {
    int d, v, rem;
    bool operator < (const D& o) const {
        return tie(d, v, rem) < tie(o.d, o.v, o.rem);
    }
};

int ans[MN], id[MN];

int main() {
    int n, q;
    scanf("%d", &n);

    lca_tree t(1, n);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        t.adj[u].emplace_back(v, 1);
        t.adj[v].emplace_back(u, 1);
    }

    t.build(1);

    scanf("%d", &q);
    while(q--) {
        int k, m;
        vector<int> c, add;
        vector<pair<int, int>> viruses;

        scanf("%d %d", &k, &m);
        for(int i = 0; i < k; i++) {
            int v, s;
            scanf("%d %d", &v, &s);
            viruses.emplace_back(v, s);
            c.push_back(v);

        }
        for(int i = 0; i < m; i++) {
            scanf("%d", &ans[i]);
            c.push_back(ans[i]);
        }

        sort(c.begin(), c.end(), [&](int u, int v){return t.st[u] < t.st[v];});

        for(int i = 0; i + 1 < (int)c.size(); i++) {
            int u = c[i], v = c[i+1], lca = t.get_lca(u, v);
            if(lca != u && lca != v) add.push_back(lca);
        }

        c.insert(c.end(), add.begin(), add.end());
        sort(c.begin(), c.end(), [&](int u, int v){return t.st[u] < t.st[v];});

        vector<int> tmp;
        for(int i = 0; i < (int)c.size(); i++) {
            if(!i || c[i] != c[i-1]) tmp.push_back(c[i]);
        }
        c = tmp;

        lca_tree comp(0, c.size());
        stack<int> path;

        for(int i = 0; i < (int)c.size(); i++) {
            while(!path.empty() && t.get_lca(c[path.top()], c[i]) != c[path.top()]) {
                path.pop();
            }

            if(!path.empty()) {
                int pt = path.top();
                int d = t.distance(c[i], c[pt]);
                comp.adj[i].emplace_back(pt, d);
                comp.adj[pt].emplace_back(i, d);
            }

            path.push(i);
            id[c[i]] = i;
        }

        /// dijkstra
        vector<D> dist(c.size(), {INT_MAX, 0, 0});
        set<pair<D, int>> fila;

        for(int i = 0; i < k; i++) {
            int cr = id[viruses[i].first];
            dist[cr] = {0, i, 0};
            fila.insert({dist[cr], cr});
        }

        while(!fila.empty()) {
            auto tt = *(fila.begin());
            fila.erase(tt);

            D d = tt.first;
            int u = tt.second;

            if(dist[u] < d) continue;

            for(auto ed : comp.adj[u]) {
                int v = ed.first;
                ll cost = ed.second;
                int nrem = d.rem + cost;

                D nno({(nrem + viruses[d.v].second - 1)/ viruses[d.v].second, d.v, nrem});
                if(nno < dist[v]) {
                    dist[v] = nno;
                    fila.insert({dist[v], v});
                }
            }
        }

        for(int i = 0; i < m; i++) {
            printf("%d ", dist[id[ans[i]]].v + 1);
        } puts("");
    }
    return 0;
}