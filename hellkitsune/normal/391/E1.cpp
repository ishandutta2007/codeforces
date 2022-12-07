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

vector<int> g[3][1000];
int n[3];
LL sum[3][1000];
LL d[3][1000][1000];
int t, st, dist = 0;

void dfs(int v, int par) {
    d[t][st][v] = dist;
    sum[t][st] += dist;
    for (int to : g[t][v]) if (to != par) {
        ++dist;
        dfs(to, v);
        --dist;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 3) cin >> n[i];
    REP(i, 3) REP(j, n[i] - 1) {
        int from, to;
        cin >> from >> to, --from, --to;
        g[i][from].pb(to);
        g[i][to].pb(from);
    }
    for (t = 0; t < 3; ++t) for (st = 0; st < n[t]; ++st)
        dfs(st, -1);
    LL tot = 0;
    REP(t, 3) REP(i, n[t])
        tot += sum[t][i];
    tot /= 2;
    LL ans = tot;
    REP(mid, 3) {
        int l = 0, r = 2;
        if (mid == 0) l = 1;
        if (mid == 2) r = 1;
        LL bestL = 0;
        REP(i, n[l]) bestL = max(bestL, sum[l][i]);
        LL bestR = 0;
        REP(i, n[r]) bestR = max(bestR, sum[r][i]);
        LL cur = (bestL + n[l]) * (n[mid] + n[r]);
        cur += (bestR + n[r]) * (n[mid] + n[l]);
        LL bestMid = 0;
        REP(i, n[mid]) REP(j, n[mid])
            bestMid = max(bestMid, d[mid][i][j] * (n[l] * n[r]) + sum[mid][i] * n[l] + sum[mid][j] * n[r]);
        cur += bestMid;
        ans = max(ans, tot + cur);
    }
    cout << ans << endl;
    return 0;
}