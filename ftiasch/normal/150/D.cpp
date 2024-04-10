// Codeforces Round #107 
// Problem D -- Mission Impassable
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 160;
const int INF = 1000000000;

int n, points[N], memory[N][N][N], dp[N];
char string[N];

int dfs(int left, int right, int extra) {
    if (left <= right) {
        int &ret = memory[left][right][extra];
        if (ret == -1) {
            ret = -INF;
            if (extra > 0 && dfs(left, right, 0) != -INF && points[extra] != -INF) {
                ret = max(ret, dfs(left, right, 0) + points[extra]);
            }
            if (left == right) {
                ret = max(ret, dfs(left + 1, right - 1, extra + 1));
            }
            if (left < right && string[left] == string[right]) {
                ret = max(ret, dfs(left + 1, right - 1, extra + 2));
            }
            for (int i = left; i < right; ++ i) {
                if (dfs(left, i, 0) != -INF) {
                    ret = max(ret, dfs(left, i, 0) + dfs(i + 1, right, extra));
                }
            }
            for (int i = right; i > left; -- i) {
                if (dfs(i, right, 0) != -INF) {
                    ret = max(ret, dfs(left, i - 1, extra) + dfs(i, right, 0));
                }
            }
        }
        return ret;
    } else {
        return points[extra];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", points + i);
        if (points[i] == -1) {
            points[i] = -INF;
        }
    }
    scanf("%s", string + 1);
    memset(memory, -1, sizeof(memory));
    dp[0] = 0;
    for (int i = 1; i <= n; ++ i) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < i; ++ j) {
            dp[i] = max(dp[i], dp[j] + dfs(j + 1, i, 0));
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}