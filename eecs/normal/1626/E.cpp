#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, tot, c[maxn], sum[maxn], ans[maxn], son[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        sum[u] = c[u];
        for (int v : G[u]) if (v ^ fa) {
            dfs1(v, u), sum[u] += sum[v];
            son[u] += c[v];
        }
        if ((c[u] || son[u]) && sum[u] > 1) tot++;
    };
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        if (tot) ans[u] = 1;
        for (int v : G[u]) if (v ^ fa) {
            int o = tot;
            if ((c[u] || son[u]) && sum[u] > 1) tot--;
            if ((c[v] || son[v]) && sum[v] > 1) tot--;
            sum[u] -= sum[v], sum[v] += sum[u];
            son[u] -= c[v], son[v] += c[u];
            if ((c[u] || son[u]) && sum[u] > 1) tot++;
            if ((c[v] || son[v]) && sum[v] > 1) tot++;
            dfs2(v, u);
            son[u] += c[v], son[v] -= c[u];
            sum[v] -= sum[u], sum[u] += sum[v], tot = o;
        }
    };
    dfs1(1, 0), dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) ans[i] = 1;
        for (int j : G[i]) {
            if (c[j] == 1) ans[i] = 1;
        }
        printf("%d ", ans[i]);
    }
    return 0;
}