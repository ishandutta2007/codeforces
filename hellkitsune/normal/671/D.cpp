#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[300000];
int dep[300000];
vector<PII> x[300000];
set<pair<LL, int> > se[300000];
int ind[300000];
LL off[300000] = {};
LL cost[300000] = {};

void myInsert(set<pair<LL, int> > &se, pair<LL, int> val) {
    auto it = se.lower_bound(val);
    auto saved = it;
    bool ins = false;
    if (it == se.end() || it->first > val.first) {
        if (it == se.begin()) {
            ins = true;
        } else {
            --it;
        }
    }
    if (!ins) {
        if (it->second > val.second) {
            ins = true;
        }
    }
    it = saved;
    if (ins) {
        while (it != se.end() && it->second >= val.second) {
            saved = it;
            ++saved;
            se.erase(it);
            it = saved;
        }
        se.insert(val);
    }
}

int myMerge(int a, int b, int maxDep) {
    if (se[a].size() < se[b].size()) {
        swap(a, b);
    }
    for (auto x : se[b]) {
        x.first += off[b] - off[a];
        myInsert(se[a], x);
    }
    return a;
}

void solve(int v, int p) {
    int cur = v;
    for (PII y : x[v]) {
        myInsert(se[v], y);
    }
    LL tot = 0;
    for (int to : g[v]) if (to != p) {
        solve(to, v);
        int i = ind[to];
        if (se[i].begin()->second > dep[v]) {
            se[i].erase(se[i].begin());
        }
        if (se[i].empty()) {
            cout << -1 << endl;
            exit(0);
        }
        cost[i] = se[i].empty() ? 0 : (se[i].begin()->first + off[i]);
        tot += cost[i];
    }
    for (int to : g[v]) if (to != p) {
        off[ind[to]] += tot - cost[ind[to]];
    }
    off[cur] += tot;
    for (int to : g[v]) if (to != p) {
        cur = myMerge(cur, ind[to], dep[v]);
    }
    if (se[cur].empty()) {
        cout << -1 << endl;
        exit(0);
    }
    ind[v] = cur;
    /*cout << v << ": ";
    for (auto x : se[ind[v]]) {
        cout << x.first + off[ind[v]] << ' ' << x.second << ' ';
    }
    cout << endl;*/
}

void calcDep(int v, int p) {
    dep[v] = p == -1 ? 0 : (dep[p] + 1);
    for (int to : g[v]) if (to != p) {
        calcDep(to, v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    calcDep(0, -1);
    REP(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        if (from != to) x[from].pb(mp(w, dep[to]));
    }
    solve(0, -1);
    /*cout << off[ind[0]] << endl;
    for (auto x : se[ind[0]]) {
        cout << x.first + off[ind[0]] << ' ' << x.second << endl;
    }*/
    //assert((int)se[ind[0]].size() == 1);
    cout << se[ind[0]].begin()->first + off[ind[0]] << endl;
    return 0;
}