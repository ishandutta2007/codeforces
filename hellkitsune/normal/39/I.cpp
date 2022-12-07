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
vector<int> g[100000];
vector<int> ans, nans, pos;
int dist[100000];

void dfs(int v) {
    for (int to : g[v]) if (dist[to] == -1) {
        dist[to] = dist[v] + 1;
        dfs(to);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
    }
    for (int i = n; i >= 1; --i) ans.pb(i);
    REP(i, n) dist[i] = -1;
    dist[0] = 0;
    dfs(0);
    REP(v, n) if (dist[v] != -1) for (int to : g[v]) if (dist[to] != dist[v] + 1) {
        int a = dist[v];
        int b = dist[to];
        for (int x : ans) if ((a + 1) % x == b % x) {
            nans.pb(x);
        }
        ans = nans;
        nans.clear();
    }
    int best = ans[0];
    REP(v, n) if (dist[v] != -1) dist[v] %= best;
    REP(v, n) if (dist[v] == 0) {
        pos.pb(v + 1);
    }
    printf("%d\n%d\n", best, (int)pos.size());
    for (int x : pos) printf("%d ", x);
    printf("\n");
    return 0;
}