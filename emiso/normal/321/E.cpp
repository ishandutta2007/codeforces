#include <bits/stdc++.h>
#define MN 4040
#define MK 808

using namespace std;

int n, K, a[MN][MN], c[MN][MN], dp[MK][MN], optK[MK][MN];

/* Tradicional Way ( TLE )
    for(int i=1;i<=K;i++)
        for(int j=1; j<=n; j++)
            for(int k=0; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i-1][k] + c[k+1][j]);
*/

void calc(int d, int l, int r) {
    if(l > r) return;

    int m = (l + r) / 2;
    int L = optK[d][l-1];
    int R = optK[d][r+1];

    for(int k=L; k<=min(R, m); k++) {
        if(dp[d][m] > dp[d-1][k] + c[k+1][m]) {
            dp[d][m] = dp[d-1][k] + c[k+1][m];
            optK[d][m] = k;
        }
    }

    calc(d, l, m-1);
    calc(d, m+1, r);
}

int main() {
    scanf("%d %d ", &n, &K);
    char st[10000];
    for(int i=1; i<=n; i++) {
        gets(st);
        for(int j=1; j<=n; j++) {
            a[i][j] = st[2 * j - 2] - '0';
        }
    }

    for(int d=1; d<n; d++) {
        for(int i=1; i+d<=n; i++) {
            int j = i+d;
            c[i][j] = c[i+1][j] + c[i][j-1] - c[i+1][j-1] + a[i][j];
        }
    }

    for(int d=0; d<MK; d++)
        for(int i=0; i<MN; i++)
            dp[d][i] = 999999999;
    dp[0][0] = 0;

    for(int d=1; d<=K; d++) {
        optK[d][0] = 0;
        optK[d][n+1] = n;
        calc(d, 1, n);
    }

    printf("%d\n", dp[K][n]);

    return 0;
}