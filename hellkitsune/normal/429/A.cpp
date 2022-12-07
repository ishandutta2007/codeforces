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

int n;
vector<int> e[100000], nxt[2][100000];
int goal[100000];
int dep[100000];
bool vis[100000] = {};
int ans[100000], ansc = 0;

void dfs(int v, int d) {
    vis[v] = true;
    dep[d] = v;
    if (d > 1)
        nxt[d & 1][dep[d - 2]].pb(v);
    REP(i, e[v].size())
        if (!vis[e[v][i]])
            dfs(e[v][i], d + 1);
}

int x;
void dfs2(int v, int ch) {
    if (goal[v] ^ ch) {
        ans[ansc++] = v;
        REP(i, nxt[x][v].size())
            dfs2(nxt[x][v][i], ch ^ 1);
    } else {
        REP(i, nxt[x][v].size())
            dfs2(nxt[x][v][i], ch);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    REP(i, n) scanf("%d", goal + i);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        goal[i] ^= x;
    }
    dfs(0, 0);
    x = 0;
    dfs2(0, 0);
    x = 1;
    REP(i, e[0].size())
        dfs2(e[0][i], 0);
    printf("%d\n", ansc);
    REP(i, ansc)
        printf("%d\n", ans[i] + 1);
    return 0;
}