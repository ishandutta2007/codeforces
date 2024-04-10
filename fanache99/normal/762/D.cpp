//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const long long INF = 100000000000000000LL;

int a[4][1 + MAXN];
long long dp[4][1 + MAXN];

void Update(long long &x, long long y) {
    if (y > x)
        x = y;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dp[1][1] = a[1][1];
    dp[2][1] = dp[1][1] + a[2][1];
    dp[3][1] = dp[2][1] + a[3][1];
    dp[2][0] = dp[3][0] = -INF;
    for (int i = 2; i <= n; i++) {
        dp[1][i] = dp[2][i] = dp[3][i] = -INF;
        Update(dp[1][i], dp[1][i - 1] + a[1][i]);
        Update(dp[1][i], dp[2][i - 1] + a[2][i] + a[1][i]);
        Update(dp[1][i], dp[3][i - 1] + a[3][i] + a[2][i] + a[1][i]);
        Update(dp[1][i], dp[3][i - 2] + a[3][i - 1] + a[3][i] + a[2][i] + a[2][i - 1] + a[1][i - 1] + a[1][i]);
        Update(dp[2][i], dp[2][i - 1] + a[2][i]);
        Update(dp[2][i], dp[1][i - 1] + a[1][i] + a[2][i]);
        Update(dp[2][i], dp[3][i - 1] + a[3][i] + a[2][i]);
        Update(dp[3][i], dp[3][i - 1] + a[3][i]);
        Update(dp[3][i], dp[2][i - 1] + a[2][i] + a[3][i]);
        Update(dp[3][i], dp[1][i - 1] + a[1][i] + a[2][i] + a[3][i]);
        Update(dp[3][i], dp[1][i - 2] + a[1][i - 1] + a[1][i] + a[2][i] + a[2][i - 1] + a[3][i - 1] + a[3][i]);
    }
    cout << dp[3][n] << "\n";
    return 0;
}