#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, p[maxn], sz[maxn], num[maxn], ans[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]), G[p[i]].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        if (G[v].empty()) sz[v] = 1;
        for (int u : G[v]) dfs(u), sz[v] += sz[u];
        num[sz[v]]++;
    };
    dfs(1);
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 1, j = 0; i <= n; i++) {
        j += num[i];
        ans[j] = min(ans[j], i);
    }
    for (int i = n; i; i--) {
        ans[i] = min(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}