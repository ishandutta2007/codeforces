#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
char s[1000][1005];
int par[1000000], ra[1000000], cnt[1000000];

int dsuParent(int v) {
    if (par[v] == v) return v;
    return dsuParent(par[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    ra[u] += ra[v];
    cnt[u] += cnt[v];
    par[v] = u;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n * m) par[i] = i, ra[i] = 1, cnt[i] = 0;
    REP(i, n) REP(j, m) if (s[i][j] == '.') {
        int &c = cnt[i * m + j];
        if (s[i - 1][j] != '.') ++c;
        if (s[i + 1][j] != '.') ++c;
        if (s[i][j - 1] != '.') ++c;
        if (s[i][j + 1] != '.') ++c;
    }
    REP(i, n) REP(j, m) if (s[i][j] == '.') {
        if (s[i + 1][j] == '.') dsuMerge(i * m + j, (i + 1) * m + j);
        if (s[i][j + 1] == '.') dsuMerge(i * m + j, i * m + j + 1);
    }
    REP(i, k) {
        int x, y;
        scanf("%d%d", &x, &y), --x, --y;
        int v = dsuParent(x * m + y);
        printf("%d\n", cnt[v]);
    }
    return 0;
}