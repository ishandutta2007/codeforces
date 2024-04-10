#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

vector <int> g[N];

struct edge {
    int u, v, c;
    edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

int color[N];

bool fl = false;

void dfs(int u) {
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 0) dfs(v);
        else if (color[v] == 1) {
            fl = true;
        }
    }
    color[u] = 2;
}

vector <int> t;

void jhfs(int u) {
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 0) {
            jhfs(v);
        }
    }
    t.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <edge> ed;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        ed.emplace_back(u, v, c);
    }
    int l = -1, r = 1e9 + 7;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            color[i] = 0;
        }
        fl = false;
        for (auto e : ed) {
            if (e.c > mid) {
                g[e.u].push_back(e.v);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) dfs(i);
        }
        if (!fl) r = mid;
        else l = mid;
    }
    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        color[i] = 0;
    }
    for (auto e : ed) {
        if (e.c > r) {
            g[e.u].push_back(e.v);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) jhfs(i);
    }
    reverse(t.begin(), t.end());
    vector <int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[t[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (ed[i].c > r) continue;
        if (pos[ed[i].u] > pos[ed[i].v]) ans.push_back(i + 1);
    }
    cout << r << ' ' << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
}