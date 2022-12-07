#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef unsigned long long LL;
typedef pair<int, int> PII;

int n, b, k, x;
int cnt[10] = {};
int mat[101][101] = {}, tmp[101][101], res[101][101], mul[101][101];
const int MOD = 1e9 + 7;
const LL INF = 17e18;
int s;

void matMul(int (&a)[101][101], int (&b)[101][101]) {
    REP(i, s) REP(j, s) {
        LL x = 0;
        REP(k, s) {
            x += (LL)a[i][k] * b[k][j];
            if (x > INF) x %= MOD;
        }
        tmp[i][j] = x % MOD;
    }
    REP(i, s) REP(j, s) a[i][j] = tmp[i][j];
}

void matExp(int p) {
    REP(i, s) REP(j, s) res[i][j] = i == j;
    REP(i, s) REP(j, s) mul[i][j] = mat[i][j];
    while (p) {
        if (p & 1) matMul(res, mul);
        p >>= 1;
        if (p) matMul(mul, mul);
    }
}

int main() {
    scanf("%d%d%d%d", &n, &b, &k, &x);
    REP(i, n) {
        int dig;
        scanf("%d", &dig);
        ++cnt[dig];
    }
    REP(i, x + 1) {
        for (int dig = 1; dig <= 9; ++dig) {
            int j = (10 * i + dig) % x;
            mat[i][j] += cnt[dig];
        }
    }
    s = x + 1;
    matExp(b);
    printf("%d\n", res[0][k]);
    return 0;
}