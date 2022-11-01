#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, k, d, dp[110][2];
int solve(int sum, int has) {
    if(sum < 0) return 0;
    if(sum == 0) return has;
    int &x = dp[sum][has];
    if(x != -1) return x;
    x  = 0;
    for(int i = 1; i <= k; i++) {
        x += solve(sum - i, has | (i >= d));
        if(x >= MOD) x -= MOD;
    }
    return x;
}

int main() {
    scanf("%d %d %d", &n, &k, &d);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(n, 0));
    return 0;
}