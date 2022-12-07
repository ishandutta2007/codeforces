#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100;
const int MOD = 1e9 + 7;
const unsigned long long WEW = 17.4e18;
int sz;
int mat[N][N] = {}, res[N][N] = {}, tmp[N][N] = {}, tr[N][N];

void matMul(int (&a)[N][N], int (&b)[N][N]) {
    REP(i, sz) REP(j, sz) {
        tr[i][j] = b[j][i];
    }
    REP(i, sz) REP(j, sz) {
        unsigned long long res = 0;
        REP(k, sz) {
            res += (unsigned long long) a[i][k] * tr[j][k];
            if (res > WEW) {
                res %= MOD;
            }
        }
        tmp[i][j] = res % MOD;
    }
    REP(i, sz) REP(j, sz) a[i][j] = tmp[i][j];
}

void matPow(LL p) {
    REP(i, sz) REP(j, sz) res[i][j] = i == j;
    while (p) {
        if (p & 1) matMul(res, mat);
        p >>= 1;
        if (p) matMul(mat, mat);
    }
}

int vec[N];

void vecMul() {
    int nvec[sz];
    REP(j, sz) {
        unsigned long long res = 0;
        REP(i, sz) {
            res += (unsigned long long) vec[i] * mat[i][j];
            if (res > WEW) {
                res %= MOD;
            }
        }
        nvec[j] = res % MOD;
    }
    REP(i, sz) vec[i] = nvec[i];
}


int n;
LL k;
LL a[100];

int main() {
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    sz = n;
    REP(i, n) REP(j, n) mat[i][j] = __builtin_popcountll(a[i] ^ a[j]) % 3 == 0;
    matPow(k - 1);
    memcpy(mat, res, sizeof res);
    REP(i, n) vec[i] = 1;
    vecMul();
    int ans = 0;
    REP(i, n) {
        ans += vec[i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << endl;
    return 0;
}