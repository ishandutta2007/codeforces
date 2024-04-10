#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
    int u, v, nxt;
} e[200010];
int head[200010], tot;
inline void addedge(int u, int v) {
    e[++tot] = edge{u, v, head[u]};
    head[u] = tot;
}
int dp[200010], vis[200010];
inline void dfs(int now) {
    vis[now] = 1;
    dp[now] = now;
    for (int i = head[now]; i; i = e[i].nxt) {
        if (vis[e[i].v]) {
            puts("-1");
            exit(0);
        }
        if (!dp[e[i].v]) dfs(e[i].v);
        dp[now] = min(dp[now], dp[e[i].v]);
    }
    vis[now] = 0;
}
char s[200010];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    for (int i = 1; i <= n; i++) s[i] = 'A';
    for (int i = 1; i <= n; i++) if (dp[i] == 0) dfs(i);
    for (int i = 1; i <= n; i++) if (dp[i] < i) s[i] = 'E';
    tot = 0;
    memset(head, 0, sizeof head);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= m; i++) addedge(e[i].v, e[i].u);
    for (int i = 1; i <= n; i++) if (dp[i] == 0) dfs(i);
    for (int i = 1; i <= n; i++) if (dp[i] < i) s[i] = 'E';
    int ans = 0;
    for (int i = 1; i <= n; i++) if (s[i] == 'A') ans++;
    printf("%d\n%s\n", ans, s + 1);
}