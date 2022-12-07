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
typedef long long LL;
typedef pair<int, int> PII;

int xw[100][100] = {}, yw[100][100] = {};
int n, x[100], y[100], xx[100], yy[100];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d%d%d", x + i, y + i, xx + i, yy + i);
        x[i] += 50;
        xx[i] += 50;
        y[i] += 50;
        yy[i] += 50;
        if (x[i] > xx[i]) swap(x[i], xx[i]);
        if (y[i] > yy[i]) swap(y[i], yy[i]);
    }
    for (int i = 1; i < n; ++i) REP(j, i) {
        int sz = xx[i] - x[i];
        int sq = sz * sz;
        for (int cx = x[i]; cx < xx[i]; ++cx) xw[j][cx] += sq;
        for (int cy = y[i]; cy < yy[i]; ++cy) yw[j][cy] += sq;
        LL tot = 0, comb = 0;
        REP(q, 100) tot += xw[j][q];
        REP(q, 100) comb += xw[j][q] * q;
        if (comb * 2 < tot * (x[j] * 2 - 1) || comb * 2 > tot * (xx[j] * 2 - 1)) {
            printf("%d\n", i);
            return 0;
        }
        tot = 0, comb = 0;
        REP(q, 100) tot += yw[j][q];
        REP(q, 100) comb += yw[j][q] * q;
        if (comb * 2 < tot * (y[j] * 2 - 1) || comb * 2 > tot * (yy[j] * 2 - 1)) {
            printf("%d\n", i);
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}