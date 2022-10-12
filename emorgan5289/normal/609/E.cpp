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
#else
#include "../../debug.cpp"
#endif

struct unionfind {

    int length;
    vector<int> parent;

    unionfind() {}

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

    int length;
    unionfind UF;
    rmq<T> RMQ;
    vector<int> index;

    // Accepts an adjacency list with pairs in the form {weight, destination}.
    // Must be a tree. There can only be one edge between two vertices.
    // O(VlogV) to set up, O(1) to query.
    pathmin(vector<vector<pair<T, int>>>& adj) {

        length = adj.size();
        UF = unionfind(length);
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
        for (auto edge : edges) {
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

        index = vector<int>(length);
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
    int query(int a, int b) {
        a = index[a]; b = index[b];
        if (a > b) swap(a, b);
        return RMQ.query(a, b-1);
    }
};

template<typename T>
vector<tuple<T, int, int>> mst(vector<tuple<T, int, int>>& adj) {

    // Kruskal's algorithm
    sort(adj.begin(), adj.end());
    int size = 0;
    for (int i = 0; i < adj.size(); i++)
        size = max(size, max(get<1>(adj[i]), get<2>(adj[i]))+1);

    unionfind UF(size);
    vector<tuple<T, int, int>> out;

    for (auto edge : adj) {
        int a = get<1>(edge), b = get<2>(edge);
        if (!UF.query(a, b)) {
            out.pb(edge);
            UF.unite(a, b);
        }
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<tuple<ll, int, int>> e(m), t(m), ec(m);
    vector<vector<pair<ll, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[i] = {w, u-1, v-1};
    }
    ec = e;
    t = mst(ec);
    ll ans = 0;
    for (auto& [w, u, v] : t) {
        adj[u].pb({-w, v});
        adj[v].pb({-w, u});
        ans += w;
    }
    pathmin p(adj);
    for (auto& [w, u, v] : e)
        cout << ans+w+p.query(u, v) << "\n";
}