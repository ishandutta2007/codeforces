#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 998244353;
int T, n, ans[maxn], f[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = ans[1] = 1; i <= n; i++) {
            G[i].clear();
            if (i < n) (ans[1] *= 2) %= P;
        }
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        for (int i = 2; i <= n; i++) {
            if ((n - 1) % i) { ans[i] = 0; continue; }
            function<bool(int, int)> dfs = [&](int v, int fa) {
                int cnt = 0;
                for (int u : G[v]) if (u ^ fa) {
                    if (!dfs(u, v)) return 0;
                    if (!f[u]) cnt++;
                }
                if (!(cnt % i)) return f[v] = 0, 1;
                if (!((cnt + 1) % i)) return f[v] = 1, 1;
                return 0;
            };
            if (dfs(1, 0) && !f[1]) ans[i] = 1;
            else ans[i] = 0;
        }
        for (int i = n; i; i--) {
            for (int j = i + i; j <= n; j += i) {
                ans[i] = (ans[i] - ans[j] + P) % P;
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}