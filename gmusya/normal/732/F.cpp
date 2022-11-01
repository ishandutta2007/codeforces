#pragma GCC optimize("O3")

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int timer = 0;
vector<bool> used;

vi tin;
vi up;
vi is_bridge;
vector<pair<int, int>> e;
vector<pair<int, int>> answer;
vvi g;

void DFS1(int v, int p = -1) {
    used[v] = true;
    tin[v] = up[v] = timer++;
    for (int i : g[v]) {
        int u = (e[i].first ^ e[i].second ^ v);
        if (u == p) {
            continue;
        }
        if (used[u]) {
            up[v] = min(up[v], tin[u]);
        } else {
            DFS1(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] > tin[v]) {
                is_bridge[i] = true;
            }
        }
    }
}

vi h;
vvi comps;
vector<pair<int, int>> ans;

void DFS2(int v, int p = -1) {
    comps.back().push_back(v);
    used[v] = true;
    for (int i : g[v]) {
        int u = (e[i].first ^ e[i].second ^ v);
        if (u == p || is_bridge[i]) {
            continue;
        }
        if (!used[u]) {
            h[u] = h[v] + 1;
            answer[i] = {u, v};
            DFS2(u, v);
        }
        if (h[u] < h[v]) {
            answer[i] = {u, v};
        }
    }
}

void DFS3(int v, int p = -1) {
    used[v] = true;
    for (int i : g[v]) {
        int u = (e[i].first ^ e[i].second ^ v);
        if (u == p || used[u]) {
            continue;
        }
        if (is_bridge[i]) {
            answer[i] = {u, v};
        }
        DFS3(u, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    answer.resize(m);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e.emplace_back(u, v);
        g[u].push_back(i);
        g[v].push_back(i);
    }
    is_bridge.resize(m);
    tin.resize(n);
    up.resize(n);
    used.assign(n, false);
    for (int v = 0; v < n; ++v) {
        if (!used[v]) {
            DFS1(v);
        }
    }
    used.assign(n, false);
    h.resize(n);
    for (int v = 0; v < n; ++v) {
        if (!used[v]) {
            comps.emplace_back();
            DFS2(v);
        }
    }
    sort(comps.begin(), comps.end(), [&](const vi& i, const vi& j) {
        return i.size() > j.size();
    });
    used.assign(n, false);
    DFS3(comps[0][0]);
    cout << comps[0].size() << '\n';
    for (auto& now : answer) {
        cout << now.first + 1 << ' ' << now.second + 1 << '\n';
    }
    return 0;
}