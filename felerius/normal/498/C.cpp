#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, f, c;
    Edge* rev = nullptr;
};

int s, t;
vector<vector<Edge*>> adj;
int INF = 1e9;

void add_edge(int a, int b, int c) {
    auto e1 = new Edge{a, b, 0, c};
    auto e2 = new Edge{b, a, 0, 0};
    e1->rev = e2;
    e2->rev = e1;
    adj[a].emplace_back(e1);
    adj[b].emplace_back(e2);
}

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> res;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i)
            continue;
        res.emplace_back(i, 0);
        while (n % i == 0) {
            res.back().second++;
            n /= i;
        }
    }
    if (n > 1)
        res.emplace_back(n, 1);
    return res;
}

int dinic_dfs(int v, int aug, vector<int>& dist, vector<int>& idx) {
    if (v == t) return aug;
    for (int& i = idx[v]; i < adj[v].size(); ++i) {
        auto e = adj[v][i];
        if (e->f == e->c || dist[e->to] != dist[v] + 1)
            continue;
        int pushed = dinic_dfs(e->to, min(aug, e->c - e->f), dist, idx);
        if (pushed == 0) continue;
        e->f += pushed;
        e->rev->f -= pushed;
        return pushed;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> f(n);
    vector<vector<int>> nodes(n);
    int ai;
    int n2 = 2;
    s = 0, t = 1;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        f[i] = factorize(ai);
        nodes[i].resize(f[i].size());
        iota(begin(nodes[i]), end(nodes[i]), n2);
        n2 += f[i].size();
    }

    adj.resize(n2);
    for (int i = 0; i < n; i += 2)
        for (int j = 0; j < f[i].size(); ++j)
            add_edge(s, nodes[i][j], f[i][j].second);
    for (int i = 1; i < n; i += 2)
        for (int j = 0; j < f[i].size(); ++j)
            add_edge(nodes[i][j], t, f[i][j].second);

    while (m--) {
        int a, b; cin >> a >> b; --a, --b;
        if (a % 2) swap(a, b);
        auto it1 = begin(f[a]);
        auto it2 = begin(f[b]);
        while (it1 != end(f[a]) && it2 != end(f[b])) {
            if (it1->first == it2->first) {
                auto node_a = nodes[a][it1 - begin(f[a])];
                auto node_b = nodes[b][it2 - begin(f[b])];
                add_edge(node_a, node_b, min(it1->second, it2->second));
                ++it1; ++it2;
            } else if (it1->first < it2->first)
                ++it1;
            else
                ++it2;
        }
    }

    int flow = 0;
    vector<int> dist(n2), idx(n2);
    while (true) {
        dist.assign(n2, INF); dist[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (auto e : adj[v]) {
                if (dist[e->to] == INF && e->f < e->c) {
                    dist[e->to] = dist[v] + 1;
                    q.push(e->to);
                }
            }
        }
        if (dist[t] == INF) break;
        idx.assign(n2, 0);
        int aug;
        while ((aug = dinic_dfs(s, INF, dist, idx)) != 0)
            flow += aug;
    }

//    int flow = 0;
//    while (true) {
//        vector<Edge*> inc(n2);
//        queue<int> q; q.push(s);
//        while (!q.empty()) {
//            auto v = q.front(); q.pop();
//            for (auto e : adj[v]) {
//                if (e->f < e->c && !inc[e->to]) {
//                    inc[e->to] = e;
//                    q.push(e->to);
//                }
//            }
//        }
//
//        if (!inc[t])
//            break;
//
//        int aug = INF;
//        for (auto v = t; v != s; v = inc[v]->from)
//            aug = min(aug, inc[v]->c - inc[v]->f);
//        flow += aug;
//        for (auto v = t; v != s; v = inc[v]->from) {
//            inc[v]->f += aug;
//            inc[v]->rev->f -= aug;
//        }
//    }

    cout << flow << '\n';
    return 0;
}