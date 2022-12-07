#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];
bool used[100000];
int p[100000];
LL ans[100000];

int par[100000], ra[100000];
LL sum[100000];

void dsuInit() {
    forn(i, n) {
        par[i] = i;
        ra[i] = 1;
        sum[i] = a[i];
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
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
    sum[u] += sum[v];
}



int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", p + i), --p[i];
    ans[n - 1] = 0;
    dsuInit();
    forn(i, n) used[i] = false;
    LL res = 0;
    for (int i = n - 1; i > 0; --i) {
        int pos = p[i];
        if (pos > 0 && used[pos - 1]) {
            dsuMerge(pos, pos - 1);
        }
        if (pos < n - 1 && used[pos + 1]) {
            dsuMerge(pos, pos + 1);
        }
        used[pos] = true;
        res = max(res, sum[dsuParent(pos)]);
        ans[i - 1] = res;
    }
    forn(i, n) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}