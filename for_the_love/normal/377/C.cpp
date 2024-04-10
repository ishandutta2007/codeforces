/* &*#()&*#)&E*F& */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
const int INF = 1e9 + 7;

int dp[1 << 20], m, a[111], b[111], t[111];
char op[111];

int Dfs(int x, int p){
    if (dp[x] != -1) return dp[x];
    if (t[p] == 1){
        dp[x] = -INF;
        for (int i = 0; i < m; i++)
        if (x >> i & 1){
            if (op[p] == 'p') dp[x] = max(dp[x], a[i] + Dfs(x ^ (1 << i), p + 1));
            else dp[x] = max(dp[x], Dfs(x ^ (1 << i), p + 1));
        }
    }else{
        dp[x] = INF;
        for (int i = 0; i < m; i++)
        if (x >> i & 1){
            if (op[p] == 'p') dp[x] = min(dp[x], Dfs(x ^ (1 << i), p + 1) - a[i]);
            else dp[x] = min(dp[x], Dfs(x ^ (1 << i), p + 1));
        }
    }
    return dp[x];
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    scanf("%d", &m);
    int n1 = 0;
    for (int i = n - 1; i >= n - m; i--) b[n1++] = a[i];
    for (int i = 0; i < m; i++) a[i] = b[i];

    for (int i = 0; i < m; i++) scanf(" %c %d", &op[i], &t[i]);
    int tot = (1 << m) - 1;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    Dfs(tot, 0);
    printf("%d\n", dp[tot]);
}