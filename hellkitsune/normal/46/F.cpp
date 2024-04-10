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
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int from[1000], to[1000];
map<string, int> ma;
int mac = 0;

char s[1005];

int getHash(string s) {
    auto it = ma.find(s);
    if (it == ma.end()) {
        ma[s] = mac;
        return mac++;
    }
    return it->second;
}

struct State {
    vector<int> pp[1000], ke[1000];
    int krn[1000], prn[1000];
    int par[1000], num[1000];

    bool closed[1000];

    int dsuParent(int v) {
        if (v == par[v]) return v;
        return par[v] = dsuParent(par[v]);
    }

    void dsuMerge(int u, int v) {
        u = dsuParent(u);
        v = dsuParent(v);
        if (u == v) return;
        if (pp[u].size() + ke[u].size() < pp[v].size() + ke[v].size()) {
            swap(u, v);
        }
        par[v] = u;
        for (int x : pp[v]) {
            pp[u].pb(x);
            prn[x] = u;
        }
        pp[v].clear();
        for (int x : ke[v]) {
            ke[u].pb(x);
            krn[x] = u;
        }
        ke[v].clear();
    }

    void solve() {
        REP(i, m) krn[i] = -1;
        REP(i, n) par[i] = i;
        REP(i, k) {
            int rn, kcnt;
            scanf("%s%d%d", s, &rn, &kcnt), --rn;
            int cur = getHash(string(s));
            pp[rn].pb(cur);
            prn[cur] = rn;
            REP(j, kcnt) {
                int x;
                scanf("%d", &x), --x;
                ke[rn].pb(x);
                krn[x] = rn;
            }
        }
        REP(i, m) closed[i] = true;
        while (true) {
            bool done = true;
            REP(i, m) if (closed[i] && (krn[i] == dsuParent(from[i]) || krn[i] == dsuParent(to[i]))) {
                closed[i] = false;
                done = false;
                dsuMerge(from[i], to[i]);
            }
            if (done) break;
        }
        REP(i, n) num[i] = -1;
        REP(i, n) {
            int ii = dsuParent(i);
            num[ii] = max(num[ii], i);
        }
    }
};

State state1, state2;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) scanf("%d%d", from + i, to + i), --from[i], --to[i];
    state1.solve();
    state2.solve();
    bool ok = true;
    REP(i, n) if (state1.num[state1.dsuParent(i)] != state2.num[state2.dsuParent(i)]) {
        ok = false;
        break;
    }
    if (ok) REP(i, m) if (state1.num[state1.krn[i]] != state2.num[state2.krn[i]]) {
        ok = false;
        break;
    }
    if (ok) REP(i, k) if (state1.num[state1.prn[i]] != state2.num[state2.prn[i]]) {
        ok = false;
        break;
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}