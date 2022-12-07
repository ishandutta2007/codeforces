#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;

int par[1005], ra[1005];
int c[1005];
bool have[1005][1005];

void dsuInit() {
    forn(i, n) {
        par[i] = i;
        ra[i] = 1;
    }
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) {
        swap(u, v);
    }
    par[v] = u;
    ra[u] += ra[v];
}

bool bad[1005] = {};

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, k) {
        scanf("%d", c + i);
        --c[i];
    }
    dsuInit();
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        dsuMerge(from, to);
        have[from][to] = have[to][from] = true;
    }
    int mx = 0;
    for (int i = 1; i < k; ++i) {
        if (ra[dsuParent(c[i])] > ra[dsuParent(c[mx])]) {
            mx = i;
        }
    }
    forn(i, k) {
        bad[dsuParent(c[i])] = true;
    }
    forn(i, n) {
        if (!bad[dsuParent(i)]) {
            dsuMerge(i, c[mx]);
        }
    }
    int ans = 0;
    forn(i, n) forn(j, i) {
        if (!have[i][j] && dsuParent(i) == dsuParent(j)) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}