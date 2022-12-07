#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 16;
const int MOD = 1e9 + 7;
const unsigned long long WEW = 17.4e18;
int sz;
int mat[N][N] = {}, res[N][N] = {}, tmp[N][N] = {}, tr[N][N];

void matMul(int (&a)[N][N], int (&b)[N][N]) {
    forn(i, sz) forn(j, sz) {
        tr[i][j] = b[j][i];
    }
    forn(i, sz) forn(j, sz) {
        unsigned long long res = 0;
        forn(k, sz) {
            res += (unsigned long long) a[i][k] * tr[j][k];
            if (res > WEW) {
                res %= MOD;
            }
        }
        tmp[i][j] = res % MOD;
    }
    forn(i, sz) forn(j, sz) a[i][j] = tmp[i][j];
}

void matPow(LL p) {
    forn(i, sz) forn(j, sz) res[i][j] = i == j;
    while (p) {
        if (p & 1) matMul(res, mat);
        p >>= 1;
        if (p) matMul(mat, mat);
    }
}

int vec[N];

void vecMul() {
    int nvec[sz];
    forn(j, sz) {
        unsigned long long res = 0;
        forn(i, sz) {
            res += (unsigned long long) vec[i] * mat[i][j];
            if (res > WEW) {
                res %= MOD;
            }
        }
        nvec[j] = res % MOD;
    }
    forn(i, sz) vec[i] = nvec[i];
}

LL n, k;
LL a, b, c;

int main() {
    cin >> n >> k;
    sz = N;
    vec[0] = 1;
    forn(i, n) {
        cin >> a >> b >> c;
        b = min(b, k);
        for (int i = c + 1; i < N; ++i) {
            vec[i] = 0;
        }
        memset(mat, 0, sizeof mat);
        forn(i, c + 1) forn(j, c + 1) {
            if (abs(i - j) <= 1) {
                mat[i][j] = 1;
            }
        }
        matPow(b - a);
        memcpy(mat, res, sizeof mat);
        vecMul();
    }
    cout << vec[0] << endl;
    return 0;
}