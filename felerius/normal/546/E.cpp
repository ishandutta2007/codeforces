#include <bits/stdc++.h>

// Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
// Problem: (41) Soldier and Traveling (Difficulty: 6) (http://codeforces.com/problemset/problem/546/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

struct Edge {
    int from, to, f, c;
    Edge* rev;
};

int INF = 1e9;
vector<vector<Edge*>> adj;
int s, t;

Edge* add_edge(int a, int b, int c) {
    auto e1 = new Edge{a, b, 0, c, nullptr};
    auto e2 = new Edge{b, a, 0, 0, nullptr};
    e1->rev = e2;
    e2->rev = e1;
    adj[a].push_back(e1);
    adj[b].push_back(e2);
    return e1;
}

int dinic_dfs(int v, int pushed, vector<int>& ptr, vector<int>& level) {
    if (pushed == 0 || v == t)
        return pushed;
    for (; ptr[v] < adj[v].size(); ++ptr[v]) {
        auto e = adj[v][ptr[v]];
        if (level[v] + 1 != level[e->to] || e->c - e->f <= 0)
            continue;
        auto p = dinic_dfs(e->to, min(pushed, e->c - e->f), ptr, level);
        if (!p)
            continue;
        e->f += p;
        e->rev->f -= p;
        return p;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n2, m; cin >> n2 >> m;
    int n = 2 * n2 + 2;
    adj.resize(n);
    s = 2 * n2;
    t = 2 * n2 + 1;

    vector<vector<Edge*>> mat(n2, vector<Edge*>(n2));
    int asum = 0, bsum = 0;
    for (int i = 0; i < n2; ++i) {
        int ai; cin >> ai;
        asum += ai;
        add_edge(s, 2 * i, ai);
        mat[i][i] = add_edge(2 * i, 2 * i + 1, INF);
    }
    for (int i = 0; i < n2; ++i) {
        int bi; cin >> bi;
        bsum += bi;
        add_edge(2 * i + 1, t, bi);
    }

    if (asum != bsum) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        mat[a][b] = add_edge(2 * a, 2 * b + 1, INF);
        mat[b][a] = add_edge(2 * b, 2 * a + 1, INF);
    }

    int flow = 0;
    vector<int> level(n);
    vector<int> ptr(n);
    while (true) {
        level.assign(n, -1);
        level[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (auto e : adj[v]) {
                if (e->c - e->f <= 0 || level[e->to] != -1)
                    continue;
                level[e->to] = level[e->from] + 1;
                q.push(e->to);
            }
        }
        if (level[t] == -1)
            break;

        ptr.assign(n, 0);
        while (auto p = dinic_dfs(s, INF, ptr, level))
            flow += p;
    }

    if (bsum == flow) {
        cout << "YES\n";
        for (int i = 0; i < n2; ++i) {
            for (int j = 0; j < n2; ++j)
                cout << (mat[i][j] ? mat[i][j]->f : 0) << ' ';
            cout << '\n';
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}