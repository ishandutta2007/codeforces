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
typedef long long LL;
typedef pair<int, int> PII;

int f[1005], rf[1005];
const int MOD = 1e9 + 7;

int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int binPow(LL x, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * x % MOD;
        p >>= 1;
        x = x * x % MOD;
    }
    return (int)ret;
}

int n = 0, m;
int x[100], y[100];
int d[1005][1005] = {};

int main() {
    f[0] = 1;
    for (int i = 1; i < 1005; ++i) f[i] = (LL)f[i - 1] * i % MOD;
    REP(i, 1005) rf[i] = binPow(f[i], MOD - 2);
    scanf("%d", &m);
    REP(i, m) scanf("%d", x + i), n += x[i];
    REP(i, m) scanf("%d", y + i);
    LL ans = f[n];
    REP(i, m) ans = ans * rf[x[i]] % MOD;
    d[0][0] = 1;
    REP(i, m - 1) REP(j, n + 1) if (d[i][j]) {
        int cnt = j + x[i];
        for (int k = max(0, cnt - y[i]); k <= cnt; ++k) {
            d[i + 1][k] = (d[i + 1][k] + (LL)d[i][j] * c(cnt, k)) % MOD;
        }
    }
    LL ans2 = 0;
    for (int i = y[m - 1] - x[m - 1]; i >= 0; --i)
        ans2 = (ans2 + d[m - 1][i]) % MOD;
    ans = ans * ans2 % MOD;
    printf("%d\n", (int)ans);
    return 0;
}