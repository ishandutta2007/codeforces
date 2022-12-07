#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

const int N = 128;
int sz;
Double mat[N][N] = {}, res[N][N] = {}, tmp[N][N] = {};

void matMul(Double (&a)[N][N], Double (&b)[N][N]) {
    forn(i, sz) forn(j, sz) {
        tmp[i][j] = 0;
        forn(k, sz) {
            tmp[i][j] += a[i][k] * b[k][j];
        }
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

int n, x;
double p[222];
double bit[10] = {};

void brute() {
    double win = 0;
    forn(i, 3) forn(j, 3) {
        double prob = p[i] * p[j];
        int xo = i ^ j;
        if (xo > 0) win += prob;
    }
    cerr << "!" << win << endl;
}

int main() {
    cin >> n >> x;
    forn(i, x + 1) cin >> p[i];
    //brute();
    sz = 128;
    forn(i, 128) forn(j, x + 1) {
        mat[i][i ^ j] = p[j];
    }
    matPow(n);
    printf("%.15f\n", (double)(1 - res[0][0]));
    return 0;
}