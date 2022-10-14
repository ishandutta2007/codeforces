#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

const int N = 2000;

int n, a[N][N], dfn[N], low[N], result;
std::vector <int> stack;

void dfs(int u, int &count) {
    if (dfn[u] == -1) {
        stack.push_back(u);
        int tmp = dfn[u] = low[u] = count ++;
        for (int v = 0; v < n; ++ v) {
            if (u != v && a[u][v]) {
                dfs(v, count);
                tmp = std::min(tmp, low[v]);
            }
        }
        low[u] = tmp;
        if (dfn[u] == low[u]) {
            while (true) {
                int v = stack.back();
                stack.pop_back();
                low[v] = INT_MAX;
                if (u == v) {
                    break;
                }
            }
            result ++;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(dfn, -1, sizeof(dfn));
    int count = 0;
    for (int i = 0; i < n; ++ i) {
        dfs(i, count);
    }
    puts(result > 1 ? "NO" : "YES");
    return 0;
}