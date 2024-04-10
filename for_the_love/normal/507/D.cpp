#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, M;

LL tt[N], ten[N], dp[1005][105][2];

int main(){
    scanf("%d%d%d", &n, &m, &M);
    ten[0] = 1;
    for (int i = 1; i <= n; i++) ten[i] = ten[i - 1] * 10 % m;
    tt[0] = 1;
    for (int i = 1; i <= n; i++) tt[i] = tt[i - 1] * 10 % M;
    LL ans = 0;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
    for (int k = 0; k < 10; k++){
        if (i == n && !k) continue;
        int x = (k * ten[i - 1] + j) % m;
        if (k){
            LL s = dp[i - 1][j][0] + dp[i - 1][j][1];
            if (!x){
                if (n == i) ans = (ans + s) % M;
                else ans = (ans + s * tt[n - i - 1] % M * 9) % M;
            }else dp[i][x][1] = (dp[i][x][1] + s) % M;
        }else{
            dp[i][x][0] = (dp[i][x][0] + dp[i - 1][j][0]) % M;
            dp[i][x][1] = (dp[i][x][1] + dp[i - 1][j][1]) % M;
        }
    }
    cout << ans << endl;
}