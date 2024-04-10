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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9;

int n, m;
int deg[15], sum, g[15][15];
bool vis[15] = {};
vector<int> unm;
int sz;
int ans = INF, cur = 0;

void dfs(int v) {
    vis[v] = true;
    REP(i, n) if (!vis[i] && g[v][i] != INF)
        dfs(i);
}

void go(int ind) {
    if (ind == sz) {
        ans = min(ans, cur);
        return;
    }
    if (vis[ind]) {
        go(ind + 1);
        return;
    }
    vis[ind] = true;
    for (int i = ind + 1; i < sz; ++i) if (!vis[i]) {
        vis[i] = true;
        cur += g[unm[ind]][unm[i]];
        go(ind + 1);
        cur -= g[unm[ind]][unm[i]];
        vis[i] = false;
    }
    vis[ind] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) REP(j, n)
        g[i][j] = (i == j) ? 0 : INF;
    REP(i, m) {
        int x, y, w;
        cin >> x >> y >> w, --x, --y;
        ++deg[x];
        ++deg[y];
        g[y][x] = g[x][y] = min(g[x][y], w);
        sum += w;
    }
    REP(k, n) REP(i, n) REP(j, n) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
    dfs(0);
    REP(i, n) if (deg[i] && !vis[i]) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, n) if (deg[i] & 1)
        unm.pb(i);
    sz = (int)unm.size();
    if (sz & 1) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, sz) vis[i] = false;
    if (sz) go(0);
    else ans = 0;
    cout << ans + sum << endl;
    return 0;
}