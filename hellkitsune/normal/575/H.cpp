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

int n;
int f[2222222], rf[2222222];
const int MOD = 1e9 + 7;

int binPow(LL x, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * x % MOD;
        p >>= 1;
        x = x * x % MOD;
    }
    return (int)ret;
}

int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int main() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < 2222222; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    scanf("%d", &n);
    int ans = 0;
    for (int i = n + 1; i <= 2 * n + 1; ++i) {
        ans += c(i, n);
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d\n", ans);
    return 0;
}