#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, P = 998244353;
int n, ans, col[2 * maxn];
bool vis[2 * maxn];
char s[maxn], t[maxn];
vector<array<int, 2>> G[2 * maxn];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 2; i <= n; i++) {
        memset(col, -1, sizeof(col));
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= 2 * n; j++) {
            G[j].clear();
            if (j < i) col[j] = 0;
        }
        for (int j = i, k = n; j < k; j++, k--) {
            G[j].push_back({k, 0});
            G[k].push_back({j, 0});
        }
        col[i] = col[n + 1] = 1;
        for (int j = 1, k = n; j < k; j++, k--) {
            G[j + n].push_back({k + n, 0});
            G[k + n].push_back({j + n, 0});
        }
        for (int j = 1; j <= n; j++) {
            if (s[j] == '0') G[j].push_back({j + n, 0}), G[j + n].push_back({j, 0});
            if (s[j] == '1') G[j].push_back({j + n, 1}), G[j + n].push_back({j, 1});
        }
        int pw = 1;
        for (int j = 1; j <= 2 * n; j++) if (!vis[j] && ~col[j]) {
            function<void(int)> dfs = [&](int u) {
                vis[u] = 1;
                for (auto &e : G[u]) {
                    if (!~col[e[0]]) col[e[0]] = col[u] ^ e[1];
                    if (col[e[0]] ^ col[u] ^ e[1]) pw = 0;
                    if (!vis[e[0]]) dfs(e[0]);
                }
            };
            dfs(j);
        }
        for (int j = 1; j <= 2 * n; j++) if (!vis[j]) {
            function<void(int)> dfs = [&](int u) {
                vis[u] = 1;
                for (auto &e : G[u]) {
                    if (!~col[e[0]]) col[e[0]] = col[u] ^ e[1];
                    if (col[e[0]] ^ col[u] ^ e[1]) pw = 0;
                    if (!vis[e[0]]) dfs(e[0]);
                }
            };
            dfs(j), pw = 2 * pw % P;
        }
        (ans += pw) %= P;
    }
    printf("%d\n", ans);
    return 0;
}