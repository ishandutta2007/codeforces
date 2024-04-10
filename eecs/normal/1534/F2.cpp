#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, ans, a[maxn], rb[maxn], ok[maxn];
int mark[maxn], L[maxn], R[maxn], vis[maxn], ban[maxn];
int cnt, tim, tp, st[maxn], dfn[maxn], low[maxn], ind[maxn], bel[maxn];
char s[maxn], t[maxn];
vector<int> G[maxn], rH[maxn], H[maxn], col[maxn];

int id(int x, int y) {
    return (x - 1) * m + y;
}

void tarjan(int v) {
    dfn[v] = low[v] = ++tim, st[++tp] = v;
    for (int u : G[v]) {
        if (!dfn[u]) tarjan(u), low[v] = min(low[v], low[u]);
        else if (!bel[u]) low[v] = min(low[v], dfn[u]);
    }
    if (dfn[v] == low[v]) {
        cnt++;
        for (int u = 0; u ^ v; ) u = st[tp--], bel[u] = cnt;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", t + 1);
        for (int j = 1; j <= m; j++) {
            s[id(i, j)] = t[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }

    for (int j = 1; j <= m; j++) {
        for (int i = n, cnt = 0; i; i--) if (s[id(i, j)] == '#') {
            if (++cnt == a[j]) { mark[id(i, j)] = j; break; }
        }
        for (int i = 1, lst = 0; i <= n; i++) {
            if (s[id(i, j)] == '#') {
                if (lst) G[id(lst, j)].push_back(id(i, j));
                lst = i;
            }
            if (!lst) continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!x || x > n || !y || y > m || s[id(x, y)] == '.') continue;
                G[id(lst, j)].push_back(id(x, y));
            }
        }
    }
    for (int i = 1; i <= n * m; i++) if (s[i] == '#') {
        if (!dfn[i]) tarjan(i);
    }

    function<void(int)> dfs1 = [&](int v) {
        if (vis[v]) return;
        vis[v] = 1;
        for (int u : rH[v]) {
            dfs1(u), ban[v] |= ban[u];
        }
        while (col[v].size() > 1) {
            mark[col[v].back()] = 0, col[v].pop_back();
        }
        if (!col[v].empty()) {
            if (ban[v]) for (int x : col[v]) mark[x] = 0;
            ban[v] = 1;
        }
    };
    for (int i = 1; i <= n * m; i++) {
        if (mark[i]) col[bel[i]].push_back(i);
        for (int j : G[i]) if (bel[i] ^ bel[j]) {
            H[bel[i]].push_back(bel[j]), ind[bel[j]] = 1;
            rH[bel[j]].push_back(bel[i]);
        }
    }
    for (int i = 1; i <= cnt; i++) {
        dfs1(i);
    }

    for (int i = 1; i <= cnt; i++) {
        L[i] = INT_MAX, R[i] = INT_MIN, vis[i] = 0;
    }
    for (int i = 1; i <= n * m; i++) if (mark[i]) {
        L[bel[i]] = min(L[bel[i]], mark[i]), ok[mark[i]] = 1;
        R[bel[i]] = max(R[bel[i]], mark[i]);
    }
    function<void(int)> dfs2 = [&](int v) {
        if (vis[v]) return;
        vis[v] = 1;
        for (int u : H[v]) {
            dfs2(u);
            L[v] = min(L[v], L[u]), R[v] = max(R[v], R[u]);
        }
    };
    for (int i = 1; i <= cnt; i++) {
        dfs2(i);
    }

    for (int i = 1; i <= cnt; i++) if (!ind[i]) {
        if (L[i] != INT_MAX) rb[L[i]] = max(rb[L[i]], R[i]);
    }
    for (int i = 1; i <= m; i++) {
        rb[i] = max(rb[i], rb[i - 1]);
    }
    int cur = 1;
    while (1) {
        while (cur <= m && !ok[cur]) cur++;
        if (cur > m) break;
        ans++, cur = rb[cur] + 1;
    }
    printf("%d\n", ans);
    return 0;
}