#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;
vector <int> g[MAXN];
int per[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        cin >> per[i];
        --per[i];
    }
}

const int INF = 1e9 + 7;
int dist[MAXN];
void bfs() {
    for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[0] = 0;
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

vector <int> ch[MAXN];
void dfs(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        ch[u].push_back(v);
        dfs(v, u);
    }
}

int l[MAXN], r[MAXN];
int pos[MAXN];
void solve() {
    bfs();
    for (int i = 0; i < n - 1; ++i) {
        if (dist[per[i + 1]] < dist[per[i]]) {
            cout << "No\n";
            exit(0);
        }
    }
    for (int i = 0; i < n; ++i) {
        pos[per[i]] = i;
    }
    dfs(0, 0);
    for (int u = 0; u < n; ++u) {
        if (ch[u].empty()) continue;
        l[u] = INF;
        r[u] = -INF;
        for (int v : ch[u]) {
            l[u] = min(l[u], pos[v]);
            r[u] = max(r[u], pos[v]);
        }
        if (r[u] - l[u] + 1 != (int)ch[u].size()) {
            cout << "No\n";
            exit(0);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (dist[per[i]] == dist[per[i + 1]] && !ch[per[i]].empty() && !ch[per[i + 1]].empty()) {
            if (l[per[i + 1]] < l[per[i]]) {
                cout << "No\n";
                exit(0);
            }
        }
    }
    cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();

    return 0;
}