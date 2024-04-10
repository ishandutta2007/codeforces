#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, x[maxn];
vector<int> path, G[maxn];
bool vis[maxn];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int V = 0, num = 0;
        vector<int> foo;
        function<void(int)> dfs = [&](int v) {
            vis[v] = 1, V++, num += x[v];
            foo.push_back(v), x[v] ^= 1;
            vector<int> H;
            for (int u : G[v]) if (!vis[u]) {
                dfs(u), H.push_back(u);
                foo.push_back(v), x[v] ^= 1;
            }
            for (int u : H) if (x[u]) {
                foo.push_back(u), foo.push_back(v);
                x[v] ^= 1, x[u] ^= 1;
            }
        };
        dfs(i);
        if (x[i]) {
            if (foo.back() == i) foo.pop_back(), x[i] ^= 1;
            else puts("-1"), exit(0);
        }
        if (!num) continue;
        if (x[i]) puts("-1"), exit(0);
        if (!path.empty()) puts("-1"), exit(0);
        path = foo;
    }
    printf("%d\n", path.size());
    for (int x : path) printf("%d ", x);
    return 0;
}