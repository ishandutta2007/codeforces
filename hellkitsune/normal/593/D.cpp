#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

vector<PII> og[200000];
vector<PII> g[200000];
int par[200000], pare[200000];
LL ew[200000];
int efrom[200000], eto[200000];
int n, m;

int dpar[200000];
void dsuInit() {
    REP(i, n) dpar[i] = i;
}

int dsuParent(int v) {
    if (v == dpar[v]) return v;
    return dpar[v] = dsuParent(dpar[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    dpar[v] = u;
}

void dfs(int v, int p) {
    for (PII to : og[v]) if (to.first != p) {
        g[v].pb(to);
        par[to.first] = v;
        pare[to.first] = to.second;
        dfs(to.first, v);
    }
}

bool was[200000] = {};
vector<int> f, s;
vector<LL> fc, sc;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d%I64d", &from, &to, ew + i), --from, --to;
        efrom[i] = from;
        eto[i] = to;
        og[from].pb(mp(to, i));
        og[to].pb(mp(from, i));
    }
    REP(i, n) par[i] = -1;
    dfs(0, -1);
    dsuInit();
    REP(i, n - 1) if (ew[i] == 1) {
        if (par[eto[i]] == efrom[i]) {
            dsuMerge(efrom[i], eto[i]);
        } else {
            dsuMerge(eto[i], efrom[i]);
        }
    }
    REP(i, m) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int u, v;
            LL w;
            scanf("%d%d%I64d", &u, &v, &w), --u, --v;
            u = dsuParent(u);
            v = dsuParent(v);
            if (u == v) {
                printf("%I64d\n", w);
                continue;
            }
            f.clear();
            s.clear();
            fc.clear();
            sc.clear();
            int uu = u, vv = v;
            REP(times, 64) {
                if (u == 0) break;
                fc.pb(ew[pare[u]]);
                u = dsuParent(par[u]);
                f.pb(u);
            }
            REP(times, 64) {
                if (v == 0) break;
                sc.pb(ew[pare[v]]);
                v = dsuParent(par[v]);
                s.pb(v);
            }
            int fup = -1;
            int sup = -1;
            for (int x : f) was[x] = true;
            was[uu] = true;
            if (!was[vv]) REP(i, s.size()) if (was[s[i]]) {
                sup = i;
                break;
            }

            if (sup == -1 && !was[vv]) {
                was[uu] = false;
                for (int x : f) was[x] = false;
                printf("0\n");
                continue;
            }
            was[uu] = false;
            for (int x : f) was[x] = false;
            for (int x : s) was[x] = true;
            was[vv] = true;
            if (!was[uu]) REP(i, f.size()) if (was[f[i]]) {
                fup = i;
                break;
            }

            if (fup == -1 && !was[uu]) {
                was[vv] = false;
                for (int x : s) was[x] = false;
                printf("0\n");
                continue;
            }
            was[vv] = false;
            for (int x : s) was[x] = false;

            for (int i = 0; i <= fup; ++i) w /= fc[i];
            for (int i = sup; i >= 0; --i) w /= sc[i];
            printf("%I64d\n", w);
        } else {
            int ind;
            LL w;
            scanf("%d%I64d", &ind, &w), --ind;
            ew[ind] = w;
            if (w == 1) {
                if (par[eto[ind]] == efrom[ind]) {
                    dsuMerge(efrom[ind], eto[ind]);
                } else {
                    dsuMerge(eto[ind], efrom[ind]);
                }
            }
        }
    }
    return 0;
}