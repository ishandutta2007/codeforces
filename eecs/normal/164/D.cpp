#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, K, x[maxn], y[maxn], d[maxn];
bool vis[maxn];
vector<array<int, 3>> V;
vector<int> ans, G[maxn];
int sqr(int x) { return x * x; }

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            V.push_back({sqr(x[i] - x[j]) + sqr(y[i] - y[j]), i, j});
        }
    }
    sort(V.begin(), V.end(), greater<>());
    auto chk = [&](int lim) {
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 0; i <= lim; i++) {
            int u = V[i][1], v = V[i][2];
            G[u].push_back(v), G[v].push_back(u);
            d[u]++, d[v]++;
        }
        bool flag = 0;
        auto take = [&](int u) {
            vis[u] = 1;
            for (int v : G[u]) if (!vis[v]) d[u]--, d[v]--;
        };
        auto undo = [&](int u) {
            vis[u] = 0;
            for (int v : G[u]) if (!vis[v]) d[u]++, d[v]++;
        };
        function<void(int)> dfs = [&](int rem) {
            if (flag) return;
            if (!rem) {
                if (!flag && !accumulate(d + 1, d + n + 1, 0)) {
                    ans.clear(), flag = 1;
                    for (int i = 1; i <= n; i++) if (vis[i]) ans.push_back(i);
                }
                return;
            }
            for (int i = 1; i <= n; i++) if (d[i] > rem) {
                take(i), dfs(rem - 1), undo(i); return;
            }
            for (int i = 1; i <= n; i++) if (d[i] == 1) {
                for (int j : G[i]) if (!vis[j]) {
                    take(j), dfs(rem - 1), undo(j); return;
                }
            }
            int u = -1;
            for (int i = 1; i <= n; i++) {
                if (!vis[i] && (!~u || d[i] > d[u])) u = i;
            }
            take(u), dfs(rem - 1), undo(u);
            if (rem < d[u]) return;
            vector<int> H;
            for (int v : G[u]) if (!vis[v]) take(v), rem--, H.push_back(v);
            dfs(rem);
            while (!H.empty()) undo(H.back()), H.pop_back();
        };
        dfs(K);
        return flag;
    };
    int l = 0, r = min(K * n, (int)V.size() - 1);
    while (l <= r) {
        int mid = (l + r) / 2;
        chk(mid) ? l = mid + 1 : r = mid - 1;
    }
    for (int i = 0; i < K; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}