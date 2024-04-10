#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, m, ans, cnt, lnk[maxn], a[maxn][maxn], b[maxn][maxn];
bool vis[maxn];
vector<int> G[maxn];
char s[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j] == 'B';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] = a[i][j] ^ a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1];
            if (b[i][j]) ans++;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (b[i][j] && b[i][m] && b[n][j]) G[i].push_back(j);
        }
    }
    function<int(int)> match = [&](int u) {
        for (int v : G[u]) if (!vis[v]) {
            vis[v] = 1;
            if (!lnk[v] || match(lnk[v])) return lnk[v] = u, 1;
        }
        return 0;
    };
    for (int i = 1; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        if (match(i)) cnt++;
    }
    printf("%d\n", ans - b[n][m] - cnt + (cnt % 2 != b[n][m]));
    return 0;
}