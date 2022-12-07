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

int n;
vector<PII> g[200001];
vector<PII> ng;
int par[200000], ra[200000];
int tin[200000], fup[200000], timer = 0;
bool incyc[200000] = {};
int cyc, clen = 0;
int sz[200000];
LL distSum[200000], ans[200000], ans2[200000];

void dsuInit() {
    REP(i, n) par[i] = i, ra[i] = 1;
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
}

void dfs(int v, int p) {
    tin[v] = fup[v] = timer++;
    for (PII to : g[v]) if (to.first != p) {
        if (tin[to.first] == -1) {
            dfs(to.first, v);
            if (fup[to.first] <= tin[v]) {
                dsuMerge(to.first, v);
            }
            fup[v] = min(fup[v], fup[to.first]);
        } else {
            fup[v] = min(fup[v], tin[to.first]);
        }
    }
}

void dfs2(int v, int p) {
    sz[v] = 1;
    distSum[v] = 0;
    vector<PII> *q;
    if (p == -1) q = &ng;
    else q = g + v;
    for (PII to : *q) if (!incyc[to.first] && to.first != p) {
        dfs2(to.first, v);
        distSum[v] += distSum[to.first] + sz[to.first] * to.second;
        sz[v] += sz[to.first];
    }
}

void dfs3(int v, int p, int lastLen) {
    vector<PII> *q;
    if (p == -1) q = &ng;
    else q = g + v;
    if (p != -1) {
        distSum[v] += distSum[p] - distSum[v] + lastLen * (n - 2 * sz[v]);
    }
    for (PII to : *q) if (!incyc[to.first] && to.first != p) {
        dfs3(to.first, v, to.second);
    }
}

int a[400000], len[400000], pos = 0, asz[400000], ind[400000];

void dfs4(int v, int p) {
    asz[v] = 1;
    for (PII to : g[v]) if (!incyc[to.first] && to.first != p) {
        dfs4(to.first, v);
        asz[v] += asz[to.first];
    }
}

LL updVal;
void dfs5(int v, int p) {
    if (p != -1) {
        ans[v] += updVal;
    }
    for (PII to : g[v]) if (!incyc[to.first] && to.first != p) {
        dfs5(to.first, v);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        g[from].pb(mp(to, w));
        g[to].pb(mp(from, w));
    }
    dsuInit();
    REP(i, n) tin[i] = -1;
    dfs(0, -1);
    REP(i, n) if (dsuParent(i) != i) {
        cyc = dsuParent(i);
        break;
    }
    REP(i, n) incyc[i] = dsuParent(i) == cyc;
    REP(i, n) if (dsuParent(i) == cyc) for (PII to : g[i]) {
        ng.pb(to);
    }
    dfs2(cyc, -1);
    dfs3(cyc, -1, 0);
    REP(i, n) if (dsuParent(i) == cyc) {
        dfs4(i, -1);
        ++clen;
    }
    for (int v = cyc, p = -1; ;) {
        a[pos] = asz[v];
        ind[pos] = v;
        for (PII to : g[v]) if (incyc[to.first] && to.first != p) {
            len[pos++] = to.second;
            p = v;
            v = to.first;
            break;
        }
        if (v == cyc) break;
    }
    REP(i, n) if (incyc[i]) ans[i] = distSum[cyc];
    else ans[i] = distSum[i];
    assert(pos == clen);
    REP(i, clen + 1) a[clen + i] = a[i], len[clen + i] = len[i], ind[clen + i] = ind[i];
    int tot = 0;
    REP(i, clen) tot += len[i];
    int mx = tot / 2;
    REP(z, 2) {
        int pos = 0;
        LL sum = 0, asum = 0, sumSum = 0;
        REP(i, clen) {
            if (i && pos >= i) {
                sumSum -= asum * len[i - 1];
                sum -= len[i - 1];
                asum -= a[i];
            }
            if (pos < i) pos = i;
            while (sum + len[pos] <= mx) {
                sum += len[pos];
                asum += a[pos + 1];
                sumSum += sum * a[pos + 1];
                ++pos;
            }
            ans[ind[i]] += sumSum;
            ans2[ind[i]] += sumSum;
        }
        if (!z) {
            reverse(a, a + (2 * clen + 1));
            reverse(ind, ind + (2 * clen + 1));
            reverse(len, len + (2 * clen));
            len[2 * clen] = len[0];
            mx = tot - mx - 1;
        }
    }
    REP(i, n) if (dsuParent(i) == cyc) {
        updVal = ans2[i];
        dfs5(i, -1);
    }
    REP(i, n) printf("%I64d ", ans[i]);
    printf("\n");
    return 0;
}