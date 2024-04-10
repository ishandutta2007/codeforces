#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct unionfind {

    vector<int> p, sz;

    unionfind() {}

    unionfind(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    inline int rep(int x) {
        while (x != p[x])
            x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a == b) return;
        p[b] = a;
        sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

template<typename T>
struct rmq {

    vector<vector<T>> tree;

    rmq() {}

    rmq(vector<T>& data) {

        int n = data.size();
        int log2n = ceil(log2(n));
        tree.assign(log2n+1, vector<T>(n));
        tree[0] = data;

        for (int i = 1; i <= log2n; i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                tree[i][j] = min(tree[i-1][j], tree[i-1][j+(1<<i-1)]);
    }

    T query(int a, int b) {
        int n = floor(log2(b-a+1));
        return min(tree[n][a], tree[n][b-(1<<n)+1]);
    }
};

template<typename T>
struct pathmin {

    rmq<T> RMQ;
    vector<int> index;

    // Accepts an adjacency list with pairs in the form {weight, destination}.
    // Must be a tree. There can only be one edge between two vertices.
    // O(VlogV) to set up, O(1) to query.
    pathmin(vector<vector<pair<T, int>>>& adj) {

        int length = adj.size();
        unionfind UF(length);
        vector<int> pre(length), post(length), succ(length, -1);
        vector<T> weight(length);

        for (int i = 0; i < length; i++)
            pre[i] = post[i] = i;

        vector<tuple<T, int, int>> edges;
        edges.reserve(length-1);
        for (int i = 0; i < length; i++)
            for (auto p : adj[i])
                edges.push_back({p.first, i, p.second});

        sort(edges.begin(), edges.end(), greater<tuple<T, int, int>>());
        for (auto& edge : edges) {
            T w;
            int a, b;
            tie(w, a, b) = edge;
            if (UF.query(a, b))
                continue;

            int Arep = UF.rep(a), Brep = UF.rep(b);

            weight[post[Arep]] = w;
            succ[post[Arep]] = pre[Brep];
            UF.unite(Arep, Brep);

            int rep = UF.rep(Arep);
            pre[rep] = pre[Arep];
            post[rep] = post[Brep];
        }

        index.assign(length, 0);
        vector<T> values(length);
        int cur = pre[UF.rep(0)], i = 0;
        while (cur != -1) {
            index[cur] = i;
            values[i] = weight[cur];
            cur = succ[cur];
            i++;
        }

        RMQ = rmq(values);
    }

    // minimum edge along the path from a to b.
    T query(int a, int b) {
        a = index[a]; b = index[b];
        if (a > b) swap(a, b);
        return RMQ.query(a, b-1);
    }
};

const int N = 3e5+5;
vector<pair<ll, int>> adj[N];
int n, m, k, q;
pair<ll, int> c[N];
using T = tuple<ll, int, int>;
priority_queue<T, vector<T>, greater<T>> heap;

void dijkstra() {
    vector<bool> vis(n, 0);
    int time = 0;
    while (!heap.empty()) {
        auto [x, r, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        c[i] = {x, r};
        for (auto& [w, j] : adj[i])
            if (!vis[j])
                heap.push({x+w, r, j});
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> q;
    while (m--) {
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb({w, v}), adj[v].pb({w, u});
    }
    for (int i = 0; i < k; i++)
        heap.push({0, i, i});
    dijkstra();
    
    vector<tuple<ll, int, int>> e;
    for (int i = 0; i < n; i++)
        for (auto& [w, j] : adj[i])
            if (c[i].second != c[j].second)
                e.pb({c[i].first+c[j].first+w, c[i].second, c[j].second});
    sort(all(e));

    unionfind uf(k);
    vector<vector<pair<ll, int>>> sp(k);
    for (auto& [w, i, j] : e)
        if (!uf.query(i, j)) {
            uf.unite(i, j);
            sp[i].pb({-w, j}), sp[j].pb({-w, i});
        }

    pathmin p(sp);
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        cout << -p.query(u, v) << "\n";
    }
}