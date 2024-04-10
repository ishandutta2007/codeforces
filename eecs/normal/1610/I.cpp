#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, sg[maxn], fa[maxn];
bool vis[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) if (v ^ fa[u]) {
            fa[v] = u, dfs(v);
            sg[u] ^= sg[v] + 1;
        }
    };
    dfs(1), putchar(sg[1] ? '1' : '2');
    int cur = sg[1];
    for (int i = 2; i <= n; i++) {
        for (int j = i; j > 1 && !vis[j]; j = fa[j]) {
            cur ^= sg[j] ^ (sg[j] + 1) ^ 1, vis[j] = 1;
        }
        putchar(cur ? '1' : '2');
    }
    return 0;
}