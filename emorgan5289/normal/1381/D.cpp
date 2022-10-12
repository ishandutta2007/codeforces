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

// combined data structure for various ancestor-related queries.

struct ancestor {

    vector<int> vin, vout, d;
    vector<vector<int>> adj, p;
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

    ancestor() {};

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
vector<bool> p;
vector<multiset<int>> dp;
int len;
vector<int> l, r;

void dfs1(int i, int k) {
    for (auto& j : adj[i])
        if (j != k) {
            dfs1(j, i);
            if (dp[j].empty()) dp[i].insert(1);
            else dp[i].insert(1+*--dp[j].end());
        }
}

void shift(int i, int j) {
    if (dp[j].empty()) dp[i].erase(dp[i].find(1));
    else dp[i].erase(dp[i].find(1+*--dp[j].end()));
    if (dp[i].empty()) dp[j].insert(1);
    else dp[j].insert(1+*--dp[i].end());
}

void dfs2(int i, int k) {
    int c = 0;
    for (auto& x : dp[i])
        if (x >= len)
            c++;
    if (c >= 3) p[i] = 1;
    for (auto& j : adj[i])
        if (j != k) {
            shift(i, j);
            dfs2(j, i);
            shift(j, i);
        }
}

void dfs3(int i, int k) {
    for (auto& j : adj[i])
        if (j != k) dfs3(j, i);
    p[k] = p[k] || p[i];
}

void dfs4(int i, int k) {
    for (auto& j : adj[i])
        if (j != k)
            dfs4(j, i), l[i] = max(l[i], l[j]+1);
}

void dfs5(int i, int k) {
    for (auto& j : adj[i])
        if (j != k)
            dfs5(j, i), r[i] = max(r[i], r[j]+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b; a--, b--;
        adj.assign(n, {}), p.assign(n, 0), dp.assign(n, {});
        for (int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v), adj[v].pb(u);
        }
        ancestor qa(adj, a), qb(adj, b);
        len = qa.d[b]-1;
        vector<bool> onpath(n);
        for (int i = 0; i < n; i++)
            onpath[i] = qa.step(i, a) != qb.step(i, b);
        dfs1(0, 0), dfs2(0, 0);
        for (int i = 0; i < n; i++) {
            if (!onpath[i]) {
                int j = qa.step(i, a);
                if (onpath[j]) dfs3(i, j);
            }
        }
        vector<int> path;
        int x = a;
        for (int i = 0;; i++) {
            path.pb(x);
            if (x == b) break;
            x = qb.step(x, b);
        }
        l.assign(n, 0), r.assign(n, 0);
        dfs4(a, a), dfs5(b, b);
        vector<bool> va(len+1, 0), vb(len+1, 0);
        va[0] = vb[len] = 1;
        a = 0, b = len;
        bool flag = 0;
        debug(path);
        debug(l);
        debug(r);
        int cntr = 0;
        while (1) {
            int k = l[path[b]];
            while (k--) {
                if (a < 0) {a++; b++; continue;};
                if (a > len) goto done;
                if (p[path[a]]) {
                    flag = 1; goto done;
                }
                a++; b++;
            }
            if (a >= 0 && a <= len && p[path[a]]) {
                flag = 1; goto done;
            }
            if (a > len) goto done;
            if (va[a]) cntr++;
            va[a] = 1;
            debug(a, b);
            k = r[path[a]];
            while (k--) {
                if (b > len) {b--; a--; continue;};
                if (b < 0) goto done;
                if (p[path[b]]) {
                    flag = 1; goto done;
                }
                b--; a--;
            }
            if (b >= 0 && b <= len && p[path[b]]) {
                flag = 1; goto done;
            }
            if (b < 0) goto done;
            if (vb[b]) cntr++;
            vb[b] = 1;
            debug(a, b);
            if (cntr >= 3) break;
        }
        done:;
        cout << (flag ? "YES" : "NO") << "\n";
    }
}