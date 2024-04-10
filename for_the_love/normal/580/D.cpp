#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
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
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, k, e[19][19], a[19];

LL dp[1 << 18][19];

LL dfs(int x, int num, int last){
    if (num == m) return dp[x][last] = 0;
    if (dp[x][last] != -1) return dp[x][last];
    dp[x][last] = 0;
    for (int i = 0; i < n; i++)
    if (!(x >> i & 1)){
        dp[x][last] = max(dp[x][last], dfs(x ^ (1 << i), num + 1, i) + e[last][i] + a[i]);
    }
    return dp[x][last];
}

int main(){
    int x, y, z;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < k; i++){
        scanf("%d%d%d", &x, &y, &z);
        e[x - 1][y - 1] = z;
    }
    memset(dp, -1, sizeof(dp));
    printf("%I64d\n", dfs(0, 0, n));
}