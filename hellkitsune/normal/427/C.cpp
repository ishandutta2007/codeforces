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

vector<int> e[100000], e2[100000];
vector<bool> vis;
int c[100000], cc, val[100000];
int n, m;
int ord[100000], ordc = 0;

const int mod = 1e9 + 7;

void dfs1(int v) {
    vis[v] = true;
    REP(i, e[v].size())
        if (!vis[e[v][i]])
            dfs1(e[v][i]);
    ord[ordc++] = v;
}

void dfs2(int v) {
    vis[v] = true;
    c[cc++] = v;
    REP(i, e2[v].size())
        if (!vis[e2[v][i]])
            dfs2(e2[v][i]);
}

int main() {
    scanf("%d", &n);
    REP(i, n)
        scanf("%d", val + i);
    scanf("%d", &m);
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e2[y].pb(x);
    }
    vis.assign(n, false);
    REP(i, n) if (!vis[i])
        dfs1(i);
    vis.assign(n, false);
    LL mincost = 0;
    LL anscnt = 1;
    REP(i, n) {
        int v = ord[n - 1 - i];
        if (!vis[v]) {
            cc = 0;
            dfs2(v);
            int mn = val[c[0]], mnc = 1;
            for (int j = 1; j < cc; ++j) {
                if (val[c[j]] < mn) {
                    mn = val[c[j]];
                    mnc = 1;
                } else if (val[c[j]] == mn)
                    ++mnc;
            }
            mincost += mn;
            anscnt = (anscnt * mnc) % mod;
        }
    }
    cout << mincost << ' ' << anscnt << endl;
    return 0;
}