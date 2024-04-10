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
vector<int> g[3000];
int d[3000][3000];
int s[2], t[2], l[2];
queue<int> q;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, 2) scanf("%d%d%d", s + i, t + i, l + i), --s[i], --t[i];
    REP(i, n) {
        REP(j, n) d[i][j] = -1;
        d[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) if (d[i][to] == -1) {
                d[i][to] = d[i][v] + 1;
                q.push(to);
            }
        }
    }
    int best = 0;
    REP(i, 2) {
        int cur = d[s[i]][t[i]];
        if (cur > l[i]) {
            printf("-1\n");
            return 0;
        }
        best += cur;
    }
    REP(i, n) REP(j, n) {
        bool ok = true;
        int tot = 0;
        REP(z, 2) {
            int cur = d[s[z]][i] + d[i][j] + d[j][t[z]];
            if (cur > l[z]) {
                ok = false;
                break;
            }
            tot += cur;
        }
        if (ok) best = min(best, tot - d[i][j]);
        ok = true;
        tot = 0;
        REP(z, 2) {
            int cur = z ? (d[s[z]][j] + d[i][j] + d[i][t[z]]) : (d[s[z]][i] + d[i][j] + d[j][t[z]]);
            if (cur > l[z]) {
                ok = false;
                break;
            }
            tot += cur;
        }
        if (ok) best = min(best, tot - d[i][j]);
    }
    printf("%d\n", m - best);
    return 0;
}