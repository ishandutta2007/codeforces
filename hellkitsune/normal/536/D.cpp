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
int s, t;
int ord[2][2000], rev[2][2000];
LL dist[2][2000];
vector<PII> g[2000];
int p[2000];
LL *di = dist[0];
const LL INF = 1e18;

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (di[lhs] != di[rhs]) return di[lhs] < di[rhs];
        return lhs < rhs;
    }
};

inline bool cmp(const int &lhs, const int &rhs) {
    return di[lhs] < di[rhs];
}

set<int, Cmp> q;

void calcOrder(int s, int *ord, int *rev, LL *dist)
{
    di = dist;
    REP(i, n) dist[i] = INF;
    dist[s] = 0;
    q.insert(s);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII to : g[v]) if (dist[to.first] > dist[v] + to.second) {
            q.erase(to.first);
            dist[to.first] = dist[v] + to.second;
            q.insert(to.first);
        }
    }
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) rev[ord[i]] = i;
}

LL d[2001][2001][2] = {};
LL mx[2001] = {}, mn[2001] = {};
LL pot[2][2001][2001];

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t), --s, --t;
    REP(i, n) scanf("%d", p + i);
    REP(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        g[from].pb(mp(to, w));
        g[to].pb(mp(from, w));
    }
    calcOrder(s, ord[0], rev[0], dist[0]);
    calcOrder(t, ord[1], rev[1], dist[1]);
    REP(i, n + 1) pot[0][i][n] = pot[1][i][n] = 0;
    REP(z, 2) REP(i, n + 1) for (int j = n - 1; j >= 0; --j) {
        pot[z][i][j] = pot[z][i][j + 1];
        if (rev[z ^ 1][ord[z][j]] >= i) {
            pot[z][i][j] += p[ord[z][j]];
        }
    }
    for (int i = n - 1; i >= 0; --i) for (int j = n - 1; j >= 0; --j) {
        //d[i][j][0] = maximize d[i + k][j][1] + pot[0][j][i] - pot[0][j][i + k];
        //d[i][j][1] = minimize d[i][j + k][0] - pot[1][i][j] + pot[1][i][j + k];
        if (rev[1][ord[0][i]] < j) {
            d[i][j][0] = d[i + 1][j][0];
            d[i][j][1] = d[i + 1][j][1];
        } else if (rev[0][ord[1][j]] < i) {
            d[i][j][0] = d[i][j + 1][0];
            d[i][j][1] = d[i][j + 1][1];
        } else {
            d[i][j][0] = mx[j] + pot[0][j][i];
            d[i][j][1] = mn[i] - pot[1][i][j];
        }
        if (j == n - 1 || dist[1][ord[1][j]] != dist[1][ord[1][j + 1]]) mn[i] = min(mn[i], d[i][j][0] + pot[1][i][j]);
        if (i == n - 1 || dist[0][ord[0][i]] != dist[0][ord[0][i + 1]]) mx[j] = max(mx[j], d[i][j][1] - pot[0][j][i]);
    }
    if (d[0][0][0] > 0) printf("Break a heart\n");
    else if (d[0][0][0] == 0) printf("Flowers\n");
    else printf("Cry\n");
    return 0;
}