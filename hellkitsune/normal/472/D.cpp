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

struct E {
    int from, to, w;
};

int n;
int d[2000][2000];
int dist[2000];
bool used[2000] = {};
vector<PII> g[2000];
int V;

bool dfs(int v, int par = -1, int cur = 0) {
    for (PII to : g[v]) if (to.first != par) {
        if (cur + to.second != d[V][to.first]) return false;
        if (!dfs(to.first, v, cur + to.second)) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    REP(i, n) REP(j, n) {
        scanf("%d", d[i] + j);
    }
    REP(i, n) if (d[i][i] != 0) {
        printf("NO\n");
        return 0;
    }
    REP(i, n) REP(j, n) if (i != j && d[i][j] == 0) {
        printf("NO\n");
        return 0;
    }
    REP(i, n) for (int j = i + 1; j < n; ++j) if (d[i][j] != d[j][i]) {
        printf("NO\n");
        return 0;
    }
    REP(i, n) dist[i] = d[0][i];
    used[0] = true;
    for (int i = 1; i < n; ++i) {
        int v = -1;
        REP(j, n) if (!used[j] && (v == -1 || dist[j] < dist[v]))
            v = j;
        int from = -1;
        REP(j, n) if (used[j] && dist[v] == d[v][j]) {
            from = j;
            break;
        }
        assert(from != -1);
        V = v;
        g[v].pb(mp(from, dist[v]));
        g[from].pb(mp(v, dist[v]));
        if (!dfs(v)) {
            cout << "NO\n";
            return 0;
        }
        REP(i, n) dist[i] = min(dist[i], d[v][i]);
        used[v] = true;
    }
    cout << "YES\n";
    return 0;
}