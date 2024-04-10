#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

const int N = 100;

int n, m, memo[26][N][N];
std::vector<std::pair<int, int>> graph[N];

int solve(int last, int u, int v)
{
    int& win = memo[last][u][v];
    if (~win) {
        return win;
    }
    win = false;
    for (auto it : graph[u]) {
        if (last <= it.second && !solve(it.second, v, it.first)) {
            win = true;
            break;
        }
    }
    return win;
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("B.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        int a, b;
        char buf[2];
        scanf("%d%d%s", &a, &b, buf);
        a --;
        b --;
        graph[a].emplace_back(b, *buf - 'a');
    }
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            putchar("BA"[solve(0, i, j)]);
        }
        puts("");
    }
}