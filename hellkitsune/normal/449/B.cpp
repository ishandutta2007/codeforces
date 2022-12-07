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

struct E {
    int to, w;
    bool rr;
    E(int to = 0, int w = 0, bool rr = false) : to(to), w(w), rr(rr) {}
};

int n, m, k;
vector<E> g[100000];
LL d[100000];
int ans = 0;
int deg[100000] = {};

const LL INF = 1e18;

class cmp {
    public:
    bool operator()(const int &lhs, const int &rhs) {
        if (d[lhs] == d[rhs]) return lhs < rhs;
        return d[lhs] < d[rhs];
    }
};

set<int, cmp> q;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w), --x, --y;
        g[x].pb(E(y, w));
        g[y].pb(E(x, w));
    }
    REP(i, k) {
        int y, w;
        scanf("%d%d", &y, &w), --y;
        g[0].pb(E(y, w, true));
    }
    REP(i, n) d[i] = INF;
    d[0] = 0;
    q.insert(0);
    while (!q.empty()) {
        int v = *(q.begin());
        q.erase(q.begin());
        for (E &to : g[v]) if (d[v] + to.w < d[to.to]) {
            q.erase(to.to);
            d[to.to] = d[v] + to.w;
            q.insert(to.to);
        }
    }
    REP(i, n) {
        int del = 0;
        REP(j, g[i].size()) if (d[i] + g[i][j].w == d[g[i][j].to]) {
            g[i][j - del] = g[i][j];
            ++deg[g[i][j].to];
        } else {
            ++del;
            if (g[i][j].rr) ++ans;
        }
        g[i].resize(g[i].size() - del);
    }
    for (E to : g[0]) if (to.rr && deg[to.to] > 1) {
        ++ans;
        --deg[to.to];
    }
    printf("%d\n", ans);
    return 0;
}