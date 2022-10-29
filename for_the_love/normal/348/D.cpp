#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 3333;
long long dp0[N][N], dp1[N][N];
char s[N][N];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    dp0[1][2] = 1;
    dp1[2][1] = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (s[i][j] != '#'){
        if (i != 1 && s[i - 1][j] == '.') dp0[i][j] += dp0[i - 1][j], dp1[i][j] += dp1[i - 1][j];
        if (j != 1 && s[i][j - 1] == '.') dp0[i][j] += dp0[i][j - 1], dp1[i][j] += dp1[i][j - 1];
        dp0[i][j] %= MOD;
        dp1[i][j] %= MOD;
    }
    cout << (dp0[n - 1][m] * dp1[n][m - 1] - dp0[n][m - 1] * dp1[n - 1][m] + MOD * MOD) % MOD << endl;
}