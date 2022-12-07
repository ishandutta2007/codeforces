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
    int to, f, cap, rev;
    E(int to, int f, int cap, int rev) : to(to), f(f), cap(cap), rev(rev) {}
    E() {}
};

int n, a[200];
bool pr[100000];
vector<E> g[205];
vector<int> od, ev;
const int S = 200, T = 201;
bool vis[205];
vector<int> gg[200];
vector<int> comp;
vector<vector<int> > comps;

void addEdge(int from, int to, int cap) {
    g[from].pb(E(to, 0, cap, (int)g[to].size()));
    g[to].pb(E(from, 0, 0, (int)g[from].size() - 1));
}

int flow(int v, int f) {
    if (v == T) return f;
    vis[v] = true;
    for (E &e : g[v]) if (e.f < e.cap && !vis[e.to]) {
        int df = flow(e.to, min(f, e.cap - e.f));
        if (df == 0) continue;
        e.f += df;
        g[e.to][e.rev].f -= df;
        return df;
    }
    return 0;
}

void dfs(int v) {
    vis[v] = true;
    comp.pb(v);
    for (int to : gg[v]) if (!vis[to])
        dfs(to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, 100000) pr[i] = true;
    for (int i = 2; i < 1000; ++i) if (pr[i]) {
        for (int j = i * i; j < 100000; j += i)
            pr[j] = false;
    }
    REP(i, n) if (a[i] & 1) od.pb(i);
    else ev.pb(i);
    if (ev.size() != od.size()) {
        cout << "Impossible\n";
        return 0;
    }
    n /= 2;
    REP(i, n) REP(j, n) if (pr[a[od[i]] + a[ev[j]]])
        addEdge(i, n + j, 1);
    REP(i, n) addEdge(S, i, 2);
    REP(i, n) addEdge(n + i, T, 2);
    int curFlow = 0;
    while (true) {
        REP(i, 202) vis[i] = false;
        int d = flow(S, 1000);
        if (d == 0)
            break;
        curFlow += d;
    }
    if (curFlow != 2 * n) {
        cout << "Impossible\n";
        return 0;
    }
    REP(i, n) REP(j, (int)g[i].size() - 1) if (g[i][j].f > 0) {
        int jj = g[i][j].to - n;
        gg[od[i]].pb(ev[jj]);
        gg[ev[jj]].pb(od[i]);
    }
    n *= 2;
    REP(i, n) assert((int)gg[i].size() == 2);
    REP(i, n) vis[i] = false;
    REP(i, n) if (!vis[i]) {
        dfs(i);
        comps.pb(comp);
        comp.clear();
    }
    cout << (int)comps.size() << '\n';
    for (vector<int> &x : comps) {
        cout << (int)x.size();
        for (int y : x) cout << ' ' << y + 1;
        cout << '\n';
    }
    return 0;
}