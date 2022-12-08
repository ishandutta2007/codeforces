#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;
const int MAXK = MAXN << 1;

const int MOD = 998244353;

int dp[MAXN][MAXK][4];

int N, K;

int sum(const int &a, const int &b) {
    return (a + b)%MOD;
}
void inc(int& a, int& b) {
    a = sum(a, b);
}

int d[4][4] = 
    {
        {0, 1, 1, 1},
        {0, 0, 2, 0},
        {0, 2, 0, 0},
        {1, 1, 1, 0}
    };

int main() {
    scanf("%d%d", &N, &K);
    
    for(int i = 0;i <= N;i++) for(int j = 0;j <= K;j++) for(int k = 0;k < 4;k++) dp[i][j][k] = 0;
    
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    dp[1][1][3] = 1;
    
    int t;
    for(int i = 2;i <= N;i++) for(int j = 1;j <= K;j++) for(int k = 0;k < 4;k++) for(int l = 0;l < 4;l++) if(j >= (t = d[l][k])) inc(dp[i][j][k], dp[i - 1][j - t][l]);
    
    int ans = 0;
    for(int i = 0;i < 4;i++) inc(ans, dp[N][K][i]);
    
    printf("%d\n", ans);
    
    return 0;
}