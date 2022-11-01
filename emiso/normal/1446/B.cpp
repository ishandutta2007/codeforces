
#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int m, n, ans, dp[5005][5005];
char s[MN]; string a, b;

int solve(int i, int j) {
    if(i == n || j == m) return 0;
    int &x = dp[i][j];
    if(x != -1) return x;
    x = 0;
    if(a[i] == b[j]) x = 2 + solve(i+1, j+1);
    x = max(x, -1 + solve(i, j+1));
    x = max(x, -1 + solve(i+1, j));
    return x;
}

int main() {
    scanf("%d %d %s", &n, &m, &s);
    a = s;
    scanf("%s", &s);
    b = s;

    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            ans = max(ans, solve(i, j));
    }

    printf("%d\n", ans);
    return 0;
}