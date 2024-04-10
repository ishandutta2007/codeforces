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
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;
typedef pair<DB, DB> DPI;
const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int sum[N], f[N];

int main(){
    int cas, k, x, y, n;
    scanf("%d%d", &cas, &k);
    f[0] = 1;
    for (int i = 1; i <= 100000; i++){
        if (i >= k) f[i] = (f[i - 1] + f[i - k]) % MOD;
        else f[i] = f[i - 1];
        sum[i] = (sum[i - 1] + f[i]) % MOD;
    }
    while (cas--){
        scanf("%d%d", &x, &y);
        printf("%d\n", ((sum[y] - sum[x - 1]) % MOD + MOD) % MOD);
    }
}