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
vector<int> g[1000];
int best[1000];
queue<int> q;
int d[1000];
vector<int> ver;
bool vis[1000];
int ans = 0;

void solve(int v) {
    ver.clear();
    ver.pb(v);
    REP(i, n) d[i] = -1;
    d[v] = 0;
    q.push(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : g[cur]) if (d[to] == -1) {
            d[to] = d[cur] + 1;
            q.push(to);
            ver.pb(to);
        }
    }
    int mn = v;
    for (int x : ver) mn = min(mn, x);
    for (int x : ver) for (int to : g[x]) if (abs(d[x] - d[to]) != 1)
        return;
    int ans = 0;
    for (int x : ver) ans = max(ans, d[x]);
    best[mn] = max(best[mn], ans);
}

void dfs(int v) {
    vis[v] = true;
    for (int to : g[v]) if (!vis[to]) {
        dfs(to);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, n) best[i] = -1;
    REP(i, n) solve(i);
    REP(i, n) vis[i] = false;
    REP(i, n) if (!vis[i]) {
        dfs(i);
        if (best[i] == -1) {
            printf("-1\n");
            return 0;
        }
        ans += best[i];
    }
    printf("%d\n", ans);
    return 0;
}