#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, id, tot, fa[maxn], ch[maxn][2], sz[maxn];
bool vis[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n, tot = n;
    auto query = [&](int a, int b, int c) {
        cout << a << " " << b << " " << c << endl;
        char ch; cin >> ch;
        return ch == 'X' ? -1 : ch == 'Y' ? 1 : 0;
    };
    function<void(int)> init = [&](int u) {
        sz[u] = !ch[u][0];
        for (int v : ch[u]) {
            if (v && !vis[v]) init(v), sz[u] += sz[v];
        }
    };
    function<int(int, int)> find_rt = [&](int u, int all) {
        for (int v : ch[u]) {
            if (v && !vis[v] && sz[v] * 2 > all) return find_rt(v, all);
        }
        return u;
    };
    function<int(int)> leaf = [&](int u) {
        return !ch[u][0] ? u : leaf(ch[u][0]);
    };
    function<void(int)> dfs = [&](int u) {
        if (vis[u] || !ch[u][0]) {
            if (fa[u]) ch[fa[u]][ch[fa[u]][1] == u] = tot, fa[tot] = fa[u];
            ch[tot][0] = u, ch[tot][1] = id, fa[u] = fa[id] = tot;
            return;
        }
        init(u);
        int x = find_rt(u, sz[u] + 1), t = query(leaf(ch[x][0]), leaf(ch[x][1]), id);
        vis[x] = 1, !~t ? dfs(u) : dfs(ch[x][t]), vis[x] = 0;
    };
    for (int i = 2; i <= n; i++) {
        int rt = 1;
        while (fa[rt]) rt = fa[rt];
        tot++, id = i, dfs(rt);
    }
    cout << -1 << endl;
    for (int i = 1; i < 2 * n; i++) {
        cout << (fa[i] ? fa[i] : -1) << " ";
    }
    cout << endl;
    return 0;
}