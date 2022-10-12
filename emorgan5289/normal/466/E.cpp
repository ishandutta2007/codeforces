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

// both unite and query take effectively constant time
struct unionfind {

    int length;
    vector<int> parent;

    unionfind(int s) {
        length = s;
        parent.assign(s, 0);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int rep(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = rep(a);
        b = rep(b);
        if (a == b)
            return;
        parent[b] = a;
    }

    // returns true if a and b are in the same set.
    inline bool query(int a, int b) {
        return rep(a) == rep(b);
    }
};

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
        parent.assign(maxexp+1, vector<int>(adj.size()));
        visited.assign(adj.size(), 0);

        _label_parent(root, adj);
        for (int exp = 1; exp <= maxexp; exp++)
            for (int i = 0; i < adj.size(); i++)
                parent[exp][i] = parent[exp-1][parent[exp-1][i]];
    }

    // Returns the k-th ancestor of node i.
    int query(int i, int k) {
        for (int j = 0; (1<<j) <= k; j++)
            if (k&(1<<j))
                i = parent[j][i];
        return i;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; fin >> n >> m;
    int c = 1, e, r = -1;

    vector<array<int, 5>> ev(m);
    vector<int> res(m, -1), deg(n+1, 0), depth(n+1, 0);
    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        fin >> ev[i][4];
        ev[i][0] = c; ev[i][1] = i;
        if (ev[i][4] == 1) {
            fin >> ev[i][2] >> ev[i][3];
            adj[ev[i][3]].pb(ev[i][2]);
            deg[ev[i][2]]++;
        }
        if (ev[i][4] == 2) {
            c++; fin >> ev[i][2];
        }
        if (ev[i][4] == 3)
            fin >> ev[i][2] >> ev[i][0];
    }

    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            adj[0].pb(i);

    unionfind u(n+1);
    ktha k(adj, 0);

    vector<int> stack = {0};
    while (!stack.empty()) {
        int i = stack.back(); stack.pop_back();
        for (int j : adj[i]) {
            depth[j] = depth[i]+1;
            stack.pb(j);
        }
    }

    sort(all(ev));
    for (auto& [_, i, x, y, t] : ev) {
        if (t == 1)
            u.unite(x, y);
        if (t == 2)
            e = x;
        if (t == 3) {
            res[i] = u.query(e, x) && (k.query(e, depth[e]-depth[x]) == x);
        }
    }

    for (auto& x : res)
        if (x != -1)
            cout << (x ? "YES" : "NO") << "\n";
}