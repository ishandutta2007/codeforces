#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, p[maxn], sz[maxn];
double ans[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        G[p[i]].push_back(i);
    }
    function<void(int)> dfs1 = [&](int v) {
        sz[v] = 1;
        for (int u : G[v]) dfs1(u), sz[v] += sz[u];
    };
    function<void(int)> dfs2 = [&](int v) {
        for (int u : G[v]) {
            ans[u] = ans[v] + 1 + (sz[v] - sz[u] - 1) / 2.0;
            dfs2(u);
        }
    };
    dfs1(1);
    ans[1] = 1, dfs2(1);
    for (int i = 1; i <= n; i++) {
        printf("%.1f ", ans[i]);
    }
    return 0;
}