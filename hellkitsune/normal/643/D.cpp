#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
LL t[100000];
int par[100000];
LL a[100000] = {}, b[100000] = {};
int deg[100000] = {};
const LL INF = 2e18;

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (a[lhs] != a[rhs]) return a[lhs] < a[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> ch[100000];
LL mn[100000], mx[100000];

struct CmpMn {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (mn[lhs] != mn[rhs]) return mn[lhs] < mn[rhs];
        return lhs < rhs;
    }
};

struct CmpMx {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (mx[lhs] != mx[rhs]) return mx[lhs] > mx[rhs];
        return lhs < rhs;
    }
};

set<int, CmpMn> gmn;
set<int, CmpMx> gmx;

void recalc(int v) {
    gmn.erase(v);
    gmx.erase(v);
    if (ch[v].empty()) {
        mn[v] = INF;
        mx[v] = -INF;
    } else {
        int ind = *ch[v].begin();
        mn[v] = a[ind] + b[par[ind]];
        ind = *ch[v].rbegin();
        mx[v] = a[ind] + b[par[ind]];
    }
    gmn.insert(v);
    gmx.insert(v);
}

void changeDegree(int v, int chind, int dif) {
    deg[v] += dif;
    ch[par[par[v]]].erase(par[v]);
    a[par[v]] -= b[v];
    b[v] = t[v] / (deg[v] + 2);
    a[par[v]] += b[v];
    ch[par[par[v]]].insert(par[v]);
    ch[par[v]].erase(v);
    a[v] += (deg[v] + 1 - dif) * (t[v] / (deg[v] + 2 - dif)) - (deg[v] + 1) * (t[v] / (deg[v] + 2));
    a[v] += dif * b[chind];
    ch[par[v]].insert(v);
    recalc(v);
    recalc(par[v]);
    recalc(par[par[v]]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    REP(i, n) scanf("%I64d", t + i);
    REP(i, n) scanf("%d", par + i), --par[i];
    REP(i, n) ++deg[par[i]];
    REP(i, n) {
        a[i] += t[i] - (deg[i] + 1) * (t[i] / (deg[i] + 2));
        b[i] = t[i] / (deg[i] + 2);
        a[par[i]] += b[i];
    }
    REP(i, n) ch[par[i]].insert(i);
    REP(i, n) recalc(i);
    REP(qq, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int v, parV;
            scanf("%d%d", &v, &parV), --v, --parV;
            ch[par[v]].erase(v);
            ch[parV].insert(v);
            int oldPar = par[v];
            par[v] = parV;
            changeDegree(oldPar, v, -1);
            changeDegree(parV, v, 1);
        } else if (qt == 2) {
            int v;
            scanf("%d", &v), --v;
            printf("%I64d\n", a[v] + b[par[v]]);
        } else {
            printf("%I64d %I64d\n", mn[*gmn.begin()], mx[*gmx.begin()]);
        }
    }
    return 0;
}