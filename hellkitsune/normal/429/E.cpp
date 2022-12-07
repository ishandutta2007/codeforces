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

int n, N;
int x[100001], y[100001], col[200001];
vector<PII> g[200001];
set<int> se;
map<int, int> ma;
int mac = 0;
bool used[200001] = {};
int pos[200001] = {};

void dfs(int v) {
    for (int &i = pos[v]; i < (int)g[v].size(); ++i) {
        PII &e = g[v][i];
        if (used[e.second]) continue;
        used[e.second] = true;
        col[e.second] = e.first > v;
        dfs(e.first);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i), ++y[i];
    REP(i, n) se.insert(x[i]), se.insert(y[i]);
    for (int x : se) ma[x] = mac++;
    REP(i, n) x[i] = ma[x[i]], y[i] = ma[y[i]];
    REP(i, n) {
        g[x[i]].pb(mp(y[i], i));
        g[y[i]].pb(mp(x[i], i));
    }
    int pre = -1;
    N = n;
    REP(i, mac) if ((int)g[i].size() % 2 == 1) {
        if (pre == -1) {
            pre = i;
        } else {
            g[i].pb(mp(pre, N));
            g[pre].pb(mp(i, N));
            ++N;
            pre = -1;
        }
    }
    REP(i, mac) dfs(i);
    REP(i, n) printf("%d ", col[i]);
    printf("\n");
    return 0;
}