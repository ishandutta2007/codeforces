#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2005;
const int M = 1 << 21;
const int MOD = 1e9 + 7;
int f[N][N];

int main(){
    int n, K;
    scanf("%d%d", &K, &n);
    for (int i = 1; i <= K; i++) f[1][i] = 1;
    for (int i = 2; i <= n; i++)
    for (int j = 1; j <= K; j++)
    for (int k = 1; k * j <= K; k++)
        f[i][k * j] = (f[i][k * j] + f[i - 1][j]) % MOD;
    LL ans = 0;
    for (int i = 1; i <= K; i++) ans = (ans + f[n][i]) % MOD;
    cout << ans << endl;
}