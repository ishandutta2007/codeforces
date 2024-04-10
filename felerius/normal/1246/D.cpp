#include <bits/stdc++.h>

// Contest: Codeforces Round #596 (Div. 1, based on Technocup 2020 Elimination Round 2) (https://codeforces.com/contest/1246)
// Problem: D: Tree Factory (https://codeforces.com/contest/1246/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

vector<set<int>> adj;
vector<int> d;

void dfs(int v) {
    for (auto c : adj[v])
        d[c] = d[v] + 1, dfs(c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> p(n); adj.resize(n), d.resize(n);
    for (int i = 1; i < n; ++i)
        cin >> p[i], adj[p[i]].emplace(i);
    dfs(0);

    vector<int> op;
    int u = max_element(begin(d), end(d)) - begin(d);
    while (u != 0) {
        if (adj[p[u]].size() == 1) {
            u = p[u];
            continue;
        }
        auto w = *begin(adj[p[u]]) == u ? *next(begin(adj[p[u]])) : *begin(adj[p[u]]);
        adj[p[u]].erase(u);
        p[u] = w;
        adj[w].emplace(u);
        op.push_back(u);
    }

    int v = 0;
    while (true) {
        cout << v << ' ';
        if (adj[v].empty())
            break;
        v = *begin(adj[v]);
    }
    cout << '\n' << op.size() << '\n';
    reverse(begin(op), end(op));
    for (auto i : op)
        cout << i << ' ';
    cout << '\n';

    return 0;
}