#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], b[maxn], col[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        G[a[i]].push_back(b[i]), 
        G[b[i]].push_back(a[i]);
    }
    for (int i = 1; i <= 2 * n; i += 2) {
        G[i].push_back(i + 1), G[i + 1].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        for (int u : G[v]) {
            if (!col[u]) col[u] = 3 - col[v], dfs(u);
            assert(col[u] == 3 - col[v]);
        }
    };
    for (int i = 1; i <= 2 * n; i++) {
        if (!col[i]) col[i] = 1, dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", col[a[i]], col[b[i]]);
    }
    return 0;
}