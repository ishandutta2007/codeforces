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

int n, m, k, w;
char s[1000][10][12];
vector<PII> d[101];
int c[1000];
vector<int> e[1000];
bool vis[1000];

void dfs(int v, int prev) {
    vis[v] = true;
    printf("%d %d\n", v + 1, prev + 1);
    REP(i, e[v].size()) if (!vis[e[v][i]])
        dfs(e[v][i], v);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &w);
    REP(i, k) REP(j, n)
        scanf("%s", s[i][j]);
    REP(i1, k - 1) for (int i2 = i1 + 1; i2 < k; ++i2) {
        int dif = 0;
        REP(i, n) REP(j, m)
            dif += s[i1][i][j] != s[i2][i][j];
        d[dif].pb(mp(i1, i2));
    }
    REP(i, k)
        c[i] = i;
    int ans = n * m * k;
    for (int i = 0; i <= n * m; ++i) {
        if (i * w >= n * m)
            break;
        REP(j, d[i].size()) {
            if (c[d[i][j].first] != c[d[i][j].second]) {
                e[d[i][j].first].pb(d[i][j].second);
                e[d[i][j].second].pb(d[i][j].first);
                int tmp = c[d[i][j].second];
                REP(p, k) if (c[p] == tmp)
                    c[p] = c[d[i][j].first];
                ans += i * w - n * m;
            }
        }
    }
    printf("%d\n", ans);
    REP(i, k)
        vis[i] = false;
    REP(i, k) if (!vis[i])
        dfs(i, -1);
    return 0;
}