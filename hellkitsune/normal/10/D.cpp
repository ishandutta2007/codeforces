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
int a[500], b[500];
int d[501][501] = {};
int pi[501][501], pj[501][501];
int nx[501][501];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    scanf("%d", &m);
    REP(i, m) scanf("%d", b + i);
    reverse(a, a + n);
    reverse(b, b + m);
    REP(i, n) {
        nx[i][m] = m;
        for (int j = m - 1; j >= 0; --j) if (a[i] == b[j]) {
            nx[i][j] = j;
        } else {
            nx[i][j] = nx[i][j + 1];
        }
    }
    REP(i, n) REP(j, m) if (d[i][j] || (!i && !j)) {
        for (int k = i; k < n; ++k)
        if ((!i || a[k] < a[i - 1]) && nx[k][j] < m) {
            int ii = k + 1;
            int jj = nx[k][j] + 1;
            if (d[ii][jj] <= d[i][j]) {
                d[ii][jj] = d[i][j] + 1;
                pi[ii][jj] = i;
                pj[ii][jj] = j;
            }
        }
    }
    int ans = 0, i = 0, j = 0;
    REP(ii, n + 1) REP(jj, m + 1) if (d[ii][jj] > ans) {
        ans = d[ii][jj];
        i = ii;
        j = jj;
    }
    printf("%d\n", ans);
    REP(times, ans) {
        printf("%d ", a[i - 1]);
        int oi = i;
        i = pi[i][j];
        j = pj[oi][j];
    }
    return 0;
}