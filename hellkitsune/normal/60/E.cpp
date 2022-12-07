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

int n, MOD;
int a[1000000];
LL x, y;
int mat[2][2], res[2][2];
LL tmp[2][2];

void matMul(int (&a)[2][2], int (&b)[2][2]) {
    REP(i, 2) REP(j, 2) {
        tmp[i][j] = 0;
        REP(k, 2) tmp[i][j] += (LL)a[i][k] * b[k][j];
    }
    REP(i, 2) REP(j, 2) a[i][j] = tmp[i][j] % MOD;
}

void matPow(LL x) {
    REP(i, 2) REP(j, 2) res[i][j] = i == j;
    while (x) {
        if (x & 1) matMul(res, mat);
        x >>= 1;
        matMul(mat, mat);
    }
}

int binPow(LL x, LL p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * x % MOD;
        p >>= 1;
        x = x * x % MOD;
    }
    return (int)ret;
}

int go(LL x) {
    if (x == 0) return 1;
    if (x == 1) return 4;
    int ret = go((x - 1) / 2);
    ret = (LL)ret * (binPow(3, (x + 1) / 2) + 1) % MOD;
    if (!(x & 1)) {
        ret = (3ll * ret + 1) % MOD;
    }
    return ret;
}

int calc(LL x) {
    if (x == 0) return 1;
    int ret = binPow(3, x);
    ret -= go(x - 1);
    if (ret < 0) ret += MOD;
    return ret;
}

int main() {
    scanf("%d%I64d%I64d%d", &n, &x, &y, &MOD);
    REP(i, n) scanf("%d", a + i);
    if (n == 1) {
        cout << a[0] % MOD << endl;
        return 0;
    }
    LL ans = 0, mul = calc(x);
    REP(i, n) {
        ans += a[i];
    }
    ans %= MOD;
    ans *= 2 * mul - 1;
    ans -= (a[0] + a[n - 1]) * (mul - 1);
    ans %= MOD;

    if (y) {
        REP(i, 2) REP(j, 2) mat[i][j] = i | j;
        matPow(x);
        LL mnmx = a[0] + (LL)a[n - 2] * res[0][1] + (LL)a[n - 1] * res[1][1];
        mnmx %= MOD;
        mul = calc(y);
        ans *= 2 * mul - 1;
        ans -= mnmx * (mul - 1);
    }

    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}