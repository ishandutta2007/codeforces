#pragma GCC optimize("O3")

#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

struct DSU {
    vector<int> dsu;
    mt19937 rnd;

    explicit DSU(int n) {
        rnd = mt19937(time(nullptr));
        dsu.resize(n);
        iota(dsu.begin(), dsu.end(), 0);
    }

    int Comp(int v) {
        if (dsu[v] == v) {
            return v;
        }
        return dsu[v] = Comp(dsu[v]);
    }

    void Merge(int u, int v) {
        u = Comp(u), v = Comp(v);
        if (rnd() & 1) {
            swap(u, v);
        }
        dsu[u] = v;
    }
};

int timer = 0;
vector<bool> used;
vector<int> tin;
vector<int> up;
vector<int> type;

void DFS(int v, vector<vector<pair<int, int>>>& g, int p = -1) {
    used[v] = true;
    tin[v] = up[v] = timer++;
    for (auto& now : g[v]) {
        int u = now.first, id = now.second;
        if (u == p) {
            continue;
        }
        if (used[u]) {
            up[v] = min(up[v], tin[u]);
        } else {
            DFS(u, g, v);
            up[v] = min(up[v], up[u]);
            if (up[u] > tin[v]) {
                type[id] = 2;
            }
        }
    }
}

struct Edge {
    int u, v, id;

    explicit Edge(int a, int b, int c) {
        u = a;
        v = b;
        id = c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    map<int, vector<Edge>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[w].emplace_back(u, v, i);
    }
    DSU dsu(n);
    type.assign(m, 1);
    for (auto& now : edges) {
        auto& list = now.second;
        map<int, int> arr;
        int size = 0;
        for (auto& e : list) {
            int u = dsu.Comp(e.u), v = dsu.Comp(e.v), id = e.id;
            e.u = u, e.v = v;
            if (e.u > e.v) {
                swap(e.u, e.v);
            }
            if (u == v) {
                type[id] = 0;
            } else {
                arr[u] = 0;
                arr[v] = 0;
            }
        }
        for (auto& tmp : arr) {
            tmp.second = size++;
        }
        vector<vector<pair<int, int>>> g(size);
        for (auto& e : list) {
            int u = e.u, v = e.v, id = e.id;
            if (u != v) {
                u = arr[u], v = arr[v];
                g[u].emplace_back(v, id);
                g[v].emplace_back(u, id);
            }
        }
        used.assign(size, false);
        tin.assign(size, 0);
        up.assign(size, 0);
        timer = 0;
        for (int v = 0; v < size; ++v) {
            if (!used[v]) {
                DFS(v, g);
            }
        }
        map<pair<int, int>, int> cnt;
        for (auto& e : list) {
            int u = e.u, v = e.v;
            ++cnt[{u, v}];
        }
        for (auto& e : list) {
            int u = e.u, v = e.v;
            if (type[e.id] == 2 && cnt[{u, v}] >= 2) {
                type[e.id] = 1;
            }
            dsu.Merge(e.u, e.v);
        }
    }
    for (int x : type) {
        if (x == 0) {
            cout << "none\n";
        } else if (x == 1) {
            cout << "at least one\n";
        } else {
            cout << "any\n";
        }
    }
    return 0;
}