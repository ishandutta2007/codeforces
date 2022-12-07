#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int d[505][505] = {};
int p[505];
const int MOD = 1e9 + 7;

int main() {
    p[0] = 1;
    for (int i = 1; i < 505; ++i) {
        p[i] = (p[i - 1] * 2) % MOD;
    }
    scanf("%d%d", &n, &k);
    d[0][0] = 1;
    for (int r = 1; r <= n; ++r) {
        for (int i = 0; i < r; ++i) for (int j = 0; j <= i; ++j) {
            d[i][j] = (d[i][j] * (LL)p[i]) % MOD;
            d[r][j + 1] = (d[r][j + 1] + d[i][j] * (LL)(p[r - i] - 1)) % MOD;
        }
    }
    int ans = 0;
    REP(i, n + 1) ans = (ans + d[i][k]) % MOD;
    printf("%d\n", ans);
    return 0;
}