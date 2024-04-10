#include <bits/stdc++.h>
using namespace std;
struct edge {
    int v, nxt;
} e[4000010];
int n, m, head[500010], tot;
int dfn[500010], low[500010];
int idcnt, dfsnow, id[500010], sta[500010], insta[500010], top;
inline void init() {
    memset(insta, 0, sizeof insta);
    memset(id, 0, sizeof id);
    memset(head, 0, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    tot = idcnt = dfsnow = top = 0;
}
inline void addedge(int u, int v) {
    e[++tot] = edge{v, head[u]};
    head[u] = tot;
}
inline void tarjan(int now) {
    dfn[now] = low[now] = ++dfsnow;
    sta[++top] = now;
    insta[now] = 1;
    for (int i = head[now]; i; i = e[i].nxt) {
        if (!dfn[e[i].v]) tarjan(e[i].v);
        if (insta[e[i].v]) low[now] = min(low[now], low[e[i].v]);
    }
    if (low[now] == dfn[now]) {
        ++idcnt;
        do {
            insta[sta[top]] = 0;
            id[sta[top]] = idcnt;
        } while (sta[top--] != now);
    }
}
map < pair <int, int>, vector <int> > grid;
int u[50010], v[50010], t[50010], c[50010];
vector <int> son[50010];
inline int check(int x) {
    init();
    int cnt = 2 * m + 2;
    for (auto i : grid) {
        if (i.second.size() == 2) {
            addedge(i.second[0] * 2, i.second[1] * 2 - 1);
            addedge(i.second[1] * 2, i.second[0] * 2 - 1);
        }
    }
    addedge(cnt - 1, cnt);
    for (int i = 1; i <= m; i++) {
        if (t[i] > x) {
            addedge(i * 2 - 1, cnt - 1);
            addedge(cnt, i * 2);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (son[i].size() == 0) continue;
        int now = son[i][0] * 2;
        for (int j = 1; j < son[i].size(); j++) {
            addedge(son[i][j] * 2 - 1, now);
            addedge(now - 1, son[i][j] * 2);
            cnt += 2;
            addedge(cnt, now);
            addedge(now - 1, cnt - 1);
            now = cnt;
            addedge(cnt, son[i][j] * 2);
            addedge(son[i][j] * 2 - 1, cnt - 1);
        }
        now = son[i][son[i].size() - 1] * 2;
        for (int j = son[i].size() - 1; j --> 0; ) {
            addedge(son[i][j] * 2 - 1, now);
            addedge(now - 1, son[i][j] * 2);
            cnt += 2;
            addedge(cnt, now);
            addedge(now - 1, cnt - 1);
            now = cnt;
            addedge(cnt, son[i][j] * 2);
            addedge(son[i][j] * 2 - 1, cnt - 1);
        }
    }
    for (int i = 1; i <= cnt; i++) if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= cnt / 2; i++) if (id[i * 2] == id[i * 2 - 1]) return 0;
    return 1;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", u + i, v + i, c + i, t + i);
        grid[make_pair(u[i], c[i])].push_back(i);
        grid[make_pair(v[i], c[i])].push_back(i);
        son[u[i]].push_back(i);
        son[v[i]].push_back(i);
    }
    for (auto i : grid)
        if (i.second.size() > 2) return puts("No"), 0;
    if (!check(1000000000)) return puts("No"), 0;
    int l = 0, r = 1000000000, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    check(ans);
    puts("Yes");
    int cnt = 0;
    for (int i = 1; i <= m; i++) if (id[i * 2 - 1] < id[i * 2]) cnt++;
    printf("%d %d\n", ans, cnt);
    for (int i = 1; i <= m; i++) if (id[i * 2 - 1] < id[i * 2]) printf("%d ", i);
    return 0;
}