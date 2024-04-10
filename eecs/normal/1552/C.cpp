#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
int T, n, K, x[maxn], y[maxn], vis[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= K; i++) {
            scanf("%d %d", &x[i], &y[i]);
            if (x[i] > y[i]) swap(x[i], y[i]);
            vis[x[i]] = vis[y[i]] = 1;
        }
        vector<int> V;
        for (int i = 1; i <= 2 * n; i++) {
            if (!vis[i]) V.push_back(i);
        }
        int ans = 0, tmp = n - K;
        for (int i = 0; i < tmp; i++) {
            x[++K] = V[i];
            y[K] = V[i + tmp];
        }
        for (int i = 1; i <= n; i++) {
            int u = x[i], v = y[i];
            for (int j = i + 1; j <= n; j++) {
                if (u > y[j] || v < x[j]) continue;
                if (u > x[j] && v < y[j]) continue;
                if (u < x[j] && v > y[j]) continue;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}