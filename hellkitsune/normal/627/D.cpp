#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, m;
int a[200000];
bool q[200000];
vector<PII> g[200000], og[200000];
int d[400000], vrest[200000], vmx[200000], vmx2[200000], vterm[200000];
int term[400000];
int s[400000], t[400000];

void dfs(int v, int p, int ind) {
    if (d[ind] != -1) return;
    if (!q[v]) {
        term[ind] = 1;
        d[ind] = 0;
        return;
    }
    term[ind] = 0;
    int mxterm = 0, mxterm2 = 0;
    int rest = 0;
    if (vrest[v] == -1) {
        REP(i, g[v].size()) if (g[v][i].first != p) {
            PII &to = g[v][i];
            dfs(to.first, v, to.second);
            if (term[to.second]) {
                term[ind] = 1;
                ++vterm[v];
                if (d[to.second] > mxterm) {
                    mxterm2 = mxterm;
                    mxterm = d[to.second];
                } else {
                    mxterm2 = max(mxterm2, d[to.second]);
                }
            } else {
                rest += d[to.second];
            }
            swap(g[v][i], g[v][g[v].size() - 1]);
            g[v].pop_back();
            --i;
        }
        vmx[v] = mxterm;
        vmx2[v] = mxterm2;
        vrest[v] = rest;
    } else {
        mxterm = (term[ind ^ 1] && vmx[v] == d[ind ^ 1]) ? vmx2[v] : vmx[v];
        rest = vrest[v];
        if (!term[ind ^ 1]) rest -= d[ind ^ 1];
        term[ind] = (vterm[v] - term[ind ^ 1]) > 0;
        PII &to = g[v][0];
        dfs(to.first, v, to.second);
        if (term[to.second]) {
            term[ind] = 1;
            mxterm = max(mxterm, d[to.second]);
        } else {
            rest += d[to.second];
        }
    }
    d[ind] = 1 + mxterm + rest;
}

bool solve(int x) {
    REP(i, n) q[i] = a[i] >= x;
    memset(d, -1, sizeof d);
    memset(term, 0, sizeof term);
    memset(vrest, -1, sizeof vrest);
    memset(vterm, 0, sizeof vterm);
    REP(i, m) if (d[i] == -1) {
        dfs(t[i], s[i], i);
    }
    REP(i, n) if (q[i]) {
        int mxterm = 0;
        int rest = 0;
        for (PII to : g[i]) {
            if (term[to.second]) mxterm = max(mxterm, d[to.second]);
            else rest += d[to.second];
        }
        if (1 + rest + mxterm >= k) return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(mp(to, 2 * i));
        g[to].pb(mp(from, 2 * i + 1));
        s[2 * i] = from;
        t[2 * i] = to;
        s[2 * i + 1] = to;
        t[2 * i + 1] = from;
    }
    m = 2 * n - 2;
    int lo = 1, hi = 1000000, mid;
    REP(i, n) og[i] = g[i];
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (solve(mid)) lo = mid;
        else hi = mid - 1;
        REP(i, n) g[i] = og[i];
    }
    printf("%d\n", lo);
    return 0;
}