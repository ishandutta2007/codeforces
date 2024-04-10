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

const int N = 1e6+5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            adj[i].resize(k);
            for (int j = 0; j < k; j++)
                cin >> adj[i][j], adj[i][j]--;
        }
        auto ord = toposort(adj);
        if (ord.size() < n) {
            cout << "-1\n";
        } else {
            vector<int> dp(n, 0);
            reverse(all(ord));
            for (int i : ord) {
                for (int j : adj[i]) {
                    if (j > i) cmax(dp[i], dp[j]+1);
                    else cmax(dp[i], dp[j]);
                }
            }
            cout << 1+*max_element(all(dp)) << "\n";
        }
    }
}