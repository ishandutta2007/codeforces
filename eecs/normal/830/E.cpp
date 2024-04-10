#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, m, ans[maxn], pre[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    auto deg = [&]() { // deg > 3
        for (int i = 1; i <= n; i++) if (G[i].size() > 3) {
            ans[G[i][0]] = ans[G[i][1]] = ans[G[i][2]] = ans[G[i][3]] = 1;
            return ans[i] = 2, 1;
        }
        return 0;
    };
    auto cycle = [&]() {
        vector<bool> vis(n + 1);
        vector<int> fa(n + 1);
        bool flag = 0;
        function<void(int)> dfs = [&](int u) {
            if (flag) return;
            vis[u] = 1;
            for (int v : G[u]) if (v ^ fa[u]) {
                if (!vis[v]) {
                    fa[v] = u, dfs(v);
                    if (flag) break;
                } else {
                    for (int i = u; ; i = fa[i]) {
                        ans[i] = 1;
                        if (i == v) break;
                    }
                    flag = 1; break;
                }
            }
        };
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }
        return flag;
    };
    auto diameter = [&]() { // diameter > 3; 1 or 2 subtrees
        vector<bool> vis(n + 1);
        vector<int> dist(n + 1), pre(n + 1);
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            int s, t;
            queue<int> Q;
            Q.push(i), vis[i] = 1;
            while (!Q.empty()) {
                int u = Q.front(); Q.pop(), s = u;
                for (int v : G[u]) if (!vis[v]) {
                    Q.push(v), vis[v] = 1;
                }
            }
            Q.push(s), vis[s] = 2;
            while (!Q.empty()) {
                int u = Q.front(); Q.pop(), t = u;
                for (int v : G[u]) if (!dist[v]) {
                    Q.push(v), dist[v] = dist[pre[v] = u] + 1;
                }
            }
            vector<int> V, cand;
            for (int i = t; ; i = pre[i]) {
                V.push_back(i);
                if (i == s) break;
            }
            for (int i = 0; i < V.size(); i++) {
                if (G[V[i]].size() > 2) cand.push_back(i);
            }
            if (cand.empty()) continue;
            int i = cand[0];
            if (cand.size() > 1) {
                int j = cand[1];
                ans[V[i - 1]] = ans[V[j + 1]] = 1;
                for (int k = i; k <= j; k++) ans[V[k]] = 2;
                for (int k : G[V[i]]) {
                    if (k ^ V[i - 1] && k ^ V[i + 1]) { ans[k] = 1; break; }
                }
                for (int k : G[V[j]]) {
                    if (k ^ V[j - 1] && k ^ V[j + 1]) { ans[k] = 1; break; }
                }
                return 1;
            }
            int u;
            for (int j : G[V[i]]) {
                if (j ^ V[i - 1] && j ^ V[i + 1]) { u = j; break; }
            }
            if (i > 1 && i + 2 < V.size() && G[u].size() > 1) {
                ans[V[i]] = 3, ans[V[i - 1]] = ans[u] = ans[V[i + 1]] = 2;
                ans[V[i - 2]] = ans[V[i + 2]] = 1;
                ans[G[u][0] == V[i] ? G[u][1] : G[u][0]] = 1;
                return 1;
            }
            if (i > 2 && i + 3 < V.size()) {
                ans[V[i]] = 4, ans[V[i - 1]] = ans[V[i + 1]] = 3;
                ans[V[i - 2]] = ans[V[i + 2]] = ans[u] = 2;
                ans[V[i - 3]] = ans[V[i + 3]] = 1;
                return 1;
            }
            if (i > 4) {
                reverse(V.begin(), V.end());
                i = V.size() - i - 1;
            }
            if (i > 1 && i + 5 < V.size()) {
                ans[u] = 3;
                for (int j = i - 2; j <= i + 5; j++) {
                    ans[V[j]] = array<int, 8>{2, 4, 6, 5, 4, 3, 2, 1}[j - (i - 2)];
                }
                return 1;
            }
        }
        return 0;
    };
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        fill(ans + 1, ans + n + 1, 0);
        if (deg() || cycle() || diameter()) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                printf("%d%c", ans[i], " \n"[i == n]);
            }
        } else {
            puts("NO");
        }
    }
    return 0;
}