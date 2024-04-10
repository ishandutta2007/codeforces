#include <bits/stdc++.h>
using namespace std;
struct edge {
    int v, nxt;
} e[400010];
int head[200010], tot;
int id[200010], dfn, ans[200010], a[200010];
int fa[200010];
inline int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
void dfs(int now, int f) {
    id[++dfn] = now;
    fa[now] = f;
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == f) continue;
        ans[e[i].v] = gcd(ans[now], a[e[i].v]);
        dfs(e[i].v, now);
    }
    if(now == 1) ans[now] = a[now];
}
int dp[200010];
inline void addedge(int u, int v) {
    e[++tot] = edge{v, head[u]};
    head[u] = tot;
}
int n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), addedge(u, v), addedge(v, u);
    dfs(1, 0);
    for(int i = 1; i <= a[1]; i++) {
        if(a[1] % i) continue;
        for(int j = 2; j <= n; j++) {
            int x = id[j];
            dp[x] = dp[fa[x]] + (bool)(a[x] % i);
            if(dp[x] <= 1) ans[x] = max(ans[x], i);
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
    return 0;
}