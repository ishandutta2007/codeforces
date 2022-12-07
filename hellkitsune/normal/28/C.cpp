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

int n, m;
int a[50];
double c[60][60] = {};
double d[51][51], d2[51][51];
double x[60][60], y[60][60];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) cin >> a[i];
    c[0][0] = 1;
    for (int i = 1; i < 60; ++i) {
        x[i][0] = 1;
        for (int j = 1; j < 60; ++j)
            x[i][j] = x[i][j - 1] / i;
    }
    for (int i = 1; i < 60; ++i) {
        y[i][0] = 1;
        for (int j = 1; j < 60; ++j)
            y[i][j] = (i - 1) * y[i][j - 1] / i;
    }
    for (int i = 1; i < 60; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 60; ++j)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    REP(i, n + 1) REP(j, n + 1) d[i][j] = 0;
    d[0][n] = 1;
    REP(w, m) {
        REP(i, n + 1) REP(j, n + 1) d2[i][j] = 0;
        REP(i, n + 1) REP(j, n + 1) {
            REP(k, j + 1) d2[max(i, (k + a[w] - 1) / a[w])][j - k] += d[i][j] * c[j][k] * x[m - w][k] * y[m - w][j - k];
        }
        REP(i, n + 1) REP(j, n + 1) if (d2[i][j] < 1e-50)
            d2[i][j] = 0;
        REP(i, n + 1) REP(j, n + 1) d[i][j] = d2[i][j];
    }
    double ans = 0;
    REP(i, n + 1) ans = ans + i * d[i][0];
    cout << setprecision(15) << fixed << ans << endl;
    return 0;
}