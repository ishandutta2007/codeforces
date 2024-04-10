#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
int dis[410][410];
vector < int > son[410];
inline void calc(int s, int *dis) {
    memset(dis, -1, sizeof(int[410]));
    queue < int > q;
    int que[410], tl;
    que[tl = 1] = s;
    dis[s] = 0;
    for (int i = 1; i <= tl; i++) {
        int cur = que[i];
        for (auto v : son[cur]) if (dis[v] == -1) dis[v] = dis[cur] + 1, que[++tl] = v;
    }
}
int qwq[410][410];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) calc(i, dis[i]);
    memset(qwq, -1, sizeof qwq);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (qwq[i][j] == -1) {
                int cur = dis[i][j], cnt = 0, ans = 1;
                for (int k = 1; k <= n; k++) {
                    if (dis[i][k] + dis[k][j] == cur) cnt++;
                    else {
                        int t = 0;
                        for (auto v : son[k]) if (dis[i][k] == dis[i][v] + 1 && dis[k][j] == dis[v][j] + 1) t++;
                        ans = 1ll * ans * t % mod;
                    }
                }
                if (cnt != cur + 1) ans = 0;
                qwq[j][i] = ans;
                printf("%d%c", ans, " \n"[j == n]);
            }
            else printf("%d%c", qwq[i][j], " \n"[j == n]);
        }
    }
}