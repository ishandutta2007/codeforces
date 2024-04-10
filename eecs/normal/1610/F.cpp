#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, m, tot = 1, odd, d[maxn], head[maxn], ans[maxn];
bool vis[maxn], mark[maxn];
struct edge { int to, nxt; } e[maxn];

void add(int u, int v) {
    e[++tot] = (edge){v, head[u]}, head[u] = tot, d[u] ^= 1;
    e[++tot] = (edge){u, head[v]}, head[v] = tot, d[v] ^= 1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        if (w ^ 1) u += n, v += n;
        add(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (d[i]) odd++;
        if (d[i] && d[i + n]) add(i, i + n);
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (d[i]) add(0, i);
    }
    function<void(int)> dfs = [&](int u) {
        mark[u] = 1;
        for (int &i = head[u]; i; i = e[i].nxt) if (!vis[i / 2]) {
            if (i / 2 <= m) ans[i / 2] = i % 2;
            vis[i / 2] = 1, dfs(e[i].to);
        }
    };
    for (int i = 0; i <= 2 * n; i++) {
        if (!mark[i]) dfs(i);
    }
    printf("%d\n", odd);
    for (int i = 1; i <= m; i++) {
        putchar(ans[i] + '1');
    }
    return 0;
}