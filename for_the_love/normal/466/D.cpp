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
typedef pair<LL, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

LL f[2111][2111];

int main(){
    int n, h, x;
    scanf("%d%d", &n, &h);
    f[0][0] = 1;

    for (int i = 1; i <= n; i++){
        scanf("%d", &x);

        int j = h - x;
        if (j < 0){
            puts("0");
            return 0;
        }
        if (j) f[i][j] += f[i - 1][j - 1] + f[i - 1][j] * j;
        f[i][j] += f[i - 1][j] + f[i - 1][j + 1] * (j + 1);
        f[i][j] %= MOD;
        if (i == n){
            if (j == 1 || j == 0) printf("%d\n", (int)f[i][j]); else puts("0");
            return 0;
        }
    }

}