#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9;
int d[31][31][51] = {};

int main() {
    REP(i, 31) REP(j, 31) REP(k, 51) d[i][j][k] = INF;
    REP(i, 31) REP(j, 31) REP(k, 51) {
        int &cur = d[i][j][k];
        if (k == 0) {
            cur = 0;
            continue;
        }
        if (k >= i * j) {
            if (k == i * j) cur = 0;
            continue;
        }
        for (int ii = 0; ii <= i - ii; ++ii) REP(kk, k + 1) {
            cur = min(cur, d[ii][j][kk] + d[i - ii][j][k - kk] + j * j);
        }
        for (int jj = 0; jj <= j - jj; ++jj) REP(kk, k + 1) {
            cur = min(cur, d[i][jj][kk] + d[i][j - jj][k - kk] + i * i);
        }
    }
    int tt;
    scanf("%d", &tt);
    REP(test, tt) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", d[n][m][k]);
    }
    return 0;
}