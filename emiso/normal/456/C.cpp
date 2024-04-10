#include <bits/stdc++.h>

using namespace std;

long long dp[100100],freq[100100];

int main() {
    int n,v;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&v);
        freq[v]++;
    }
    dp[0] = 0, dp[1] = freq[1];
    for(int i=2;i<100010;i++) {
        dp[i] = max(dp[i-1],dp[i-2] + freq[i]*i);
    }
    printf("%lld\n",dp[100001]);
    return 0;
}