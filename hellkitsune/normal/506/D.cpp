#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>
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
vector<PII> e[100000];
int q;
int x[100000], y[100000], ans[100000] = {};
int par[100000], ra[100000];
unordered_map<LL, int> ma;
vector<int> v;

int findSet(int v) {
    if (v == par[v])
        return v;
    return par[v] = findSet(par[v]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (ra[a] < ra[b])
            swap(a, b);
        par[b] = a;
        if (ra[a] == ra[b])
            ++ra[a];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c), --a, --b, --c;
        e[c].pb(mp(a, b));
    }
    scanf("%d", &q);
    REP(i, q) {
        scanf("%d%d", x + i, y + i), --x[i], --y[i];
        if (x[i] > y[i]) swap(x[i], y[i]);
        ma[((LL)x[i] << 32) | y[i]] = 0;
    }
    REP(i, n) par[i] = i, ra[i] = 0;
    REP(i, m) if ((int)e[i].size() > 100) {
        for (PII x : e[i])
            unionSet(x.first, x.second);
        REP(j, q) if (findSet(x[j]) == findSet(y[j]))
            ++ans[j];
        for (PII x : e[i]) {
            par[x.first] = x.first;
            par[x.second] = x.second;
            ra[x.first] = ra[x.second] = 0;
        }
    }
    REP(i, m) if ((int)e[i].size() <= 100 && !e[i].empty()) {
        for (PII x : e[i])
            unionSet(x.first, x.second);
        v.clear();
        for (PII x : e[i]) v.pb(x.first), v.pb(x.second);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        REP(i, v.size()) for (int j = i + 1; j < (int)v.size(); ++j) if (findSet(v[i]) == findSet(v[j])) {
            auto it = ma.find(((LL)v[i] << 32) | v[j]);
            if (it != ma.end())
                ++it->second;
        }
        for (PII x : e[i]) {
            par[x.first] = x.first;
            par[x.second] = x.second;
            ra[x.first] = ra[x.second] = 0;
        }
    }
    REP(i, q) ans[i] += ma[((LL)x[i] << 32) | y[i]];
    REP(i, q) printf("%d\n", ans[i]);
    return 0;
}