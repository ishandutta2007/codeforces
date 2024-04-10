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

multiset<array<int, 3>> s;
vector<vector<array<int, 2>>> adj;
vector<int> col;

void dfs(int i) {
    for (auto& [j, c] : adj[i]) {
        col[j] = col[i]^c;
        dfs(j);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        s.insert({2*x-1, 2*y, i});
    }
    while (s.size() > 1) {
        debug(s);
        auto p = *s.begin(); s.erase(s.begin());
        auto q = *s.begin(); s.erase(s.begin());
        if (p[1] == q[1]) {
            adj[p[2]].pb({q[2], 1});
            continue;
        }
        if (p[1] < q[0]) {
            s.insert(q);
            continue;
        }
        s.insert({min(p[1], q[1])+1, max(p[1], q[1]), (int)adj.size()});
        adj.pb({{p[2], p[1] < q[1]}, {q[2], q[1] < p[1]}});
        debug(adj.back());
    }
    col.assign(adj.size(), -1);
    for (int i = adj.size()-1; i >= 0; i--)
        if (col[i] == -1)
            col[i] = 0, dfs(i);
    for (int i = 0; i < n; i++)
        cout << col[i] << " \n"[i == n-1];
}