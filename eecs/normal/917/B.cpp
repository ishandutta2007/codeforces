#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, f[maxn][maxn][26][2];
vector<int> G[maxn], W[maxn];

bool dfs(int u, int v, int lst, int turn) {
    int &ans = f[u][v][lst][turn];
    if (~ans) return ans; ans = 0;
    if (!turn) {
        for (int i = 0; i < G[u].size(); i++) {
            if (W[u][i] >= lst) {
                ans |= !dfs(G[u][i], v, W[u][i], turn ^ 1);
            }
        }
        return ans;
    } else {
        for (int i = 0; i < G[v].size(); i++) {
            if (W[v][i] >= lst) {
                ans |= !dfs(u, G[v][i], W[v][i], turn ^ 1);
            }
        }
        return ans;
    }
}

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        char w; scanf("%d %d %c", &u, &v, &w);
        G[u].push_back(v), W[u].push_back(w - 'a');
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", dfs(i, j, 0, 0) ? 'A' : 'B');
        }
        printf("\n");
    }
    return 0;
}