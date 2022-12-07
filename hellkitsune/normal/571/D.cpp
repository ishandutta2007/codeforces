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
typedef pair<int, LL> PILL;

struct Triple {
    int x, y;
    LL z;
    Triple(int x, int y, LL z) : x(x), y(y), z(z) {}
    Triple() {}
};

int n, m;
vector<PILL> upd[500000];
vector<Triple> t[500000];
int mupd[500000] = {};
vector<PII> mt[500000];
int par[500000], ra[500000], mpar[500000], mra[500000];
int cm[500000], mcm[500000];
vector<int> cv[500000], mcv[500000];
char qt[5];
int x, y;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) t[i].pb(Triple(0, i, 0));
    REP(i, n) mt[i].pb(mp(0, i));
    REP(i, n) cm[i] = i, mcm[i] = i, cv[i].pb(i), mcv[i].pb(i);
    for (int i = 1; i <= m; ++i) {
        scanf("%s", qt);
        if (qt[0] == 'U') {
            scanf("%d%d", &x, &y), --x, --y;
            x = cm[x], y = cm[y];
            if (cv[x].size() < cv[y].size()) swap(x, y);
            LL delta = (upd[y].empty() ? 0ll : upd[y].back().second) - (upd[x].empty() ? 0ll : upd[x].back().second);
            for (int q : cv[y]) {
                cv[x].pb(q);
                cm[q] = x;
                t[q].pb(Triple(i, x, delta + (t[q].empty() ? 0ll : t[q].back().z)));
            }
        } else if (qt[0] == 'M') {
            scanf("%d%d", &x, &y), --x, --y;
            x = mcm[x], y = mcm[y];
            if (mcv[x].size() < mcv[y].size()) swap(x, y);
            for (int q : mcv[y]) {
                mcv[x].pb(q);
                mcm[q] = x;
                mt[q].pb(mp(i, x));
            }
        } else if (qt[0] == 'A') {
            scanf("%d", &x), --x;
            x = cm[x];
            upd[x].pb(mp(i, (int)cv[x].size() + (upd[x].empty() ? 0 : upd[x].back().second)));
        } else if (qt[0] == 'Z') {
            scanf("%d", &x), --x;
            x = mcm[x];
            mupd[x] = i;
        } else {
            scanf("%d", &x), --x;
            int ztime = 0;
            for (PII q : mt[x]) if (mupd[q.second] > q.first) {
                ztime = max(ztime, mupd[q.second]);
            }
            LL ans = t[x].back().z + (upd[t[x].back().y].empty() ? 0ll : upd[t[x].back().y].back().second);
            if (ztime) {
                int ind = 0;
                REP(j, t[x].size()) if (j == (int)t[x].size() - 1 || t[x][j + 1].x > ztime) {
                    ind = j;
                    break;
                }
                int pos = t[x][ind].y;
                int u = lower_bound(upd[pos].begin(), upd[pos].end(), mp(ztime, 0ll)) - upd[pos].begin() - 1;
                ans -= t[x][ind].z + ((u == -1) ? 0ll : upd[pos][u].second);
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}