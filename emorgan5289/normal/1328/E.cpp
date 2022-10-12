#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int parent[300000], depth[300000];

void bfs(vector<vector<int>>& adj, int root) {
    vector<int> stack = {root};
    depth[root] = 0;
    while (!stack.empty()) {
        int i = stack.back();
        stack.pop_back();
        for (int& j : adj[i]) {
            stack.push_back(j);
            parent[j] = i;
            depth[j] = depth[i]+1;
            adj[j].erase(find(adj[j].begin(), adj[j].end(), i));
        }
    }
}

struct ktha {

    vector<vector<int>> parent;
    vector<bool> visited;

    void _label_parent(int i, vector<vector<int>>& adj) {
        visited[i] = 1;
        for (int j : adj[i])
            if (!visited[j]) {
                parent[0][j] = i;
                _label_parent(j, adj);
            }
    }

    // Accepts an adjecency list. Can include or exlude parents, it works either way.
    ktha(vector<vector<int>>& adj, int root) {

        int maxexp = floor(log2(adj.size()));
        parent = vector<vector<int>>(maxexp+1, vector<int>(adj.size()));
        visited = vector<bool>(adj.size(), 0);

        _label_parent(root, adj);
        for (int exp = 1; exp <= maxexp; exp++)
            for (int i = 0; i < adj.size(); i++)
                parent[exp][i] = parent[exp-1][parent[exp-1][i]];
    }

    // Returns the k-th ancestor of node i.
    int query(int i, int k) {
        int exp = 0;
        for (int mask = 1; k > 0; mask <<= 1) {
            if (k&mask) {
                k -= mask;
                i = parent[exp][i];
            }
            exp += 1;
        }
        return i;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; fin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; fin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    parent[0] = 0;
    bfs(adj, 0);
    ktha q(adj, 0);

    for (int i = 0; i < m; i++) {
        int k; fin >> k;
        vector<int> b(k);
        for (auto& x : b) {
            fin >> x; x--; x = parent[x];
        }
        sort(all(b), [&](int x, int y){return depth[x] > depth[y];});
        bool v = 1;
        // debug(i, b);
        for (int j = 0; j < k-1; j++) {
            // debug(b[j], b[j+1], q.query(b[j], depth[b[j]]-depth[b[j+1]]));
            v &= (b[j+1] == q.query(b[j], depth[b[j]]-depth[b[j+1]]));
            if (!v) break;
        }

        cout << (v ? "YES\n" : "NO\n"); 
    }
}