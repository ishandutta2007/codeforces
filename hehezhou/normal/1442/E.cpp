#include <bits/stdc++.h>
using namespace std;
int col[200010];
vector < int > son[200010];
int dp[200010][2], k;
void dfs(int cur, int fa) {
    dp[cur][0] = dp[cur][1] = 0;
    for (auto v : son[cur]) {
        if (v == fa) continue;
        dfs(v, cur);
        int qwq = min(dp[v][0], dp[v][1] + 1);
        if (qwq + dp[cur][0] <= k) dp[cur][0] = max(dp[cur][0], qwq);
        else dp[cur][0] = k + 10;
        qwq = min(dp[v][1], dp[v][0] + 1);
        if (qwq + dp[cur][1] <= k) dp[cur][1] = max(dp[cur][1], qwq);
        else dp[cur][1] = k + 10;
    }
    if (col[cur] == 1) dp[cur][0] = k + 10;
    else if (col[cur] == 2) dp[cur][1] = k + 10;
}
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) son[i].clear(), scanf("%d", col + i);
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            son[u].push_back(v);
            son[v].push_back(u);
        }
        int L = 0, R = n, ans = n;
        while (L <= R) {
            k = L + R >> 1;
            dfs(1, 0);
            if (dp[1][0] <= k || dp[1][1] <= k) ans = k, R = k - 1;
            else L = k + 1;
        }
        printf("%d\n", (ans + 3) / 2);
    }
}