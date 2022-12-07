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

int n;
int a[100];
vector<int> g[100];
bool vis[100];

void dfs(int v) {
    vis[v] = true;
    for (int to : g[v]) if (!vis[to])
        dfs(to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i], --a[i];
    REP(i, n) {
        int x;
        cin >> x;
        if (i - x >= 0) g[i].pb(i - x), g[i - x].pb(i);
        if (i + x < n) g[i].pb(i + x), g[i + x].pb(i);
    }
    REP(i, n) {
        REP(j, n) vis[j] = false;
        dfs(i);
        if (!vis[a[i]]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}