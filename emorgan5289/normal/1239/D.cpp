#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

void visit(int i, vector<vector<int>>& adj, vector<int>& order, vector<bool>& visited) {
    visited[i] = 1;
    for (int j : adj[i])
        if (!visited[j])
            visit(j, adj, order, visited);
    order.push_back(i);
}

void partition(int i, int c, vector<int>& component, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[i] = 1;
    component[i] = c;
    for (int j : adj[i])
        if (!visited[j])
            partition(j, c, component, adj, visited);
}

vector<int> kosaraju(vector<vector<int>>& adj) {

    int size = adj.size();
    vector<int> order, out(size);
    vector<vector<int>> rev_adj(size);
    vector<bool> visited(size, 0);

    for (int i = 0; i < size; i++)
        if (!visited[i])
            visit(i, adj, order, visited);

    for (int i = 0; i < size; i++)
        visited[i] = 0;
    for (int i = 0; i < size; i++)
        for (int j : adj[i])
            rev_adj[j].push_back(i);

    int c = -1;
    for (int i = size-1; i >= 0; i--)
        if (!visited[order[i]])
            partition(order[i], ++c, out, rev_adj, visited);

    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n, m; fin >> n >> m;
        vector<vector<int>> adj(n);
        if (n == 1) {
            cout << "No\n"; continue;
        }
        for (int i = 0; i < m; i++) {
            int u, v; fin >> u >> v;
            if (u != v) adj[u-1].pb(v-1);
        }
        vector<int> com = kosaraju(adj);
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 0) {
                s = i; goto next;
            }
            for (int j : adj[i])
                if (com[i] != com[j]) {
                    s = j; goto next;
                }
        }
        for (int i = 0; i < n; i++)
            if (com[i] != 0) goto next;
        cout << "No\n"; continue;
        next:;
        vector<int> stack = {s};
        vector<bool> vis(n, 0);
        vis[s] = 1;
        int c = 1;
        while (!stack.empty()) {
            int i = stack.back(); stack.pop_back();
            for (int j : adj[i]) {
                if (vis[j]) continue;
                stack.pb(j);
                vis[j] = 1; c++;
            }
        }
        cout << "Yes\n" << c << " " << n-c << "\n";
        for (int i = 0; i < n; i++)
            if (vis[i]) cout << i+1 << " ";
        cout << "\n"; 
        for (int i = 0; i < n; i++)
            if (!vis[i]) cout << i+1 << " ";
        cout << "\n"; 
    }
}