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

int n, x;
int d[101] = {};
int m[101][101] = {}, t[101][101], res[101][101];

const int MOD = 1e9 + 7;

void matMul(int (&a)[101][101], int (&b)[101][101], int (&c)[101][101]) {
    REP(i, 101) REP(j, 101) {
        c[i][j] = 0;
        REP(k, 101) c[i][j] = (c[i][j] + (LL)a[i][k] * b[k][j]) % MOD;
    }
}

void matAssign(int (&a)[101][101], int (&b)[101][101]) {
    REP(i, 101) REP(j, 101)
        a[i][j] = b[i][j];
}

void matPow(int p) {
    REP(i, 101) REP(j, 101) res[i][j] = 0;
    REP(i, 101) res[i][i] = 1;
    while (p) {
        if (p & 1) {
            matMul(res, m, t);
            matAssign(res, t);
        }
        matMul(m, m, t);
        matAssign(m, t);
        p >>= 1;
    }
}

int main() {
    scanf("%d%d", &n, &x);
    REP(i, n) {
        int zz;
        scanf("%d", &zz);
        ++d[zz];
    }
    REP(i, 99) m[i + 1][i] = 1;
    REP(i, 100) {
        m[i][99] = d[100 - i];
    }
    m[100][100] = 1;
    m[99][100] = 1;
    matPow(x + 1);
    printf("%d\n", res[99][100]);
    return 0;
}