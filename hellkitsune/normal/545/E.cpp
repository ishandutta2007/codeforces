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
vector<PII> g[300000];
map<PII, int> ma;
LL d[300000];
int p[300000], pw[300000];

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (d[lhs] != d[rhs]) return d[lhs] < d[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

LL ans = 0;
vector<int> edges;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        g[from].pb(mp(to, w));
        g[to].pb(mp(from, w));
        ma[mp(from, to)] = i + 1;
        ma[mp(to, from)] = i + 1;
    }
    int st;
    scanf("%d", &st), --st;
    REP(i, n) d[i] = 1e18;
    d[st] = 0;
    q.insert(st);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII e : g[v]) if (d[e.first] > d[v] + e.second) {
            q.erase(e.first);
            d[e.first] = d[v] + e.second;
            p[e.first] = v;
            pw[e.first] = e.second;
            q.insert(e.first);
        }
    }
    REP(v, n) for (PII e : g[v]) if (e.first != st && d[e.first] == d[v] + e.second && e.second < pw[e.first]) {
        p[e.first] = v;
        pw[e.first] = e.second;
    }
    REP(v, n) if (v != st) {
        ans += pw[v];
        edges.pb(ma[mp(v, p[v])]);
    }
    printf("%I64d\n", ans);
    for (int x : edges) printf("%d ", x);
    printf("\n");
    return 0;
}