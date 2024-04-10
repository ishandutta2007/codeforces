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
int f[100000];
vector<int> g[100000], rev[100000];
bool vis1[100000], vis2[100000];

void dfs1(int v) {
    vis1[v] = true;
    for (int to : g[v]) if (!vis1[to])
        dfs1(to);
}

void dfs2(int v) {
    vis2[v] = true;
    if (f[v] == 1) return;
    for (int to : rev[v]) if (!vis2[to])
        dfs2(to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> f[i];
    REP(i, m) {
        int from, to;
        cin >> from >> to, --from, --to;
        g[from].pb(to);
        rev[to].pb(from);
    }
    REP(i, n) vis1[i] = false;
    REP(i, n) if (!vis1[i] && f[i] == 1)
        dfs1(i);
    REP(i, n) vis2[i] = false;
    REP(i, n) if (!vis2[i] && f[i] == 2)
        dfs2(i);
    REP(i, n) if (vis1[i] && vis2[i])
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}