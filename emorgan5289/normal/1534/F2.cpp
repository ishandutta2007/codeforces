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
 
struct scc {
 
    vector<vector<int>> adj, c_adj, r_adj;
    vector<int> c, v, ord;
 
    scc(vector<vector<int>> _adj) : adj(_adj) {}
 
    void dfs(int i) {
        v[i] = 1;
        for (int j : adj[i])
            if (!v[j]) dfs(j);
        ord.push_back(i);
    }
 
    void partition(int i, int t) {
        v[i] = 1, c[i] = t;
        for (int j : r_adj[i])
            if (!v[j]) partition(j, t);
    }
 
    // returns a component vector c s.t. c[i] == c[j] iff i and j
    // are in the same strongly connected component, runs in O(E).
    vector<int> components() {
        int n = adj.size(), t = 0;
        v.assign(n, 0), r_adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j : adj[i]) r_adj[j].push_back(i);
            if (!v[i]) dfs(i);
        }
        v.assign(n, 0), c.assign(n, 0);
        for (int i = n-1; i >= 0; i--)
            if (!v[ord[i]]) partition(ord[i], t++);
        return c;
    }
 
    // returns an adjacency list over the scc's where an edge u->v means there is
    // some edge i->j in the original graph s.t. c[i] = u && c[j] = v, runs in O(E).
    vector<vector<int>> dag() {
        if (c.empty()) components();
        if (c.empty()) return {};
        c_adj.resize(*max_element(c.begin(), c.end())+1);
        for (int i = 0; i < adj.size(); i++)
            for (int j : r_adj[i])
                if (c_adj[c[j]].empty() || c[i] != c_adj[c[j]].back())
                    if (c[i] != c[j]) c_adj[c[j]].push_back(c[i]);
        debug("b");
        return c_adj;
    }
};

// Accepts an adjacency list. Assumes that the graph is connected and acyclic.
// Runs in O(V+E).

vector<int> toposort(vector<vector<int>> adj) {
    vector<int> out, stk, in(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
        for (int j : adj[i]) in[j]++;
    for (int i = 0; i < adj.size(); i++)
        if (!in[i]) stk.push_back(i);
    while (!stk.empty()) {
        out.push_back(stk.back()); stk.pop_back();
        for (int j : adj[out.back()])
            if (!--in[j]) stk.push_back(j);
    }
    return out;
}
 
ll n, m;
vector<string> s;
vector<vector<int>> adj;
vector<vector<int>> mm;
int t = 0;
 
ll get(int i, int j) {
    if (mm[i][j] == -1) {
        mm[i][j] = t++;
    }
    return mm[i][j];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    reverse(all(s));
    debug(s);
    mm.assign(n, vector<int>(m, -1));
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    vector<ll> p(m, -1);
    adj.resize(n*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '#') continue;
            get(i, j);
            if (p[j] != -1) {
                adj[get(i, j)].pb(get(p[j], j));
            }
            if (i != n-1 && s[i+1][j] == '#') adj[get(i, j)].pb(get(i+1, j));
            if (j != 0) {
                if (s[i][j-1] == '#')
                    adj[get(i, j)].pb(get(i, j-1));
                else if (p[j-1] != -1)
                    adj[get(i, j)].pb(get(p[j-1], j-1));
            }
            if (j != m-1) {
                if (s[i][j+1] == '#')
                    adj[get(i, j)].pb(get(i, j+1));
                else if (p[j+1] != -1)
                    adj[get(i, j)].pb(get(p[j+1], j+1));
            }
            p[j] = i;
        }
    }
    debug();
    while (adj.size() > t) adj.pop_back();

    auto adj_scc = scc(adj);
    auto c = adj_scc.components();
    auto dag = adj_scc.dag();

    int k = dag.size();

    debug(k);

    debug(dag);
    vector<vector<int>> grp(k);
    vector<int> l(k, inf), r(k, -inf);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '#')
                grp[c[get(i, j)]].pb(j);

    for (int i = 0; i < k; i++) {
        sort(all(grp[i]));
    }
    debug(grp);

    vector<int> ord(k), in(k);
    for (int i = 0; i < k; i++)
        for (int j : dag[i]) in[j]++;

    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){
        return grp[i][0] < grp[j][0];
    });

    for (int i = 0; i < k; i++) {
        l[ord[i]] = r[ord[i]] = i;
    }

    debug(l, r);

    debug(ord);
    debug(in);
    for (int i : toposort(dag))
        for (int j : dag[i]) {
            cmin(l[j], l[i]);
            cmax(r[j], r[i]);
        }

    set<array<int, 2>> sv;
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (s[i][j] == '#' && a[j]-- > 0) {
                int x = c[get(i, j)];
                sv.insert({l[x], r[x]});
            }

    vector<array<int, 2>> v;
    for (auto& lr : sv) v.pb(lr);
    sort(all(v), [&](auto i, auto j){
        return i[1] < j[1];
    });

    debug(v);

    int x = -1, ans = 0;
    for (auto& [i, j] : v) {
        if (x >= i && x <= j) continue;
        ans++;
        x = j;
    }

    cout << ans << "\n";
}