#include <bits/stdc++.h>
#define MOD 100000000

using namespace std;
typedef long long ll;

int n1, n2, k1, k2;

ll dp[110][110][11][11];
ll solve(int q1, int q2, int s1, int s2) {
    if(q1 + q2 == 0) return 1;

    ll &x = dp[q1][q2][s1][s2];
    if(x != -1) return x;
    x = 0;

    if(q1 && s1 < k1) x += solve(q1 - 1, q2, s1 + 1, 0);
    if(q2 && s2 < k2) x += solve(q1, q2 - 1, 0, s2 + 1);
    return (x %= MOD);
}

int main() {
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(n1, n2, 0, 0));
    return 0;
}