#include <bits/stdc++.h>

#define MN 1101000

using namespace std;
typedef long long ll;

int r, n, maxi[MN], dp[MN], t[MN], x[MN], y[MN];

int main() {
    scanf("%d %d", &r, &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &t[i], &x[i], &y[i]);
    }

    for(int i = n-1; i >= 0; i--) {
        dp[i] = 1 + maxi[i+2*r+1];
        for(int j = i+1; j < min(n, i+2*r+1); j++) {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }

        maxi[i] = max(dp[i], maxi[i+1]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        if(abs(x[i] - 1) + abs(y[i] - 1) <= t[i])
           ans = max(ans, dp[i]);

    printf("%d\n", ans);
    return 0;
}