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
int f[50][50], mn[50], mx[50];
const int INF = 1e9;
int gm, gg, sm, ss;
LL d[51][51] = {}, nd[51][51];
bool cang[50], cans[50], canb[50];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) REP(j, n) f[i][j] = INF;
    REP(i, n) f[i][i] = 0;
    REP(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        f[from][to] = min(f[from][to], w);
        f[to][from] = min(f[to][from], w);
    }
    scanf("%d%d%d%d", &gm, &gg, &sm, &ss);
    REP(k, n) REP(i, n) REP(j, n) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
    REP(i, n) {
        mn[i] = INF, mx[i] = -INF;
        REP(j, n) if (i != j) {
            mn[i] = min(mn[i], f[i][j]);
            mx[i] = max(mx[i], f[i][j]);
        }
    }
    LL ans = 0;
    REP(gco, n) REP(bco, n) if (mn[gco] < mx[bco] || (mn[gco] == mx[bco] && gco < bco)) {
        if (gco == bco) continue;
        bool ok = true;
        REP(i, n) {
            if (i == gco) {
                cang[i] = true;
                cans[i] = canb[i] = false;
            } else if (i == bco) {
                canb[i] = true;
                cang[i] = cans[i] = false;
            } else {
                cang[i] = mn[i] < mn[gco] || (mn[i] == mn[gco] && i < gco);
                canb[i] = mx[i] > mx[bco] || (mx[i] == mx[bco] && i > bco);
                cans[i] = false;
                REP(j, n) if (j != i && (f[i][j] > mn[gco] || (f[i][j] == mn[gco] && i > gco)) &&
                              (f[i][j] < mx[bco] || (f[i][j] == mx[bco] && i < bco))) {
                    cans[i] = true;
                    break;
                }
                if (!cang[i] && !cans[i] && !canb[i]) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;
        memset(d, 0, sizeof d);
        d[0][0] = 1;
        REP(i, n) {
            memset(nd, 0, sizeof nd);
            REP(g, gg + 1) REP(s, ss + 1) if (d[g][s] != 0) {
                if (cang[i]) {
                    nd[g + 1][s] += d[g][s];
                }
                if (cans[i]) {
                    nd[g][s + 1] += d[g][s];
                }
                if (canb[i]) {
                    nd[g][s] += d[g][s];
                }
            }
            memcpy(d, nd, sizeof nd);
        }
        for (int g = gm; g <= gg; ++g) for (int s = sm; s <= ss; ++s) {
            ans += d[g][s];
        }
        d[gg][ss] -= ans;
    }
    cout << ans << endl;
    return 0;
}