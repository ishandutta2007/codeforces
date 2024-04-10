#include <bits/stdc++.h>
using namespace std;
char s[200010];
typedef long long ll;
int a, b, n;
ll dp[200010][2];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", s);
        dp[0][0] = b, dp[0][1] = 1e15;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                dp[i + 1][0] = min(dp[i][0] + a, dp[i][1] + a + a) + b;
                dp[i + 1][1] = min(dp[i][1] + a, dp[i][0] + a + a) + b + b;
            }
            else {
                dp[i + 1][0] = 1e15;
                dp[i + 1][1] = dp[i][1] + b + b + a;
            }
        }
        printf("%I64d\n", dp[n][0]);
    }
}