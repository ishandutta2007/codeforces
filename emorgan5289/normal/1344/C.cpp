#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int k = 0;
char res[300000];

// Accepts an adjacency list. Assumes that the graph is connected and acyclic.
// Runs in O(V+E).
vector<int> topologicalsort(vector<vector<int>>& adj) {

    int size = adj.size(), back = adj.size()-1;
    vector<int> out, stack, indegree(size, 0);
    vector<bool> visited(size, 0);

    for (int i = 0; i < size; i++)
        for (int j : adj[i])
            indegree[j]++;

    // Kahn's algorithm
    for (int i = 0; i < size; i++)
        if (indegree[i] == 0)
            stack.push_back(i);

    while (!stack.empty()) {
        int i = stack.back();
        stack.pop_back();
        out.push_back(i);
        for (int j : adj[i]) {
            indegree[j]--;
            if (indegree[j] == 0)
                stack.push_back(j);
        }
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); radj[v].pb(u);
    }
    vector<int> top = topologicalsort(adj);
    if (top.size() != n) {
        cout << "-1\n"; return 0;
    }

    vector<int> r1(n, inf), r2(n, inf);
    for (auto& i : top) {
        r1[i] = i;
        for (auto& j : radj[i])
            r1[i] = min(r1[i], r1[j]);
    }
    reverse(all(top));
    for (auto& i : top) {
        r2[i] = i;
        for (auto& j : adj[i])
            r2[i] = min(r2[i], r2[j]);
    }

    k = 0;
    for (int i = 0; i < n; i++) {
        if (min(r1[i], r2[i]) >= i) {
            k++; res[i] = 'A';
        } else {
            res[i] = 'E';
        }
    }

    for (int i = 0; i < n; i++)
        debug(i, r1[i], r2[i]);

    cout << k << "\n";
    for (int i = 0; i < n; i++)
        cout << res[i];
    cout << "\n";
}