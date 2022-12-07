#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[100000];
int dep[100000], cnt[100000], cnt2[100000];
LL sum[100000], sum2[100000];
int tin[100000], tout[100000], timer = 0;
int up[17][100000];

void dfs(int v, int p) {
    tin[v] = timer++;
    up[0][v] = p;
    if (p == -1) dep[v] = 0;
    else dep[v] = dep[p] + 1;
    sum[v] = dep[v];
    cnt[v] = 1;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
        sum[v] += sum[to];
        cnt[v] += cnt[to];
    }
    tout[v] = timer++;
}

void dfs2(int v, int p) {
    for (int to : g[v]) if (to != p) {
        sum2[to] = sum2[v] + cnt2[v] + sum[v] - sum[to] - (LL)dep[v] * (cnt[v] - cnt[to]) + cnt[v] - cnt[to];
        cnt2[to] = cnt2[v] + cnt[v] - cnt[to];
        dfs2(to, v);
    }
}

bool isParent(int v, int p) {
    return tin[v] >= tin[p] && tout[v] <= tout[p];
}

int lca(int u, int v) {
    if (isParent(u, v)) return v;
    if (isParent(v, u)) return u;
    for (int i = 16; i >= 0; --i) if (up[i][v] != -1 && !isParent(u, up[i][v])) {
        v = up[i][v];
    }
    return up[0][v];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    sum2[0] = cnt2[0] = 0;
    dfs2(0, -1);
    REP(i, 16) REP(j, n) if (up[i][j] == -1) {
        up[i + 1][j] = -1;
    } else {
        up[i + 1][j] = up[i][up[i][j]];
    }
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        int lc = lca(u, v);
        double ans;
        if (lc == u || lc == v) {
            if (lc == u) swap(u, v);
            int nx = u;
            for (int i = 16; i >= 0; --i) if (up[i][nx] != -1 && !isParent(v, up[i][nx])) {
                nx = up[i][nx];
            }
            ans = (double)sum[u] / cnt[u] + (double)(sum[v] - sum[nx] - (LL)(cnt[v] - cnt[nx]) * dep[v] + sum2[v]) / (cnt[v] - cnt[nx] + cnt2[v]) - dep[v] + 1;
        } else {
            ans = (double)sum[u] / cnt[u] + (double)sum[v] / cnt[v] - 2 * dep[lc] + 1;
        }
        printf("%.12f\n", ans);
    }
    return 0;
}