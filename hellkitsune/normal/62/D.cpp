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
vector<int> g[100];
int ord[3003];
bool vis[100];
int pos[100] = {};
int deg[100] = {};

int getHash(int u, int v) {
    return (min(u, v) << 7) | max(u, v);
}

void dfs(int v, int p) {
    vis[v] = true;
    for (int to : g[v]) if (to != p && !vis[to]) {
        dfs(to, v);
    }
}

void eraseEdge(int x, int y) {
    g[x].erase(find(g[x].begin(), g[x].end(), y));
    g[y].erase(find(g[y].begin(), g[y].end(), x));
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m + 1) scanf("%d", ord + i), --ord[i];
    for (int i = m - 1; i >= 0; --i) {
        int from = ord[i];
        int to = ord[i + 1];
        g[from].pb(to);
        g[to].pb(from);
        int p = -1;
        if (i) p = ord[i - 1];
        sort(g[from].begin(), g[from].end());
        for (int x : g[from]) if (x > to && x != p) {
            REP(j, n) vis[j] = g[j].empty();
            dfs(x, from);
            bool ok = true;
            vis[from] = true;
            REP(j, n) if (!vis[j]) {
                ok = false;
                break;
            }
            if (!ok) continue;
            ord[i + 1] = x;
            eraseEdge(from, x);
            REP(j, n) sort(g[j].begin(), g[j].end());
            REP(j, n) deg[j] = (int)g[j].size();
            for (int j = i + 2; j <= m; ++j) ord[j] = -2;
            for (i += 2; i <= m; ++i) {
                for (int y : g[x]) {
                    REP(j, n) vis[j] = deg[j] == 0;
                    dfs(y, x);
                    vis[x] = true;
                    bool ok = true;
                    REP(j, n) if (!vis[j]) {
                        ok = false;
                        break;
                    }
                    if (!ok) continue;
                    eraseEdge(x, y);
                    --deg[x];
                    --deg[y];
                    ord[i] = x = y;
                    break;
                }
            }
            REP(j, m + 1) printf("%d ", ord[j] + 1);
            printf("\n");
            return 0;
        }
    }
    printf("No solution\n");
    return 0;
}