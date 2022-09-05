#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        function<void(int, int, int)> dfs = [&](int u, int fa, int x) {
            if (fa) G[u].erase(find(G[u].begin(), G[u].end(), fa));
            int y = u == 1 ? 1 : -x;
            a[u] = x - y * G[u].size();
            for (int v : G[u]) dfs(v, u, y);
        };
        dfs(1, 0, 0);
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        putchar('\n');
    }
    return 0;
}