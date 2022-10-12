#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

struct centroid {

    int c, s;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> sz;

    centroid(int n) : adj(n), vis(n, 0), sz(n) {}
    centroid(vector<vector<int>> _adj) :
        adj(_adj), vis(_adj.size(), 0), sz(_adj.size()) {}

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

    // returns the centroid of the unvisited
    // component of the tree containing r
    int find(int r) {
        dfs1(r, r);
        s = sz[r]/2;
        dfs2(r, r);
        return c;
    }

    // returns the vertices of the tree ordered in a
    // pre-order dfs traversal of the centroid tree in O(VlogV)
    vector<int> list() {
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
    pair<int, vector<vector<int>>> tree() {
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

vector<vector<int>> adj;
vector<ll> s, val;
ll r, b, t1, t2;

void dfs(int i, int k) {
    s[i] = 1;
    for (int j : adj[i])
        if (j != k) dfs(j, i), s[i] += s[j];
}

void dfs2(int i, int k, bool small) {
    if (small) {
        t1 += 1;
        val[i] = t1;
    } else {
        t2 += b;
        val[i] = t2;
    }
    cout << i+1 << " " << k+1 << " " << val[i]-val[k] << "\n";
    for (int j : adj[i])
        if (j != k) dfs2(j, i, small);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    adj.resize(n);
    s.resize(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    r = centroid(adj).find(0);
    dfs(r, r);
    debug(r);
    for (int i : adj[r])
        debug(i, s[i]);
    vector<bool> dp(n+1, 0), ch(n, 0);
    vector<int> nxt(n+1);
    dp[0] = 1;
    nxt[0] = -1;
    for (int i : adj[r])
        for (int j = n; j >= s[i]; j--)
            if (dp[j-s[i]] && !dp[j])
                dp[j] = 1, nxt[j] = i;
    for (int i = 0; i <= n; i++)
        if (dp[i] && 3*i >= n && 3*i <= 2*n)
            b = i+1;
    debug(b);
    ll y = b-1;
    val.resize(n);
    while (y > 0) {
        int i = nxt[y];
        debug(y, i);
        y -= s[i], ch[i] = 1;
    }
    for (int i : adj[r])
        dfs2(i, r, ch[i]);
    debug(t1, t2);
    if (n != 1) {
        // assert(y == 0);
        // assert(t1+t2 >= n*n*2/9);
    }
}