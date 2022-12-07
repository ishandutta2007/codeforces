#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
int n, m, q, k;
int qt, x, y, t;
int cats[20] = {};
int mat[20][20], res[20][20], tmp[20][20], mul[20][20];
const unsigned long long MX = 17.4e18;

void matMul(int (&a)[20][20], int (&b)[20][20]) {
    REP(i, k) REP(j, k) {
        unsigned long long x = 0;
        REP(z, k) {
            x += (LL)a[i][z] * b[z][j];
            if (x > MX) x %= MOD;
        }
        tmp[i][j] = x % MOD;
    }
    REP(i, k) REP(j, k) a[i][j] = tmp[i][j];
}

void matExp(int p) {
    REP(i, k) REP(j, k) res[i][j] = i == j;
    REP(i, k) REP(j, k) mul[i][j] = mat[i][j];
    REP(i, k) if (cats[i]) {
        REP(j, k) mul[j][i] = 0;
    }
    while (p) {
        if (p & 1) matMul(res, mul);
        p >>= 1;
        if (p) matMul(mul, mul);
    }
}

int vec[20] = {}, nvec[20];

void vecMul() {
    REP(i, k) nvec[i] = 0;
    REP(i, k) REP(j, k) nvec[j] = (nvec[j] + (LL)vec[i] * res[i][j]) % MOD;
    REP(i, k) vec[i] = nvec[i];
}

void addEdge(int x, int y, int xx, int yy) {
    int from = x * m + y;
    int to = xx * m + yy;
    mat[from][to] = 1;
}

int main() {
    scanf("%d%d%d", &n, &m, &q), k = n * m;
    REP(i, n - 1) REP(j, m) addEdge(i, j, i + 1, j), addEdge(i + 1, j, i, j);
    REP(i, n) REP(j, m - 1) addEdge(i, j, i, j + 1), addEdge(i, j + 1, i, j);
    REP(i, n) REP(j, m) addEdge(i, j, i, j);
    int curt = 1;
    vec[0] = 1;
    REP(i, q) {
        scanf("%d%d%d%d", &qt, &x, &y, &t), --x, --y;
        int pos = x * m + y;
        matExp(t - curt);
        vecMul();
        if (qt == 2) {
            cats[pos] = 1;
            vec[pos] = 0;
        } else if (qt == 3) {
            cats[pos] = 0;
        } else {
            printf("%d\n", vec[pos]);
        }
        curt = t;
    }
    return 0;
}