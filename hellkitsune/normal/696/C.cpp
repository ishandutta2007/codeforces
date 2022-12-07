#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;


const int MOD = 1e9 + 7;
int mat[2][2] = {}, res[2][2] = {}, tmp[2][2] = {}, tr[2][2];

void matMul(int (&a)[2][2], int (&b)[2][2]) {
    REP(i, 2) REP(j, 2) {
        LL res = 0;
        REP(k, 2) {
            res += (LL)a[i][k] * b[k][j];
        }
        tmp[i][j] = res % MOD;
    }
    REP(i, 2) REP(j, 2) a[i][j] = tmp[i][j];
}

void matPow(LL p) {
    REP(i, 2) REP(j, 2) res[i][j] = i == j;
    while (p) {
        if (p & 1) matMul(res, mat);
        p >>= 1;
        if (p) matMul(mat, mat);
    }
}

int vec[2];

void vecMul() {
    int nvec[2];
    REP(j, 2) {
        LL res = 0;
        REP(i, 2) {
            res += (LL)vec[i] * mat[i][j];
        }
        nvec[j] = res % MOD;
    }
    REP(i, 2) vec[i] = nvec[i];
}

int main() {
    mat[1][1] = 2;
    mat[0][0] = MOD - 1;
    mat[1][0] = 1;
    int k;
    scanf("%d", &k);
    REP(times, k) {
        LL p;
        scanf("%I64d", &p);
        matPow(p);
        REP(i, 2) REP(j, 2) mat[i][j] = res[i][j];
    }
    vec[0] = vec[1] = 1;
    vecMul();
    REP(i, 2) vec[i] = (LL)vec[i] * (MOD / 2 + 1) % MOD;
    printf("%d/%d\n", vec[0], vec[1]);
    return 0;
}