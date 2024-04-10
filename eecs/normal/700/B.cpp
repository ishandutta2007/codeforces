#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, cnt[maxn];
long long ans;
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, v; i <= 2 * K; i++) {
        scanf("%d", &v), cnt[v]++;
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), cnt[v] += cnt[u];
        }
        ans += min(cnt[v], 2 * K - cnt[v]);
    };
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}