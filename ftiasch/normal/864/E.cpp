#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100;
const int M = 2000;

int t[N], d[N], p[N], order[N], dp[N + 1][M + 1];

bool cmp(int i, int j) {
    return d[i]  < d[j];
    // if (t[i] + d[i] == t[j] + d[j]) {
    //     return d[i] < d[j];
    // }
    // return t[i] + d[i] < t[j] + d[j];
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("C.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d", t + i, d + i, p + i);
        order[i] = i;
    }
    std::sort(order, order + n, cmp);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j <= M; ++ j) {
            dp[i + 1][j] = dp[i][j];
            if (t[order[i]] <= j && j < d[order[i]]) {
                dp[i + 1][j] = std::max(dp[i][j], dp[i][j - t[order[i]]] + p[order[i]]);
            }
        }
    }
    int j = std::max_element(dp[n], dp[n] + (M + 1)) - dp[n];
    printf("%d\n", dp[n][j]);
    std::vector<int> result;
    for (int i = n - 1; i >= 0; -- i) {
        if (t[order[i]] <= j && j < d[order[i]] && dp[i][j - t[order[i]]] + p[order[i]] == dp[i + 1][j]) {
            result.push_back(order[i] + 1);
            j -= t[order[i]];
        }
    }
    printf("%d\n", (int)result.size());
    for (int i = (int)result.size() - 1; i >= 0; -- i) {
        printf("%d%c", result[i], " \n"[i == 0]);
    }
}