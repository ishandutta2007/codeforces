#include <cstdio>
#include <cmath>
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

int n, m;
vector<int> e[30000];
int ans[30000], ansc = 0;
bool vis[30000] = {};

void dfs(int v) {
    vis[v] = true;
    REP(i, e[v].size())
        if (!vis[e[v][i]])
            dfs(e[v][i]);
    ans[ansc++] = v;
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
    }
    REP(i, n)
        if (!vis[i])
            dfs(i);
    REP(i, n)
        printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}