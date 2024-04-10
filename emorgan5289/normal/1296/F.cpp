#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

struct lca {

    vector<pair<int, int>> euler_walk;
    vector<vector<pair<int, int>>> range_mins;
    vector<int> walk_index;
    vector<bool> visited;

    void _label_walk(vector<vector<int>>& edges, int i, int depth) {
        visited[i] = 1;
        walk_index[i] = euler_walk.size();
        euler_walk.push_back({depth, i});
        for (int j : edges[i]) {
            if (visited[j]) continue;
            _label_walk(edges, j, depth+1);
            euler_walk.push_back({depth, i});
        }
    }

    // Accepts an adjecency list. Can include or exlude parents, it works either way.
    lca(vector<vector<int>>& edges, int root) {

        // set up the euler walk
        walk_index = vector<int>(edges.size(), 0);
        visited = vector<bool>(edges.size(), 0);
        _label_walk(edges, root, 0);

        // set up RMQ lookup table
        range_mins.push_back({});
        for (int i = 0; i < euler_walk.size(); i++)
            range_mins.back().push_back(euler_walk[i]);
        for (int len = 2; len <= euler_walk.size(); len <<= 1) {
            auto prev = range_mins.back();
            range_mins.push_back({});
            for (int i = 0; i < euler_walk.size()-len+1; i++)
                range_mins.back().push_back(min(prev[i], prev[i+len/2]));
        }
    }

    int query(int i, int j) {
        int a = min(walk_index[i], walk_index[j]);
        int b = max(walk_index[i], walk_index[j]);
        if (b == a) return i;
        int n = floor(log2(b-a));
        return min(range_mins[n][a], range_mins[n][b-pow(2, n)+1]).second;
    }
};

int depth[5005], parent[5005], val[5005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    vector<vector<int>> adj(n);
    vector<array<int, 2>> edges;
    for (int i = 0; i < n-1; i++) {
        int a, b; fin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
    }

    vector<int> stack = {0};
    while (!stack.empty()) {
        int i = stack.back();
        stack.pop_back();
        for (int j : adj[i]) {
            stack.push_back(j);
            depth[j] = depth[i]+1;
            parent[j] = i;
            adj[j].erase(find(adj[j].begin(), adj[j].end(), i));
        }
    }
    lca l(adj, 0);

    fill(val, val+5005, 1);

    int m; fin >> m;
    vector<array<int, 3>> paths(m);
    for (auto& p : paths) {
        fin >> p[1] >> p[2] >> p[0];
        p[1]--, p[2]--;
    }
    sort(all(paths));

    for (auto [x, a, b] : paths) {
        int c = l.query(a, b);
        while (a != c) {
            val[a] = x;
            a = parent[a];
        }
        while (b != c) {
            val[b] = x;
            b = parent[b];
        }
    }

    for (auto [x, a, b] : paths) {
        int c = l.query(a, b);
        int k = inf;
        while (a != c) {
            k = min(k, val[a]);
            a = parent[a];
        }
        while (b != c) {
            k = min(k, val[b]);
            b = parent[b];
        }
        if (k != x) {
            cout << "-1\n"; return 0;
        }
    }

    for (auto& p : edges) {
        int a = p[0], b = p[1];
        cout << val[a+b-l.query(a, b)] << " ";
    }
}