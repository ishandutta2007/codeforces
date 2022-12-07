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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int x[500];
vector<PII> g[500];

int main() {
    scanf("%d%d", &n, &m);
    if (n == 1) cout << setprecision(15) << fixed << 0.0 << endl;
    else {
        REP(i, n) scanf("%d", x + i);
        REP(i, m) {
            int p, q, v;
            scanf("%d%d%d", &p, &q, &v), --p, --q;
            g[p].pb(mp(q, v));
            g[q].pb(mp(p, v));
        }
        double ans = 0;
        REP(i, n) REP(j, g[i].size()) {
            int to = g[i][j].first;
            ans = max(ans, (double)(x[i] + x[to]) / g[i][j].second);
        }
        cout << setprecision(15) << fixed << ans << endl;
    }
    return 0;
}