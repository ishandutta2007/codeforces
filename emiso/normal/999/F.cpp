#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

int ans, n, k, c[5050], f[505], ff[100100], fcard[100100], joy[100100];
int dp[505][100000];

int solve(int n, int p) {
    if(p == 0 || n == 0) return 0;
    int &x = dp[p][n];
    if(x != -1) return x;
    x = solve(n, p - 1);
    for(int i = 1; i <= min(n, k); i++)
        x = max(x, solve(n-i, p - 1) + joy[i]);
    return x;
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i < k*n; i++) {
        scanf("%d", &c[i]);
        fcard[c[i]]++;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &f[i]);
        ff[f[i]]++;
    }
    for(int i = 1; i <= k; i++) {
        scanf("%d", &joy[i]);
    }

    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= 100000; i++) {
        ans += solve(fcard[i], ff[i]);
    }

    printf("%d\n", ans);
    return 0;
}