#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int dp[2010];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int cnt = 0, lst = 0;
        for (int i = 0; i <= n; i++) dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i <= n + n; i++) {
            int now;
            scanf("%d", &now);
            if (now > lst) {
                lst = now;
                for (int i = n; i >= cnt; i--) dp[i] |= dp[i - cnt];
                cnt = 0;
            }
            cnt++;
        }
        for (int i = n; i >= cnt; i--) dp[i] |= dp[i - cnt];
        puts(dp[n] ? "YES" : "NO");
    }
}