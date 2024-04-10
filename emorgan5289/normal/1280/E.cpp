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

vector<int> s, t;
vector<double> r, m;
vector<vector<int>> adj;

void add() {
    if (!s.empty()) {
        if (adj[s.back()].size() == 2) {
            int i = adj[s.back()].back();
            adj[s.back()].back() = adj.size();
            adj.pb({i}), t.pb(t[s.back()]);
            s.back() = adj.size()-1;
        }
        adj[s.back()].pb(adj.size());
    }
    adj.pb({}), t.pb(0);
}

void dfs1(int i) {
    for (auto& j : adj[i]) dfs1(j);
    if (t[i] == 0) {m[i] = 1; return;}
    auto x = m[adj[i][0]], y = m[adj[i][1]];
    if (t[i] == 1) m[i] = min(x, y);
    if (t[i] == 2) m[i] = x+y;
}

void dfs2(int i, double k) {
    debug(i, k);
    if (t[i] == 0) {r[i] = k; return;}
    auto x = adj[i][0], y = adj[i][1];
    if (t[i] == 1) {
        if (m[x] < m[y]) dfs2(x, k);
        else dfs2(y, k);
    }
    if (t[i] == 2) {
        debug(m[x], m[y]);
        dfs2(x, k*(m[y]/m[x]+1));
        dfs2(y, k*(m[x]/m[y]+1));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        s.clear(), t.clear(), adj.clear();
        do {
            char c; cin >> c;
            if (c == '*') add();
            if (c == 'S') t[s.back()] = 1;
            if (c == 'P') t[s.back()] = 2;
            if (c == '(') add(), s.pb(adj.size()-1);
            if (c == ')') s.pop_back();
        } while (!s.empty());
        r.assign(adj.size(), 0);
        m.resize(adj.size());
        dfs1(0); dfs2(0, k);
        debug(m);
        cout << "REVOLTING";
        cout << setprecision(0) << fixed;
        for (int i = 0; i < r.size(); i++)
            if (t[i] == 0) cout << " " << r[i];
        cout << "\n";
    }
}