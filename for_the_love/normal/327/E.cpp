#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 24;
const long long MOD = 1e9 + 7;
long long a[30], sum[1 << N], s[3], dp[1 << N], t[1 << N];
int n, m;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    scanf("%d", &m);
    s[1] = s[2] = -1;
    for (int i = 1; i <= m; i++) scanf("%I64d", &s[i]);
    for (int i = 1; i <= n; i++) t[1 << (i - 1)] = i;
    for (int i = 0; i < 1 << n; i++) sum[i] = sum[i - (i & -i)] + a[t[i & -i]];
    dp[0] = 1;
    for (int i = 0; i < 1 << n; i++){
        if (sum[i] == s[1] || sum[i] == s[2]) continue;
        for (int j = i; j; j -= j & -j) dp[i] += dp[i - (j & -j)];
        dp[i] %= MOD;
    }
    printf("%I64d\n", dp[(1 << n) - 1]);
}