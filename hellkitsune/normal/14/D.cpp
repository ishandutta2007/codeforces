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

vector<int> g[200];
int ex[200], ey[200];
int n, ans = 0;
bool mark[200], vis[200];

void go(int v) {
    mark[v] = true;
    REP(i, g[v].size()) if (!mark[g[v][i]])
        go(g[v][i]);
}

int dfs(int v, int len) {
    vis[v] = true;
    int ret = len;
    REP(i, g[v].size()) {
        if (mark[g[v][i]] == mark[v] && !vis[g[v][i]])
            ret = max(ret, dfs(g[v][i], len + 1));
    }
    vis[v] = false;
    return ret;
}

int main() {
    cin >> n;
    REP(i, n - 1) {
        int x, y;
        cin >> x >> y, --x, --y;
        ex[i] = x, ey[i] = y;
        g[x].pb(y);
        g[y].pb(x);
    }
    REP(i, n - 1) {
        vector<int> &gx = g[ex[i]];
        vector<int> &gy = g[ey[i]];
        gx.erase(find(gx.begin(), gx.end(), ey[i]));
        gy.erase(find(gy.begin(), gy.end(), ex[i]));
        REP(j, n) mark[j] = false;
        go(ex[i]);
        int len1 = 0, len2 = 0;
        REP(j, n) {
            REP(k, n) vis[k] = false;
            if (mark[j])
                len1 = max(len1, dfs(j, 0));
            else
                len2 = max(len2, dfs(j, 0));
        }
        ans = max(ans, len1 * len2);
        gx.pb(ey[i]);
        gy.pb(ex[i]);
    }
    cout << ans << endl;
    return 0;
}