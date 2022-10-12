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

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (adj.empty()) return;
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
        while (k) {
            int j = k&-k;
            i = p[i][__builtin_ctz(j)];
            k -= j;
        }
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

    // returns the number of edges between i and j in O(logn) time.
    int dist(int i, int j) {
        return d[i]+d[j]-2*d[lca(i, j)];
    }
};

// note, the file lca_old.cpp allows lca queries in O(1) time instead of O(logn) time,
// but has a much higher constant factor and can cause MLE for around 5*10^5 vertices.

vector<vector<int>> subadj;
vector<int> c;
vector<array<int, 2>> dp;
// 0 = solve in general
// 1 = solve where nothing can be exposed upwards

void dfs(int i) {
    for (int j : subadj[i])
        dfs(j);
    if (c[i]) {
        for (int j : subadj[i]) {
            dp[i][0] += dp[j][1];
            dp[i][1] += dp[j][1];
        }
        dp[i][1]++;
    } else {
        // take root
        for (int j : subadj[i]) {
            dp[i][0] += dp[j][0];
            dp[i][1] += dp[j][0];
        }
        dp[i][0]++, dp[i][1]++;
        // don't take root
        int x = 0, y = 0;
        if (subadj[i].size() == 1) {
            x = dp[subadj[i][0]][0];
            y = dp[subadj[i][0]][1];
        } else {
            int z = inf;
            for (int j : subadj[i]) {
                x += dp[j][1];
                y += dp[j][1];
                cmin(z, dp[j][0]-dp[j][1]);
            }
            x += z;
        }
        cmin(dp[i][0], x);
        cmin(dp[i][1], y);
    }
    debug(i, dp[i]);
}

int solve(int r) {
    debug(subadj, r, c);
    int n = subadj.size();
    dp.assign(n, {0, 0});
    dfs(r);
    return dp[r][0];
}

vector<vector<int>> adj;
ancestor anc;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    anc = ancestor(adj, 0);
    ll q; cin >> q;
    vector<int> rvin(n);
    for (int i = 0; i < n; i++)
        rvin[anc.vin[i]] = i;
    while (q--) {
        set<int> s;
        ll k; cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i]; v[i]--;
            s.insert(v[i]);
        }
        sort(all(v), [&](int i, int j){
            return anc.vin[i] < anc.vin[j];
        });
        for (int i = 0; i+1 < v.size(); i++)
            s.insert(anc.lca(v[i], v[i+1]));
        vector<int> vins;
        for (int i : s) vins.pb(anc.vin[i]);
        sort(all(vins));
        map<int, int> label;
        int t = 0;
        for (int i : s) label[i] = t++;
        subadj.assign(s.size(), {});
        vector<int> stk;
        int r = -1;
        bool ok = 1;
        c.assign(subadj.size(), 0);
        for (int i : v)
            c[label[i]] = 1;
        for (int i : vins) {
            i = rvin[i];
            while (!stk.empty() && !anc.is_ancestor(stk.back(), i))
                stk.pop_back();
            if (stk.empty()) r = label[i];
            else {
                subadj[label[stk.back()]].pb(label[i]);
                if (anc.dist(i, stk.back()) == 1 && c[label[i]] && c[label[stk.back()]])
                    ok = 0;
            }
            stk.pb(i);
        }
        debug(label);
        if (ok)
            cout << solve(r) << "\n";
        else
            cout << "-1\n";
    }
}