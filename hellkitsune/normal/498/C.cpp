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

struct V {
    int val, ind;
    V(int val, int ind) : val(val), ind(ind) {}
    V() {}
};

int n, m;
int a[100];
set<int> d;
vector<int> di;
bool pr[40000];
int fr[100], t[100];
vector<V> v1, v2;
set<PII> se;
vector<vector<int> > g;
vector<char> used, vis;
vector<int> mt;

bool kuhn(int v) {
    if (vis[v]) return false;
    vis[v] = true;
    for (int to : g[v]) if (mt[to] == -1 || kuhn(mt[to])) {
        mt[to] = v;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 40000) pr[i] = true;
    for (int i = 2; i < 40000; ++i) if (pr[i]) {
        for (int j = i * i; j < 40000; j += i)
            pr[j] = false;
    }
    for (int i = 2; i < 40000; ++i) if (pr[i])
        di.pb(i);
    cin >> n >> m;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> fr[i] >> t[i], --fr[i], --t[i];
    REP(i, m) se.insert(mp(fr[i], t[i])), se.insert(mp(t[i], fr[i]));
    REP(i, n) {
        int val = a[i];
        for (int j = 0; di[j] * di[j] <= val; ++j) if (val % di[j] == 0) {
            d.insert(di[j]);
            val /= di[j];
            while (val % di[j] == 0)
                val /= di[j];
        }
        if (val > 1) d.insert(val);
    }
    di.clear();
    for (int x : d)
        di.pb(x);
    REP(i, n) {
        int val = a[i];
        REP(j, di.size()) {
            while (val % di[j] == 0) {
                val /= di[j];
                if (i & 1) v2.pb(V(j, i));
                else v1.pb(V(j, i));
            }
        }
    }
    n = (int)v1.size();
    m = (int)v2.size();
    g.resize(n);
    REP(i, n) REP(j, m) if (v1[i].val == v2[j].val && se.count(mp(v1[i].ind, v2[j].ind))) {
        g[i].pb(j);
    }
    vis.resize(n);
    used.resize(n);
    mt.assign(m, -1);
    int ans = 0;
    REP(i, n) for (int to : g[i]) if (mt[to] == -1) {
        mt[to] = i;
        used[i] = true;
        ++ans;
        break;
    }
    REP(i, n) if (!used[i]) {
        REP(j, n) vis[j] = false;
        if (kuhn(i)) ++ans;
    }
    cout << ans << '\n';
    return 0;
}