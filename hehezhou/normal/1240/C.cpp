#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n, k;
vector < pair < int, int > > son[500010];
ll dp[500010][2];
void dfs(int cur, int fa) {
    vector < ll > tmp;
    dp[cur][1] = 0;
    for (const auto &i : son[cur]) {
        if (i.first == fa) continue;
        dfs(i.first, cur);
        dp[cur][1] += dp[i.first][0];
        tmp.push_back(max(0ll, dp[i.first][1] - dp[i.first][0] + i.second));
    }
    sort(tmp.begin(), tmp.end(), greater < ll > ());
    for (int i = 0; i < tmp.size() && i < k - 1; i++) dp[cur][1] += tmp[i];
    dp[cur][0] = dp[cur][1];
    if (tmp.size() >= k) dp[cur][0] += tmp[k - 1];
}
inline void rmain() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) son[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        son[u].push_back({v, w});
        son[v].push_back({u, w});
    }
    dfs(1, 0);
    printf("%lld\n", dp[1][0]);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}