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

vector<int> g[60000];
int n, r1, r2;
int par[60000];

void dfs(int v, int p) {
    par[v] = p;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
    }
}

int main() {
    scanf("%d%d%d", &n, &r1, &r2), --r1, --r2;
    for (int i = 0; i < n; ++i) {
        if (i == r1) continue;
        int x;
        scanf("%d", &x), --x;
        g[x].pb(i);
        g[i].pb(x);
    }
    dfs(r2, -1);
    REP(i, n) if (par[i] != -1)
        printf("%d ", par[i] + 1);
    printf("\n");
    return 0;
}