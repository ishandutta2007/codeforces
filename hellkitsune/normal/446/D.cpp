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

int n, m, k;
double g[500][500];
int ind[500];
int t[500] = {};
double x[500][500], a[500][105];
int xc, ac;

const int SZ = 105;
int sz;
double mat[SZ][SZ] = {}, tmp[SZ][SZ], res[SZ][SZ];
void matMul(double (&a)[SZ][SZ], double (&b)[SZ][SZ]) {
    REP(i, sz) REP(j, sz) {
        double val = 0;
        REP(q, sz) val += a[i][q] * b[q][j];
        tmp[i][j] = val;
    }
    REP(i, sz) REP(j, sz) {
        a[i][j] = tmp[i][j];
    }
}

void matExp(int p) {
    REP(i, sz) REP(j, sz) res[i][j] = 0;
    REP(i, sz) res[i][i] = 1;
    while (p) {
        if (p & 1) {
            matMul(res, mat);
        }
        p >>= 1;
        matMul(mat, mat);
    }
}

void solve() {
    xc = ac = 0;
    REP(i, n) if (t[i]) {
        ind[i] = ac++;
    } else {
        ind[i] = xc++;
    }
    REP(i, xc) {
        REP(j, xc) x[i][j] = 0;
        REP(j, ac) a[i][j] = 0;
    }
    REP(i, n) if (!t[i]) {
        int ii = ind[i];
        x[ii][ii] = 1;
        REP(j, n) if (!t[j] && i != j) {
            int jj = ind[j];
            x[ii][jj] = -g[i][j];
        }
        REP(j, n) if (t[j]) {
            int jj = ind[j];
            a[ii][jj] = g[i][j];
        }
    }
    REP(i, xc) {
        int best = i;
        for (int j = i + 1; j < xc; ++j) if (abs(x[j][i]) > abs(x[best][i])) {
            best = j;
        }
        if (best != i) {
            REP(j, xc) swap(x[i][j], x[best][j]);
            REP(j, ac) swap(a[i][j], a[best][j]);
        }
        double mul = 1.0 / x[i][i];
        REP(j, xc) x[i][j] *= mul;
        REP(j, ac) a[i][j] *= mul;
        for (int j = i + 1; j < xc; ++j) {
            mul = x[j][i];
            REP(q, xc) x[j][q] -= mul * x[i][q];
            REP(q, ac) a[j][q] -= mul * a[i][q];
        }
    }
    for (int i = xc - 1; i > 0; --i) {
        REP(j, i) {
            double mul = x[j][i];
            REP(q, ac) a[j][q] -= mul * a[i][q];
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k), k -= 2;
    REP(i, n) scanf("%d", t + i);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        ++g[from][to];
        ++g[to][from];
    }
    REP(i, n) {
        double mul = 0;
        REP(j, n) mul += g[i][j];
        mul = 1.0 / mul;
        REP(j, n) g[i][j] *= mul;
    }
    solve();
    sz = ac;
    REP(i, n) if (t[i]) {
        int ii = ind[i];
        REP(j, n) if (!t[j]) {
            int jj = ind[j];
            double mul = g[i][j];
            REP(q, sz) mat[ii][q] += mul * a[jj][q];
        } else {
            int jj = ind[j];
            mat[ii][jj] += g[i][j];
        }
    }
    matExp(k);
    double ans = 0;
    REP(i, sz) ans += a[0][i] * res[i][sz - 1];
    printf("%.12f\n", ans);
    return 0;
}