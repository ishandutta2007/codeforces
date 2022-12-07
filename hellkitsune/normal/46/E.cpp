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

int n, m;
int a[1500][1500];
LL d[1500], nd[1500];
const LL INF = 1e15;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) REP(j, m) scanf("%d", a[i] + j);
    REP(i, n) REP(j, m - 1) a[i][j + 1] += a[i][j];
    REP(i, m) d[i] = a[0][i];
    for (int i = m - 2; i >= 0; --i) {
        d[i] = max(d[i], d[i + 1]);
    }
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            REP(j, m - 1) nd[j] = d[j + 1] + a[i][j];
            nd[m - 1] = -INF;
            if (i != n - 1) {
                for (int j = 1; j < m; ++j) {
                    nd[j] = max(nd[j], nd[j - 1]);
                }
            }
        } else {
            nd[0] = -INF;
            for (int j = 1; j < m; ++j) {
                nd[j] = d[j - 1] + a[i][j];
            }
            if (i != n - 1) {
                for (int j = m - 2; j >= 0; --j) {
                    nd[j] = max(nd[j], nd[j + 1]);
                }
            }
        }
        REP(j, m) d[j] = nd[j];
    }
    LL ans = -INF;
    REP(i, m) ans = max(ans, d[i]);

    cout << ans << endl;
    return 0;
}