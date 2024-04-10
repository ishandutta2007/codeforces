#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, g[maxn][maxn];
vector<pair<int, int>> ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    if (n < m) {
        for (int i = 1; i <= n; i++) {
            int t = *min_element(g[i] + 1, g[i] + m + 1);
            for (int j = 1; j <= t; j++) {
                ans.emplace_back(0, i);
            }
            for (int j = 1; j <= m; j++) {
                g[i][j] -= t;
            }
        }
        for (int i = 1; i <= m; i++) {
            int t = g[1][i];
            for (int j = 1; j <= n; j++) {
                if (g[j][i] < 0 || t ^ g[j][i]) puts("-1"), exit(0);
            }
            for (int j = 1; j <= t; j++) {
                ans.emplace_back(1, i);
            }
        }
    } else {
        for (int i = 1; i <= m; i++) {
            int t = INT_MAX;
            for (int j = 1; j <= n; j++) {
                t = min(t, g[j][i]);
            }
            for (int j = 1; j <= t; j++) {
                ans.emplace_back(1, i);
            }
            for (int j = 1; j <= n; j++) {
                g[j][i] -= t;
            }
        }
        for (int i = 1; i <= n; i++) {
            int t = g[i][1];
            for (int j = 1; j <= m; j++) {
                if (g[i][j] < 0 || t ^ g[i][j]) puts("-1"), exit(0);
            }
            for (int j = 1; j <= t; j++) {
                ans.emplace_back(0, i);
            }
        }
    }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        if (!p.first) printf("row %d\n", p.second);
        else printf("col %d\n", p.second);
    }
    return 0;
}