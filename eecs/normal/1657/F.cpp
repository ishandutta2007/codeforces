#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, q, x[maxn], y[maxn], fa[maxn], dep[maxn];
int tot, tp, tim, cnt, st[maxn * 6], dfn[maxn * 6], low[maxn * 6], bel[maxn * 6];
char ans[maxn];
vector<int> G[maxn], path[maxn], H[maxn * 6];
vector<array<int, 2>> id[maxn][26];
string str[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> init = [&](int u) {
        dep[u] = dep[fa[u]] + 1;
        for (int v : G[u]) if (v ^ fa[u]) {
            fa[v] = u, init(v);
        }
    };
    init(1);
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i] >> str[i];
        vector<int> _path;
        int u = x[i], v = y[i];
        while (u ^ v) {
            if (dep[u] > dep[v]) path[i].push_back(u), u = fa[u];
            else _path.push_back(v), v = fa[v];
        }
        path[i].push_back(u);
        copy(_path.rbegin(), _path.rend(), back_inserter(path[i]));
        for (int j = 0; j < path[i].size(); j++) {
            id[path[i][j]][str[i][j] - 'a'].push_back({i, 0});
            id[path[i][j]][str[i][str[i].size() - j - 1] - 'a'].push_back({i, 1});
        }
    }
    tot = 2 * q;
    auto add = [&](int u, int v) {
        if (u && v) H[u].push_back(v);
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 0, lst = 0; j < 26; j++) if (!id[i][j].empty()) {
            int _lst = ++tot;
            for (auto &p : id[i][j]) {
                add(p[0] + p[1] * q, lst), add(_lst, p[0] + !p[1] * q);
            }
            add(_lst, lst), lst = _lst;
        }
        for (int j = 25, lst = 0; ~j; j--) if (!id[i][j].empty()) {
            int _lst = ++tot;
            for (auto &p : id[i][j]) {
                add(p[0] + p[1] * q, lst), add(_lst, p[0] + !p[1] * q);
            }
            add(_lst, lst), lst = _lst;
        }
    }
    function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++tim, st[++tp] = u;
        for (int v : H[u]) {
            if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
            else if (!bel[v]) low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            cnt++;
            while (1) {
                int x = st[tp--];
                bel[x] = cnt;
                if (x == u) break;
            }
        }
    };
    for (int i = 1; i <= tot; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= q; i++) {
        if (bel[i] == bel[i + q]) cout << "NO\n", exit(0);
    }
    cout << "YES\n";
    fill(ans + 1, ans + n + 1, 'a');
    for (int i = 1; i <= q; i++) {
        if (bel[i] > bel[i + q]) reverse(str[i].begin(), str[i].end());
        for (int j = 0; j < path[i].size(); j++) ans[path[i][j]] = str[i][j];
    }
    for (int i = 1; i <= n; i++) {
        cout.put(ans[i]);
    }
    return 0;
}