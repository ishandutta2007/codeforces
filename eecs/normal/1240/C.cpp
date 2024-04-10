#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int T, n, K;
long long f[maxn], g[maxn];
vector<array<int, 2>> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 1, u, v, w; i < n; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back({v, w}), G[v].push_back({u, w});
        }
        function<void(int, int)> dfs = [&](int u, int fa) {
            vector<long long> V;
            long long s = 0;
            for (auto &e : G[u]) if (e[0] ^ fa) {
                dfs(e[0], u), s += f[e[0]];
                if (g[e[0]] + e[1] > f[e[0]]) V.push_back(g[e[0]] + e[1] - f[e[0]]);
            }
            sort(V.begin(), V.end(), greater<>());
            f[u] = s + accumulate(V.begin(), V.begin() + min(K, (int)V.size()), 0LL);
            g[u] = s + accumulate(V.begin(), V.begin() + min(K - 1, (int)V.size()), 0LL);
        };
        dfs(1, 0);
        printf("%lld\n", f[1]);
    }
    return 0;
}