#include <bits/stdc++.h>

using namespace std;

int n, s, k, dp[51][2002], r[51];
char c[51];

int solve(int pos, int cnd) {
    if(cnd >= k) return 0;

    int &x = dp[pos][cnd];
    if(x != -1) return x;

    x = 1e7;
    for(int i = 0; i < n; i++)
        if(r[i] > r[pos] && c[i] != c[pos])
            x = min(x, solve(i, cnd + r[i]) + abs(pos - i));

    return x;
}

int main() {
    scanf("%d %d %d", &n, &s, &k);
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    scanf("%s", c);

    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
        ans = min(ans, solve(i, r[i]) + abs(s - 1 - i));

    printf("%d\n", ans < 1e6 ? ans : -1);
    return 0;
}