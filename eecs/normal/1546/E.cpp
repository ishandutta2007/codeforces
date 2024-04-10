#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 998244353;
int T, n, p[maxn][maxn], vis[maxn], lnk[maxn], ans[maxn], fa[maxn], sz[maxn];
int cnt, tim, tp, st[maxn], bel[maxn], dfn[maxn], low[maxn], type[maxn], ban[maxn][2];
bool chk[maxn][maxn];
vector<int> G[maxn], H[maxn];
mt19937 rnd(time(0));

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
 
void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y, sz[y] += sz[x];
}

void tarjan(int v) {
    dfn[v] = low[v] = ++tim, st[++tp] = v;
    for (int u : H[v]) {
        if (!dfn[u]) tarjan(u), low[v] = min(low[v], low[u]);
        else if (!bel[u]) low[v] = min(low[v], dfn[u]);
    }
    if (dfn[v] == low[v]) {
        cnt++;
        for (int u = 0; u ^ v; ) u = st[tp--], bel[u] = cnt;
    }
}

int test(int v) {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(v), vis[v] = 1;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int y : H[x]) if (!vis[y]) {
            Q.push(y), vis[y] = 1;
        }
    }
    for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
        if (vis[i] && vis[i + 2 * n]) return 0;
    }
    return 1;
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            G[i].clear(), fa[i] = i, sz[i] = 1;
            for (int j = 1; j <= n; j++) scanf("%d", &p[i][j]);
        }
        for (int i = 1; i <= 4 * n; i++) {
            H[i].clear();
        }
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = i + 1; j <= 2 * n; j++) {
                bool flag = 0;
                for (int k = 1; k <= n; k++) {
                    if (p[i][k] == p[j][k]) { flag = 1; break; }
                }
                chk[i][j] = chk[j][i] = flag;
                if (flag) G[i].push_back(j), G[j].push_back(i);
            }
        }
        function<int(int)> match = [&](int v) {
            shuffle(G[v].begin(), G[v].end(), rnd);
            for (int u : G[v]) if (!vis[u]) {
                vis[u] = 1;
                int z = lnk[u];
                lnk[u] = v, lnk[v] = u, lnk[z] = 0;
                if (!z || match(z)) return 1;
                lnk[u] = z, lnk[v] = 0, lnk[z] = u;
            }
            return 0;
        };
        memset(lnk, 0, sizeof(lnk));
        int num = 0;
        for (int i = 1; i <= 2 * n; i++) {
            memset(vis, 0, sizeof(vis));
            if (!lnk[i] && match(i)) num++;
        }
        while (num < n) {
            memset(lnk, 0, sizeof(lnk)), num = 0;
            for (int i = 1; i <= 2 * n; i++) {
                memset(vis, 0, sizeof(vis));
                if (!lnk[i] && match(i)) num++;
            }
        }
        for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
            for (int j = 1; j <= 2 * n; j++) if (j < lnk[j] && i ^ j) {
                if (chk[i][j]) H[i].push_back(j + 2 * n), H[j].push_back(i + 2 * n);
                if (chk[i][lnk[j]]) H[i].push_back(j), H[j + 2 * n].push_back(i + 2 * n);
                if (chk[lnk[i]][j]) H[i + 2 * n].push_back(j + 2 * n), H[j].push_back(i);
                if (chk[lnk[i]][lnk[j]]) H[i + 2 * n].push_back(j), H[j + 2 * n].push_back(i);
            }
        }
        tim = 0, memset(dfn, 0, sizeof(dfn));
        cnt = 0, memset(bel, 0, sizeof(bel));
        for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
            if (!dfn[i]) tarjan(i);
            if (!dfn[i + 2 * n]) tarjan(i + 2 * n);
        }
        for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
            type[i] = bel[i] < bel[i + 2 * n];
        }
        for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
            int foo = test(i), bar = test(i + 2 * n);
            ban[i][0] = !foo, ban[i][1] = !bar;
        }
        for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
            for (int j = 1; j <= 2 * n; j++) if (j < lnk[j] && i ^ j) {
                if ((!chk[i][j] && !(type[i] == 1 && type[j] == 1) && !ban[i][0] && !ban[j][0] ||
                    !chk[lnk[i]][lnk[j]] && !(type[i] == 0 && type[j] == 0) && !ban[i][1] && !ban[j][1])
                    && chk[i][lnk[j]] && chk[j][lnk[i]]) unite(i, j);
                if ((!chk[i][lnk[j]] && !(type[i] == 1 && type[j] == 0) && !ban[i][0] && !ban[j][1] ||
                    !chk[j][lnk[i]] && !(type[i] == 0 && type[j] == 1) && !ban[i][1] && !ban[j][0])
                    && chk[i][j] && chk[lnk[i]][lnk[j]]) unite(i, j);
            }
        }
        int cnt = 0;
        for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
            if (i == find(i) && sz[i] > 1) cnt++;
        }
        printf("%d\n", qp(2, cnt));
        for (int i = 1; i <= 2 * n; i++) if (i < lnk[i]) {
            if (type[i]) printf("%d ", i);
            else printf("%d ", lnk[i]);
        }
        putchar('\n');
    }
    return 0;
}