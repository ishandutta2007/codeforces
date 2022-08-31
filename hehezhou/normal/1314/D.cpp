#include <bits/stdc++.h>
using namespace std;
int mp[85][85], n, k;
int dis[85][15];
int tag[85];
int main() {
    srand(time(0));
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", mp[i] + j);
        }
    int ans = 1e9;
    for (int t = 1; t <= 3000; t++) {
        for (int i = 2; i <= n; i++) tag[i] = rand() % 2;
        memset(dis, 0x3f, sizeof dis);
        dis[1][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int u = 1; u <= n; u++)
                for (int v = 1; v <= n; v++) {
                    if (tag[u] ^ tag[v]) {
                        dis[v][i] = min(dis[v][i], dis[u][i - 1] + mp[u][v]);
                    }
                }
        }
        ans = min(ans, dis[1][k]);
    }
    return cout << ans << endl, 0;
}