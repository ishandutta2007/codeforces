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
int a[100000];
vector<int> g[100000];
int ans = 0;

void dfs(int v, int cats, int p) {
    if (a[v]) ++cats;
    else cats = 0;
    if (cats > m) return;
    if ((int)g[v].size() == 1 && v != 0) ++ans;
    for (int to : g[v]) if (to != p) {
        dfs(to, cats, v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, 0, -1);
    printf("%d\n", ans);
    return 0;
}