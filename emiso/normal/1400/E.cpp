#include <bits/stdc++.h>

using namespace std;

int dp[5050][5050], n, a[5050];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = n-1; i >= 0; i--) {
        for(int j = n; j >= 0; j--) {
            if(j > a[i]) dp[i][j] = 1234567;
            else dp[i][j] = min((j < a[i]) + dp[i+1][min(a[i+1],j)], 1 + dp[i][j+1]);
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}