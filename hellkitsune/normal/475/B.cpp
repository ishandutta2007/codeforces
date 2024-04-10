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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

vector<int> g[400], rev[400];
int n, m, k;
string s;
vector<int> ord;
bool vis[400];

void dfs1(int v) {
    vis[v] = true;
    for (int to : g[v]) if (!vis[to])
        dfs1(to);
    ord.pb(v);
}

void dfs2(int v) {
    vis[v] = true;
    for (int to : rev[v]) if (!vis[to])
        dfs2(to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;
    REP(i, n) if (s[i] == '<') {
        REP(j, m - 1) g[i * m + j + 1].pb(i * m + j);
    } else {
        REP(j, m - 1) g[i * m + j].pb(i * m + j + 1);
    }
    cin >> s;
    REP(j, m) if (s[j] == 'v') {
        REP(i, n - 1) g[i * m + j].pb((i + 1) * m + j);
    } else {
        REP(i, n - 1) g[(i + 1) * m + j].pb(i * m + j);
    }
    k = n * m;
    REP(i, k) for (int to : g[i])
        rev[to].pb(i);
    REP(i, k) vis[i] = false;
    REP(i, k) if (!vis[i])
        dfs1(i);
    REP(i, k) vis[i] = false;
    dfs2(ord[k - 1]);
    REP(i, k) if (!vis[i]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}