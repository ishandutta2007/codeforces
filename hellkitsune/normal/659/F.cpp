#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
LL k;
int a[1001][1001];

int par[1 << 20], ra[1 << 20];
void dsuInit() {
    REP(i, 1 << 20) par[i] = i, ra[i] = 1;
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

int dsuParent(int y, int x) {
    return dsuParent((y << 10) | x);
}

void dsuMerge(int y, int x, int yy, int xx) {
    int u = (y << 10) | x;
    int v = (yy << 10) | xx;
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
}

PII ord[1000001];

inline bool cmp(const PII &lhs, const PII &rhs) {
    return a[lhs.first][lhs.second] > a[rhs.first][rhs.second];
}

bool used[1001][1001] = {};

vector<PII> all[1000001];

int ans[1000][1000];

int rem, eq;
void dfs(int y, int x) {
    ans[y][x] = eq;
    --rem;
    if (rem && y > 0 && ans[y - 1][x] == 0 && a[y - 1][x] >= eq) dfs(y - 1, x);
    if (rem && x > 0 && ans[y][x - 1] == 0 && a[y][x - 1] >= eq) dfs(y, x - 1);
    if (rem && y < n - 1 && ans[y + 1][x] == 0 && a[y + 1][x] >= eq) dfs(y + 1, x);
    if (rem && x < m - 1 && ans[y][x + 1] == 0 && a[y][x + 1] >= eq) dfs(y, x + 1);
}

int main() {
    dsuInit();
    scanf("%d%d%I64d", &n, &m, &k);
    REP(i, n) REP(j, m) scanf("%d", a[i] + j);
    LL sum = 0;
    REP(i, n) REP(j, m) sum += a[i][j];

    if (k > sum) {
        printf("NO\n");
        return 0;
    }
    int tot = n * m;
    REP(i, n) REP(j, m) if (a[i][j] > 0 && k % a[i][j] == 0 && k / a[i][j] <= tot) {
        all[k / a[i][j]].pb(mp(i, j));
    }
    REP(i, n) REP(j, m) ord[i * m + j] = mp(i, j);
    sort(ord, ord + tot, cmp);
    int pos = 0;
    for (int i = 1; i <= 1000000; ++i) if (k % i == 0) {
        LL need = k / i;
        if (need > 1.1e9) continue;
        while (pos < tot) {
            int y = ord[pos].first;
            int x = ord[pos].second;
            if (a[y][x] < need) break;
            used[y][x] = true;
            if (y > 0 && used[y - 1][x]) dsuMerge(y, x, y - 1, x);
            if (x > 0 && used[y][x - 1]) dsuMerge(y, x, y, x - 1);
            if (y < n - 1 && used[y + 1][x]) dsuMerge(y, x, y + 1, x);
            if (x < m - 1 && used[y][x + 1]) dsuMerge(y, x, y, x + 1);
            ++pos;
        }
        for (PII x : all[i]) if (ra[dsuParent(x.first, x.second)] >= i) {
            rem = i;
            eq = need;
            dfs(x.first, x.second);
            printf("YES\n");
            REP(i, n) {
                REP(j, m) printf("%d ", ans[i][j]);
                printf("\n");
            }
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}