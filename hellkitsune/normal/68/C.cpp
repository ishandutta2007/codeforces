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

int lo[6][6], hi[6][6], a[6][6], bal[6], mx[6], tot = 0;
int n, m;
const int INF = 1e9;
int besta = INF, bestb = -1;

void go(int x, int y) {
    if (x == n - 1) {
        if (bal[x] < besta || (bal[x] == besta && tot > bestb)) {
            besta = bal[x];
            bestb = tot;
        }
        return;
    }
    if (y == n - 1 && x) {
        if (bal[x] >= lo[x][y] && bal[x] <= hi[x][y]) {
            bal[y] += bal[x];
            tot += bal[x] * bal[x];
            if (bal[x]) tot += a[x][y];
            go(x + 1, x + 2);
            if (bal[x]) tot -= a[x][y];
            tot -= bal[x] * bal[x];
            bal[y] -= bal[x];
        }
    } else {
        int upto = min(hi[x][y], mx[y] - bal[y]);
        for (int i = lo[x][y]; i <= upto; ++i) {
            bal[x] -= i;
            bal[y] += i;
            if (i) tot += a[x][y];
            tot += i * i;
            if (!x && y == n - 1) {
                if (-bal[0] <= besta) go(1, 2);
            } else {
                go(x, y + 1);
            }
            tot -= i * i;
            if (i) tot -= a[x][y];
            bal[y] -= i;
            bal[x] += i;
        }
    }
}

int main() {
    scanf("%d", &n);
    m = n * (n - 1) / 2;
    REP(i, m) {
        int from, to, l, h, aa;
        scanf("%d%d%d%d%d", &from, &to, &l, &h, &aa), --from, --to;
        lo[from][to] = l;
        hi[from][to] = h;
        a[from][to] = aa;
    }
    REP(i, n - 1) {
        mx[i] = 0;
        for (int j = i + 1; j < n; ++j) {
            mx[i] += hi[i][j];
        }
    }
    mx[n - 1] = 12345;
    go(0, 1);
    if (besta == INF) printf("-1 -1\n");
    else printf("%d %d\n", besta, bestb);
    return 0;
}