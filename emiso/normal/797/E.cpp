#include <bits/stdc++.h>

using namespace std;

int KLIM = 200;
int dp[100100][210], arr[100100];

int n, q, p, k;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = n; i > 0; i--)
        for(int j = 1; j <= 200; j++)
            dp[i][j] = 1 + ((i + j + arr[i] <= n) ? dp[i+j+arr[i]][j] : 0);

    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &p, &k);
        if(k <= KLIM) printf("%d\n", dp[p][k]);
        else {
            int ans = 0;
            while(p <= n) {
                p += k + arr[p];
                ans++;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}