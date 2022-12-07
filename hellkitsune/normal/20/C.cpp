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
vector<PII> g[100000];
LL d[100000];
int p[100000];

const LL INF = 1e18;

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (d[lhs] == d[rhs]) return lhs < rhs;
        return d[lhs] < d[rhs];
    }
};

set<int, Cmp> q;

vector<int> ans;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w), --x, --y;
        g[x].pb(mp(y, w));
        g[y].pb(mp(x, w));
    }
    REP(i, n) d[i] = INF;
    d[0] = 0;
    q.insert(0);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII to : g[v]) if (d[v] + to.second < d[to.first]) {
            q.erase(to.first);
            d[to.first] = d[v] + to.second;
            p[to.first] = v;
            q.insert(to.first);
        }
    }
    if (d[n - 1] == INF) {
        printf("-1\n");
        return 0;
    }
    ans.pb(n);
    int v = n - 1;
    while (v != 0) {
        v = p[v];
        ans.pb(v + 1);
    }
    for (int i = (int)ans.size() - 1; i >= 0; --i) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}