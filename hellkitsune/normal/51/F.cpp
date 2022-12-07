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
vector<int> og[2000], g[2000];
int timer = 0, tin[2000], fup[2000];
int par[2000], ra[2000];

void dsuInit() {
    REP(i, n) par[i] = i, ra[i] = 1;
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
}

void dfs(int v, int p) {
    tin[v] = fup[v] = timer++;
    for (int to : og[v]) if (to != p) {
        if (tin[to] == -1) {
            dfs(to, v);
            if (fup[to] <= tin[v]) {
                dsuMerge(v, to);
            }
            fup[v] = min(fup[v], fup[to]);
        } else {
            fup[v] = min(fup[v], tin[to]);
        }
    }
}

vector<int> ver, ver2;

void dfs2(int v, int p) {
    ver.pb(v);
    tin[v] = 1;
    for (int to : g[v]) if (to != p) {
        dfs2(to, v);
    }
}

int best;
int dist[2000];
void dfs3(int v, int p) {
    if (p == -1) {
        dist[v] = 0;
    } else {
        dist[v] = dist[p] + 1;
    }
    if (dist[v] > dist[best]) {
        best = v;
    }
    for (int to : g[v]) if ((int)g[to].size() > 1 && to != p) {
        dfs3(to, v);
    }
}
int ans = 0;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        og[from].pb(to);
        og[to].pb(from);
    }
    dsuInit();
    REP(i, n) tin[i] = -1;
    REP(i, n) if (tin[i] == -1) {
        dfs(i, -1);
    }
    REP(i, n) {
        int ii = dsuParent(i);
        for (int to : og[i]) {
            int jj = dsuParent(to);
            if (ii != jj) {
                g[ii].pb(jj);
            }
        }
    }
    REP(i, n) tin[i] = -1;
    bool frst = true;
    REP(i, n) if (dsuParent(i) == i && tin[i] == -1) {
        dfs2(i, -1);
        int cur = 0;
        for (int v : ver) if ((int)g[v].size() > 1) {
            ver2.pb(v);
        } else {
            ++cur;
        }
        if (!ver2.empty()) {
            best = ver2[0];
            dfs3(ver2[0], -1);
            dfs3(best, -1);
            cur += dist[best] + 1;
        }
        ver.clear();
        ver2.clear();
        if (frst) {
            ans = cur;
            frst = false;
        } else {
            ans += cur - 1;
        }
    }
    cout << n - ans << endl;
    return 0;
}