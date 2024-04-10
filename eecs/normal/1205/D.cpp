#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, rt, sz[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs1 = [&](int v, int fa) {
        sz[v] = 1;
        int mx = 0;
        for (int u : G[v]) if (u ^ fa) {
            dfs1(u, v), sz[v] += sz[u];
            mx = max(mx, sz[u]);
        }
        if (!rt && max(mx, n - sz[v]) <= n / 2) rt = v;
    };
    dfs1(1, 0), dfs1(rt, 0);
    sort(G[rt].begin(), G[rt].end(), [&](int x, int y) { return sz[x] > sz[y]; });
    int m = 0, s = 0;
    while (s < n / 3) s += sz[G[rt][m++]];
    vector<int> V1 = {0}, V2 = {0};
    for (int i = 1; i <= s; i++) {
        V1.push_back(i);
    }
    for (int i = 1; i <= n - 1 - s; i++) {
        V2.push_back((s + 1) * i);
    }
    int p1 = 0, p2 = 0;
    function<void(int, int, int)> dfs2 = [&](int v, int fa, int lst) {
        int o = ++p1;
        printf("%d %d %d\n", fa, v, V1[o] - V1[lst]);
        for (int u : G[v]) if (u ^ fa) dfs2(u, v, o);
    };
    function<void(int, int, int)> dfs3 = [&](int v, int fa, int lst) {
        int o = ++p2;
        printf("%d %d %d\n", fa, v, V2[o] - V2[lst]);
        for (int u : G[v]) if (u ^ fa) dfs3(u, v, o);
    };
    for (int i = 0; i < G[rt].size(); i++) {
        if (i < m) dfs2(G[rt][i], rt, 0);
        else dfs3(G[rt][i], rt, 0);
    }
    return 0;
}