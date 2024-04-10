#include <bits/stdc++.h>
using namespace std;
int n;
vector < int > son[300010];
int sg[300010], a[300010];
int _min[300010], dp[300010];
void dfs(int cur, int fa) {
    _min[cur] = cur;
    for (auto i : son[cur]) if (i != fa) {
        dfs(i, cur);
        _min[cur] = min(_min[cur], _min[i]);
        dp[cur] ^= dp[i] + 1;
        sg[_min[i]] ^= dp[i] + 1;
    }
    sg[_min[cur]] ^= dp[cur] ^ 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    sg[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) sg[i] ^= sg[i - 1];
    for (int i = 1; i <= n; i++) putchar(sg[i] == 0 ? '2' : '1');
    puts("");
}