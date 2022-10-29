#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n;
char s[N];
int dp[N][2][2][2];

void checkMax(int &a, int b){
    if (a < b) a = b;
}

int main(){
    scanf("%d", &n);
    scanf("%s", s);
    dp[0][1][0][0] = dp[0][0][0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
        for (int x = 0; x < 2; x++)
            dp[i + 1][j][k][x] = dp[i][j][k][x];
        if (s[i] == '0'){
            checkMax(dp[i + 1][1][1][1], dp[i][0][0][0] + 1);
            checkMax(dp[i + 1][1][1][1], dp[i][0][1][1] + 1);

            checkMax(dp[i + 1][0][1][0], dp[i][1][1][0] + 1);
            checkMax(dp[i + 1][0][1][0], dp[i][1][1][1] + 1);
            checkMax(dp[i + 1][0][0][0], dp[i][1][0][0] + 1);
        }else{
            checkMax(dp[i + 1][0][1][1], dp[i][1][0][0] + 1);
            checkMax(dp[i + 1][0][1][1], dp[i][1][1][1] + 1);

            checkMax(dp[i + 1][1][1][0], dp[i][0][1][0] + 1);
            checkMax(dp[i + 1][1][1][0], dp[i][0][1][1] + 1);
            checkMax(dp[i + 1][1][0][0], dp[i][0][0][0] + 1);
        }
    }
    int ans = max(dp[n][0][1][0], dp[n][0][1][1]);
    checkMax(ans, dp[n][0][0][0]);
    checkMax(ans, dp[n][1][1][1]);
    checkMax(ans, dp[n][1][1][0]);
    checkMax(ans, dp[n][1][0][0]);
    printf("%d\n", ans);
}