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
        c_adj.resize(*max_element(c.begin(), c.end())+1);
        for (int i = 0; i < adj.size(); i++)
            for (int j : r_adj[i])
                if (c_adj[c[j]].empty() || c[i] != c_adj[c[j]].back())
                    if (c[i] != c[j]) c_adj[c[j]].push_back(c[i]);
        return c_adj;
    }
};
 
 
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
    adj.resize(10*n*m);
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
    while (adj.size() > t) adj.pop_back();
 
    // part 1
 
    debug(t);
    debug(adj);

    if (t == 0) {
        cout << "0\n"; return 0;
    }

    adj = scc(adj).dag();
    debug(adj);
    t = adj.size();
    vector<ll> in(t);
    for (int i = 0; i < t; i++)
        for (int j : adj[i])
            in[j]++;
    ll ans = 0;
    for (int i = 0; i < t; i++)
        if (in[i] == 0)
            ans++;
    cout << ans << "\n";
}