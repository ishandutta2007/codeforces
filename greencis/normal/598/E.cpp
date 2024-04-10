#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[35][35][55];

int f(int n, int m, int k) {
    if (k == 0) return 0;
    if (n * m == k) return 0;
    if (n * m < k) return 1e9;
    if (!dp[n][m][k]) {
        int ans = 1e9;
        for (int cnt = 0; cnt <= k; ++cnt) {
            for (int len = 1; len < n; ++len) {
                int f1 = f(len, m, cnt);
                int f2 = f(n - len, m, k - cnt);
                ans = min(ans, m * m + f1 + f2);
            }
            for (int len = 1; len < m; ++len) {
                int f1 = f(n, len, cnt);
                int f2 = f(n, m - len, k - cnt);
                ans = min(ans, n * n + f1 + f2);
            }
        }
        dp[n][m][k] = ans + 1;
    }
    return dp[n][m][k] - 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",f(n,m,k));
    }

    return 0;
}