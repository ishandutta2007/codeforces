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
char s[25][25];
int a[25][25], d[1 << 20], ma[25][25], c[25][25];
const int INF = 1e9;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n) REP(j, m) scanf("%d", a[i] + j);
    REP(i, n) REP(j, m) {
        int &mask = ma[i][j], &cost = c[i][j], mx = 0;
        REP(k, n) if (s[k][j] == s[i][j]) {
            cost += a[k][j];
            mask |= 1 << k;
            mx = max(mx, a[k][j]);
        }
        cost -= mx;
    }
    REP(i, 1 << n) d[i] = INF;
    d[0] = 0;
    REP(mask, (1 << n) - 1) {
        int i = 0;
        while (mask & (1 << i)) ++i;
        REP(j, m) {
            d[mask | ma[i][j]] = min(d[mask | ma[i][j]], d[mask] + c[i][j]);
            d[mask | (1 << i)] = min(d[mask | (1 << i)], d[mask] + a[i][j]);
        }
    }
    printf("%d\n", d[(1 << n) - 1]);
    return 0;
}