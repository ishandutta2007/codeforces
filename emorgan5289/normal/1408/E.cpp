#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// Accepts an adjecency matrix. Returns the sum of the weights of the MST.
// Use inf to show that two vertices are NOT connected. Runs in O(V^2).
template<typename T>
T mst(vector<vector<T>>& adj) {
    
    const static T inf_T = numeric_limits<T>::max();
    vector<bool> visited(adj.size(), 0);
    vector<T> cost(adj.size(), inf_T);

    cost[0] = 0;
    T out = 0;

    // Prim's algorithm
    for (int k = 0; k < adj.size(); k++) {

        T leastcost = inf_T, next = -1;
        for (int i = 0; i < adj.size(); i++)
            if (!visited[i] && cost[i] < leastcost) {
                leastcost = cost[i];
                next = i;
            }

        visited[next] = 1;
        out += leastcost;

        for (int i = 0; i < adj.size(); i++)
            cost[i] = min(cost[i], adj[next][i]);
    }
    return out;
}

// This is used for Kruskal's algorithm below.
struct unionfind {

    int length;
    vector<int> parent;

    unionfind(int s) {
        length = s;
        parent.assign(s, 0);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int rep(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = rep(a);
        b = rep(b);
        if (a == b)
            return;
        parent[b] = a;
    }

    // returns true if a and b are in the same set.
    inline bool query(int a, int b) {
        return rep(a) == rep(b);
    }
};

// Accepts an EDGE LIST in the form {weight, start, end}. Returns the sum
// of the weights of the MST. The vertices should be labeled from 0..N.
// Runs in O(ElogE).
template<typename T>
T mst(vector<tuple<T, int, int>>& adj) {

    // Kruskal's algorithm
    sort(adj.begin(), adj.end());
    int size = 0;
    for (int i = 0; i < adj.size(); i++)
        size = max(size, max(get<1>(adj[i]), get<2>(adj[i]))+1);

    unionfind UF(size);
    T out = 0;

    for (auto edge : adj) {
        int a = get<1>(edge), b = get<2>(edge);
        if (!UF.query(a, b)) {
            out += get<0>(edge);
            UF.unite(a, b);
        }
    }
    return out;
}

// Accepts an ADJACENCY LIST in the form {weight, end}. Requires the function above.
template<typename T>
T mst(vector<vector<pair<T, int>>>& adj) {
    vector<tuple<T, int, int>> edges;
    for (int i = 0; i < adj.size(); i++)
        for (auto e : adj[i])
            edges.push_back({e.first, i, e.second});
    return mst(edges);
}

const ll N = 2e5+5;
ll a[N], b[N];
vector<tuple<ll, int, int>> e;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int s; cin >> s;
        while (s--) {
            int x; cin >> x; x--;
            ans += a[i]+b[x];
            e.pb({-a[i]-b[x], i, m+x});
        }
    }
    cout << ans+mst(e) << "\n";
}