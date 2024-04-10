#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct ancestor {

    vector<int> vin, vout, d;
    vector<vector<int>> &adj, p;
    int n, t = 0, e;

    void dfs(int i, int v) {
        vin[i] = t++;
        p[i][0] = v, d[i] = d[v]+1;
        for (int j = 1; j <= e; j++)
            p[i][j] = p[p[i][j-1]][j-1];
        for (auto& j : adj[i])
            if (j != v) dfs(j, i);
        vout[i] = t-1;
    }

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<int>>& _adj, int root) : adj(_adj), n(_adj.size()) {
        vin.resize(n), vout.resize(n), d.assign(n, 0);
        e = ceil(log2(n));
        p.assign(n, vector<int>(e+1));
        dfs(root, root);
    }

    // returns true if i is an ancestor of j in O(1) time.
    bool is_ancestor(int i, int j) const {
        return vin[i] <= vin[j] && vout[i] >= vout[j];
    }

    // returns the k'th ancestor of i O(logk) time.
    int ktha(int i, int k) const {
        for (int j = 0; (1<<j) <= k; j++)
            if (k&(1<<j)) i = p[i][j];
        return i;
    }

    // returns the LCA of i and j in O(logn) time.
    int lca(int i, int j) const {
        if (is_ancestor(i, j)) return i;
        if (is_ancestor(j, i)) return j;
        for (int k = e; k >= 0; k--)
            if (!is_ancestor(p[i][k], j))
                i = p[i][k];
        return p[i][0];
    }

    // returns the vertex one step along the path from i to j in O(logn) time.
    int step(int i, int j) const {
        return is_ancestor(i, j) ? ktha(j, d[j]-d[i]-1) : p[i][0];
    }
};

vector<vector<int>> adj;
int ans = 0;

int dfs(int i, int k) {
    vector<int> d;
    int c1 = 0, c2 = 0;
    for (auto& j : adj[i])
        if (j != k) {
            int c = 1+dfs(j, i);
            if (c >= c1) {
                c2 = c1; c1 = c;
            }
            else if (c >= c2)
                c2 = c;
        }
    ans = max(ans, c1+c2);
    return c1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b, da, db; cin >> n >> a >> b >> da >> db; a--, b--;
        adj.assign(n, {});
        for (int i = 0; i < n-1; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
        }
        ancestor an(adj, 0);
        if (an.d[a]+an.d[b]-2*an.d[an.lca(a, b)] <= da) {
            cout << "Alice\n"; continue;
        }
        ans = 0;
        dfs(0, 0);
        debug(ans);
        if (db > 2*da && 2*da < ans) {
            cout << "Bob\n"; continue;
        } else {
            cout << "Alice\n";
        }
    }
}