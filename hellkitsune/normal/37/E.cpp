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
char s[50][55];
vector<int> g[2500], ng[2500];
int par[2500], ra[2500];

int dsuParent(int v) {
    if (par[v] == v) return v;
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

void dsuInit(int n) {
    REP(i, n) par[i] = i, ra[i] = 1;
}

int dist[2500];
queue<int> q;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    dsuInit(n * m);
    REP(i, n - 1) REP(j, m) if (s[i][j] == s[i + 1][j]) {
        dsuMerge(i * m + j, (i + 1) * m + j);
    } else {
        g[i * m + j].pb((i + 1) * m + j);
        g[(i + 1) * m + j].pb(i * m + j);
    }
    REP(i, n) REP(j, m - 1) if (s[i][j] == s[i][j + 1]) {
        dsuMerge(i * m + j, i * m + j + 1);
    } else {
        g[i * m + j].pb(i * m + j + 1);
        g[i * m + j + 1].pb(i * m + j);
    }
    REP(i, n * m) {
        int ii = dsuParent(i);
        for (int to : g[i]) {
            int jj = dsuParent(to);
            if (jj != ii) {
                ng[ii].pb(jj);
            }
        }
    }
    int ans = 1234566;
    n *= m;
    REP(i, n) if (dsuParent(i) == i) {
        REP(j, n) dist[j] = -1;
        dist[i] = 0;
        q.push(i);
        int mx = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : ng[v]) if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                mx = max(mx, dist[to]);
                q.push(to);
            }
        }
        int tmp;
        if (s[i / m][i % m] == 'W') tmp = 0;
        else tmp = 1;
        tmp = (tmp + mx) % 2;
        mx += tmp;
        ans = min(ans, mx);
    }
    printf("%d\n", ans);
    return 0;
}