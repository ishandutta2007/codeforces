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

int h, t, r;
int n, m;
int hh[201], ht[201], th[201], tt[201];
vector<int> g[41000];
bool canLose[41000];

int dist[41000];
queue<int> q;
bool hasCycle = false;
int ord[41000], ordc = 0, rev[41000];
int vis[41000] = {};
int d[41000];

void dfs(int v) {
    vis[v] = 1;
    for (int to : g[v]) if (vis[to] == 0) {
        dfs(to);
    } else if (vis[to] == 1) {
        printf("Draw\n");
        exit(0);
    }
    vis[v] = 2;
    ord[ordc++] = v;
}

int main() {
    scanf("%d%d%d", &h, &t, &r);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", hh + i, ht + i);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) scanf("%d%d", th + i, tt + i);
    ++r;
    REP(i, r) REP(j, r) {
        int mn = min(n, i);
        for (int ii = 1; ii <= mn; ++ii) {
            int newI = i - ii + hh[ii];
            int newJ = j + ht[ii];
            if (newI + newJ >= r) {
                canLose[i * r + j] = true;
            } else {
                g[i * r + j].pb(newI * r + newJ);
            }
        }
        mn = min(m, j);
        for (int jj = 1; jj <= mn; ++jj) {
            int newI = i + th[jj];
            int newJ = j - jj + tt[jj];
            if (newI + newJ >= r) {
                canLose[i * r + j] = true;
            } else {
                g[i * r + j].pb(newI * r + newJ);
            }
        }
    }
    REP(i, r * r) dist[i] = -1;
    q.push(h * r + t);
    dist[h * r + t] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) if (dist[to] == -1) {
            dist[to] = dist[v] + 1;
            q.push(to);
        }
    }
    if (dist[0] != -1) {
        printf("Ivan\n%d\n", dist[0]);
        return 0;
    }
    dfs(h * r + t);
    reverse(ord, ord + ordc);
    REP(i, ordc) rev[ord[i]] = i;
    int st = rev[h * r + t];
    REP(i, ordc) d[i] = -1;
    d[st] = 0;
    int ans = 1;
    for (int i = st; i < ordc; ++i) if (d[i] >= 0) {
        for (int to : g[ord[i]]) {
            d[rev[to]] = max(d[rev[to]], d[i] + 1);
            if (canLose[to]) {
                ans = max(ans, d[i] + 2);
            }
        }
    }
    printf("Zmey\n%d\n", ans);
    return 0;
}