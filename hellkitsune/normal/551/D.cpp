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
typedef unsigned long long LL;
typedef pair<int, int> PII;

LL n, k, l;
int MOD;
LL ONE = 1;

int a[2][2], b[2][2];

LL binPow(LL x, LL p) {
    x %= MOD;
    LL ret = 1;
    while (p) {
        if (p & 1) ret = (ret * x) % MOD;
        p >>= 1;
        x = (x * x) % MOD;
    }
    return ret;
}

void matMul(int (&a)[2][2], int (&b)[2][2]) {
    int tmp[2][2];
    REP(i, 2) REP(j, 2) {
        LL x = 0;
        REP(k, 2) x += (LL)a[i][k] * b[k][j];
        tmp[i][j] = x % MOD;
    }
    REP(i, 2) REP(j, 2) {
        a[i][j] = tmp[i][j];
    }
}

void matPow(int (&a)[2][2], int (&res)[2][2], LL p) {
    int b[2][2];
    REP(i, 2) REP(j, 2) b[i][j] = a[i][j];
    REP(i, 2) REP(j, 2) res[i][j] = i == j;
    while (p) {
        if (p & 1) {
            matMul(res, b);
        }
        p >>= 1;
        matMul(b, b);
    }
}

int main() {
    cin >> n >> k >> l >> MOD;
    for (LL i = l; i <= 61; ++i) if (k & (ONE << i)) {
        cout << 0 << endl;
        return 0;
    }
    int ones = 0, zeroes = 0;
    for (LL i = 0; i < l; ++i) {
        if (k & (ONE << i)) {
            ++ones;
        } else {
            ++zeroes;
        }
    }
    LL tot = binPow(2, n);
    REP(i, 2) REP(j, 2) a[i][j] = 1;
    a[1][1] = 0;
    matPow(a, b, n);
    LL zMul = b[0][0] + b[1][0];
    zMul %= MOD;
    LL oMul;
    if (tot >= zMul) {
        oMul = tot - zMul;
    } else {
        oMul = MOD + tot - zMul;
    }
    LL ans = binPow(oMul, ones) * binPow(zMul, zeroes);
    ans %= MOD;
    cout << ans << endl;
    return 0;
}