#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct centroid {

    int c, s;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> sz;

    centroid(int n) : adj(n), vis(n, 0), sz(n) {}

    // add an edge between i and j
    void edge(int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    void dfs1(int i, int p) {
        sz[i] = 1;
        for (int j : adj[i])
            if (j != p && !vis[j]) {
                dfs1(j, i);
                sz[i] += sz[j];
            }
    }

    void dfs2(int i, int p) {
        bool v = sz[i] >= s;
        for (int j : adj[i])
            if (j != p && !vis[j]) {
                dfs2(j, i);
                v &= sz[j] <= s;
            }
        if (v) c = i;
    }

    int find(int r) {
        dfs1(r, r);
        s = sz[r]/2;
        dfs2(r, r);
        return c;
    }

    // returns the vertices of the tree ordered in a
    // pre-order dfs traversal of the centroid tree in O(VlogV)
    vector<int> solve() {
        vector<int> out, stk = {0};
        while (!stk.empty()) {
            int i = find(stk.back()); stk.pop_back();
            out.push_back(i);
            vis[i] = 1;
            for (int j : adj[i])
                if (!vis[j])
                    stk.push_back(j);
        }
        return out;
    }

    // returns {root, children-only adjacency list} of the centroid tree
    pair<int, vector<vector<int>>> full_tree() {
        int root = find(0);
        vector<vector<int>> out(adj.size());
        vector<int> stk = {root};
        while (!stk.empty()) {
            int i = stk.back(); stk.pop_back();
            vis[i] = 1;
            for (int j : adj[i])
                if (!vis[j]) {
                    int r = find(j);
                    out[i].push_back(r);
                    stk.push_back(r);
                }
        }
        return {root, out};
    }
};

const int maxn = 50005;
vector<int> adj[maxn];
ll f[maxn];
bool vis[maxn];
int n, k;
vector<vector<int>> d;

void dfs(int i, int p, int x) {
    d.back().pb(x);
    for (auto& j : adj[i])
        if (j != p && !vis[j])
            dfs(j, i, x+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    centroid cd(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        cd.edge(u, v);
        adj[u].pb(v); adj[v].pb(u);
    }
    ll out = 0;
    f[0] = 1;
    for (auto& r : cd.solve()) {
        vis[r] = 1;
        d.clear();
        for (auto& j : adj[r]) {
            d.pb({});
            if (!vis[j])
                dfs(j, r, 1);
        }
        if (d.size() == 0) continue;
        for (auto& v : d)
            for (auto& x : v)
                f[x]++;
        for (auto& v : d) {
            for (auto& x : v)
                f[x]--;
            for (auto& x : v)
                if (x <= k)
                    out += f[k-x];
        }
    }
    cout << out << "\n";
}