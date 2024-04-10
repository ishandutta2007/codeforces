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

int n, m, MOD;
LL k;
int s[50000];
LL ind[50001], tmp[50000];
int val[50001], ord[50000];
int mu[60][50000][2][2];
int mtmp[2][2];
int vec[2], nvec[2];
const LL MX = 1e18;

void koef(int (&m)[2][2], int a, int b) {
    a %= MOD;
    b %= MOD;
    m[0][0] = 0;
    m[1][0] = 1;
    m[0][1] = a;
    m[1][1] = b;
}

void matMul(int (&m)[2][2], int (&a)[2][2], int (&b)[2][2]) {
    REP(i, 2) REP(j, 2) {
        LL val = 0;
        REP(k, 2) val += (LL)a[i][k] * b[k][j];
        m[i][j] = val % MOD;
    }
}

void vecMul(int (&m)[2][2]) {
    REP(i, 2) {
        LL val = 0;
        REP(j, 2) val += (LL)vec[j] * m[j][i];
        nvec[i] = val % MOD;
    }
    REP(i, 2) vec[i] = nvec[i];
}

inline bool cmp(const int &lhs, const int &rhs) {
    return ind[lhs] < ind[rhs];
}

int main() {
    scanf("%I64d%d%d", &k, &MOD, &n);
    if (k < 2) {
        if (k == 0) printf("0\n");
        else printf("%d\n", 1 % MOD);
        return 0;
    }
    REP(i, n) scanf("%d", s + i);
    scanf("%d", &m);
    REP(i, m) scanf("%I64d%d", ind + i, val + i);
    REP(i, m) ord[i] = i;
    sort(ord, ord + m, cmp);
    REP(i, m) tmp[i] = ind[ord[i]];
    REP(i, m) ind[i] = tmp[i];
    REP(i, m) tmp[i] = val[ord[i]];
    REP(i, m) val[i] = tmp[i];
    ind[m++] = 1e18 + 15;
    koef(mu[0][0], s[(2 * n - 2) % n], s[(2 * n - 1) % n]);
    koef(mu[0][1], s[(2 * n - 1) % n], s[0]);
    for (int i = 2; i < n; ++i) koef(mu[0][i], s[i - 2], s[i - 1]);
    for (int i = 0; i < 59; ++i) REP(j, n) {
        matMul(mu[i + 1][j], mu[i][j], mu[i][(j + (1ll << i)) % n]);
    }
    LL pos = 2;
    int bad = 0;
    vec[0] = 0, vec[1] = 1 % MOD;
    while (pos <= k) {
        LL ok = min(k, ind[bad]) + 1;
        if (ok != pos) {
            for (int i = 59; i >= 0; --i) if (ok - pos >= (1ll << i)) {
                vecMul(mu[i][pos % n]);
                pos += 1ll << i;
            }
        }
        if (pos > k) break;
        int a = s[(pos - 2) % n];
        int b = val[bad];
        int tmp = vec[1];
        vec[1] = ((LL)vec[0] * a + (LL)vec[1] * b) % MOD;
        vec[0] = tmp;
        ++pos, ++bad;
        if (pos > k) break;
        while (ind[bad] - 1 == ind[bad - 1]) {
            a = val[bad - 1];
            b = val[bad];
            tmp = vec[1];
            vec[1] = ((LL)vec[0] * a + (LL)vec[1] * b) % MOD;
            vec[0] = tmp;
            ++pos, ++bad;
            if (pos > k) break;
        }
        if (pos > k) break;
        a = val[bad - 1];
        b = s[(pos - 1) % n];
        tmp = vec[1];
        vec[1] = ((LL)vec[0] * a + (LL)vec[1] * b) % MOD;
        vec[0] = tmp;
        ++pos;
    }
    printf("%d\n", vec[1] % MOD);
    return 0;
}