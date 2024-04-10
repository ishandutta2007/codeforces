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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
PII p[20][100000];
int c[100000] = {};
int q[100000], qt[100000], qc = 0, ec = 0;
PII qu[100000];
int quc = 0;
vector<int> g[100000];
int tin[100000], tout[100000], curt = 0;

void dfs(int v) {
    tin[v] = ++curt;
    for (int to : g[v])
        dfs(to);
    tout[v] = ++curt;
}

inline bool par(int vp, int v) {
    return tin[vp] <= tin[v] && tout[vp] >= tout[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x >> y, --x, --y;
            p[0][x] = mp(y, ec++);
            c[x] = 1;
            g[y].pb(x);
        } else if (t == 2) {
            cin >> x, --x;
            q[qc] = x;
            qt[qc++] = ec - 1;
        } else {
            cin >> x >> y, --x, --y;
            qu[quc++] = mp(x, y);
        }
    }
    REP(i, n) if (c[i] == 0)
        dfs(i);
    for (int i = 1; i < 20; ++i) {
        REP(j, n) if (c[j] == i && c[p[i - 1][j].first] == i) {
            p[i][j] = mp(p[i - 1][p[i - 1][j].first].first, max(p[i - 1][j].second, p[i - 1][p[i - 1][j].first].second));
            ++c[j];
        }
    }
    REP(i, quc) {
        if (!par(qu[i].first, q[qu[i].second])) {
            cout << "NO\n";
            continue;
        }
        int cur = -1, x = q[qu[i].second];
        while (x != qu[i].first) {
            int ind = c[x] - 1;
            while (!par(qu[i].first, p[ind][x].first))
                --ind;
            cur = max(cur, p[ind][x].second);
            x = p[ind][x].first;
        }
        if (qt[qu[i].second] < cur)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}