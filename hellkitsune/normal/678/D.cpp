#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, x;
LL n;
const int MOD = 1e9 + 7;

const int N = 3;
int mat[N][N] = {}, res[N][N] = {}, tmp[N][N] = {};

void matMul(int (&a)[N][N], int (&b)[N][N]) {
    REP(i, N) REP(j, N) {
        LL res = 0;
        REP(k, N) {
            res += (LL)a[i][k] * b[k][j];
        }
        tmp[i][j] = res % MOD;
    }
    REP(i, N) REP(j, N) a[i][j] = tmp[i][j];
}

void matPow(LL p) {
    REP(i, N) REP(j, N) res[i][j] = i == j;
    while (p) {
        if (p & 1) matMul(res, mat);
        p >>= 1;
        if (p) matMul(mat, mat);
    }
}

int vec[N] = {1, 0, 1};
void vecMul() {
    LL nvec[N] = {};
    REP(i, N) REP(j, N) {
        nvec[j] += (LL)vec[i] * mat[i][j];
    }
    REP(i, N) vec[i] = nvec[i] % MOD;
}

int main() {
    cin >> a >> b >> n >> x;
    mat[0][0] = a;
    mat[1][1] = a;
    mat[2][1] = b;
    mat[2][2] = 1;
    matPow(n);
    memcpy(mat, res, sizeof mat);
    vecMul();
    int ans = ((LL)vec[0] * x + vec[1]) % MOD;
    cout << ans << endl;
    return 0;
}