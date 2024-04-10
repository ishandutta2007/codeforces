#include <map>
#include <set>
#include <cmath>
#include <queue>
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
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

LL f[5005][5005], s[5005];

int main(){
    int n, m, k, x;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        s[i] = s[i - 1] + x;
        for (int j = 1; j <= k; j++)
        if (i >= m) f[i][j] = max(f[i][j], f[i - m][j - 1] + s[i] - s[i - m]);
        for (int j = 0; j <= k; j++)
            f[i][j] = max(f[i][j], f[i - 1][j]);
    }
    printf("%I64d\n", f[n][k]);
}