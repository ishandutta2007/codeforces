#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, m, a[maxn], b[maxn], vis[maxn], lst[maxn];
long long d[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", &b[i]);
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        auto bfs = [&](long long &x) {
            queue<int> Q;
            for (int i = 1; i <= n; i++) {
                if (vis[i]) Q.push(i), d[i] = x;
                else d[i] = -1;
            }
            fill(lst + 1, lst + n + 1, 0);
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                for (int u : G[v]) if (a[u] < d[v] && !(vis[v] && vis[u]) && lst[v] ^ u) {
                    if (!~d[u]) {
                        Q.push(u), d[u] = d[v] + b[u], lst[u] = v;
                    } else {
                        for (int i = u; !vis[i]; i = lst[i]) x += b[i], vis[i] = 1;
                        for (int i = v; !vis[i]; i = lst[i]) x += b[i], vis[i] = 1;
                        return 1;
                    }
                }
            }
            return 0;
        };
        auto chk = [&](long long x) {
            fill(vis + 1, vis + n + 1, 0), vis[1] = 1;
            while (bfs(x));
            return accumulate(vis + 1, vis + n + 1, 0) == n;
        };
        int l = 0, r = 1e9 + 1, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}