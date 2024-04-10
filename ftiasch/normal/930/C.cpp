#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

const int N = 100000;

int n, m, cov[N + 1], pre[N], suf[N];

void solve(int* a, int* dp)
{
    std::vector<int> can(m + 1, INT_MAX);
    can[0] = 0;
    for (int i = 0; i < m; ++ i) {
        dp[i] = std::upper_bound(can.begin(), can.end(), a[i]) - can.begin();
        can[dp[i]] = std::min(can[dp[i]], a[i]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        cov[a - 1] ++;
        cov[b] --;
    }
    for (int i = 1; i < m; ++ i) {
        cov[i] += cov[i - 1];
    }
    solve(cov, pre);
    std::reverse(cov, cov + m);
    solve(cov, suf);
    int result = 0;
    for (int i = 0; i < m; ++ i) {
        result = std::max(result, pre[i] + suf[m - 1 - i] - 1);
    }
    printf("%d\n", result);
}