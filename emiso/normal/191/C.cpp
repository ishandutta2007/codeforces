#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MN 100010
#define LG 20

struct lca_tree {
    vector<vector<pair<int, ll> > > adj;
    vector<int> parent[LG], depth, acum;
    vector<ll> dist;
    int lg, n, built = 0, root;

    lca_tree(int root_, int sz) {
        n = sz, root = root_;
        for(lg = 1; (1 << lg) <= MN; lg++); lg--;
        assert(lg < LG);
        for(int i = 0; i <= lg; i++) parent[i].resize(n+1);
        depth.resize(n+1); dist.resize(n+1); adj.resize(n+1);
        acum.resize(n+1);
    }

    void dfs(int u, int p = -1) {
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

int n, k, ans[MN];
map<pair<int, int>, int> ed;

int main() {
    scanf("%d", &n);

    lca_tree t(1, n);

    for(int i = 0; i + 1 < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        ed[{u, v}] = i;
        ed[{v, u}] = i;
        t.adj[u].push_back({v, 1});
        t.adj[v].push_back({u, 1});
    }

    t.build(1);
    scanf("%d", &k);
    while(k--) {
        int u, v;
        scanf("%d %d", &u, &v);
        t.acum[u]++;
        t.acum[v]++;
        t.acum[t.get_lca(u, v)] -= 2;
    }

    vector<int> v;
    for(int i = 1; i <= n; i++) v.push_back(i);
    sort(v.begin(), v.end(), [&](int a, int b) {
         return t.depth[a] > t.depth[b];
    });

    for(int x : v) {
        if(x == 1) continue;
        int y = t.parent[0][x];
        ans[ed[{x, y}]] = t.acum[x];
        t.acum[t.parent[0][x]] += t.acum[x];
    }

    for(int i = 0; i + 1 < n; i++) {
        printf("%d ", ans[i]);
    }
}