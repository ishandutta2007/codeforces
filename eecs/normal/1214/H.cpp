#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, fa[maxn], dep[maxn], mx[maxn], sec[maxn], ans[maxn], chk[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs1 = [&](int v, int fa) {
        for (int u : G[v]) if (u ^ fa) {
            dep[u] = dep[v] + 1, dfs1(u, v);
        }
    };
    function<void(int)> dfs2 = [&](int v) {
        dep[v] = dep[fa[v]] + 1;
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs2(u);
            if (mx[u] + 1 > mx[v]) sec[v] = mx[v], mx[v] = mx[u] + 1;
            else sec[v] = max(sec[v], mx[u] + 1);
        }
    };
    function<void(int, int, int)> dfs3 = [&](int v, int c, int inc) {
        c = ans[v] = (c + inc + K - 1) % K + 1;
        for (int u : G[v]) {
            if (u ^ fa[v] && !chk[u]) dfs3(u, c, inc);
        }
    };
    dfs1(1, 0);
    int rt = max_element(dep + 1, dep + n + 1) - dep;
    dfs2(rt);
    for (int i = 1; i <= n; i++) if (sec[i] && K > 2) {
        if (mx[i] + dep[i] >= K && sec[i] + dep[i] >= K && mx[i] + sec[i] >= K
            - 1) puts("No"), exit(0);
    }
    int ed = max_element(dep + 1, dep + n + 1) - dep;
    vector<int> V;
    for (int v = ed; v; v = fa[v]) {
        V.push_back(v), chk[v] = 1;
        ans[v] = (dep[v] - 1) % K + 1;
    }
    for (int v : V) for (int u : G[v]) if (!chk[u]) {
        dfs3(u, ans[v], dep[v] <= dep[ed] / 2 ? -1 : 1);
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}