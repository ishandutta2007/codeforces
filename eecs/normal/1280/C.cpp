#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, k, sz[maxn];
vector<pair<int, int>> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &k);
        for (int i = 1; i <= 2 * k; i++) {
            G[i].clear();
        }
        for (int i = 1, u, v, w; i < 2 * k; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].emplace_back(v, w), G[v].emplace_back(u, w);
        }
        long long s1 = 0, s2 = 0;
        function<void(int, int, int)> dfs = [&](int v, int fa, int w) {
            sz[v] = 1;
            for (auto e : G[v]) if (e.first ^ fa) {
                dfs(e.first, v, e.second), sz[v] += sz[e.first];
            }
            if (sz[v] & 1) s1 += w;
            s2 += 1LL * w * min(sz[v], 2 * k - sz[v]);
        };
        dfs(1, 0, 0);
        printf("%lld %lld\n", s1, s2);
    }
    return 0;
}