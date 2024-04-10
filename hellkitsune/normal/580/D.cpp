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

LL d[18][1 << 18];
int n, m, k;
int a[18];
int c[18][18] = {};

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) scanf("%d", a + i);
    REP(i, k) {
        int x, y, cc;
        scanf("%d%d%d", &x, &y, &cc), --x, --y;
        c[x][y] = cc;
    }
    for (int j = 1; j < (1 << n) - 1; ++j) REP(i, n) if (j & (1 << i)) {
        REP(k, n) if (!(j & (1 << k))) {
            d[k][j | (1 << k)] = max(d[k][j | (1 << k)], d[i][j] + c[i][k]);
        }
    }
    LL ans = 0;
    REP(mask, 1 << n) if (__builtin_popcount(mask) == m) {
        LL cur = 0;
        REP(i, n) if (mask & (1 << i)) cur = max(cur, d[i][mask]);
        REP(i, n) if (mask & (1 << i)) {
            cur += a[i];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}