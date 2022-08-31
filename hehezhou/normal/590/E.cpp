#include <bits/stdc++.h>
using namespace std;
const int L = 10000010;
int id[L], son[L][2], fail[L];
int n, cnt = 1;
int grid[755][755];
int rt = 1;
int chk[755];
inline void insert(int &now, char *s, int iid) {
    if (now == 0) now = ++cnt;
    if (*s == 0) {
        if (id[now]) chk[iid] = 1;
        else id[now] = iid;
        return;
    }
    insert(son[now][*s - 'a'], s + 1, iid);
}
char buc[L + 755], *s[755];
int now;
inline void build() {
    queue < int > q;
    for (int i = 0; i < 2; i++) if (son[rt][i]) fail[son[rt][i]] = rt, q.push(son[rt][i]); else son[rt][i] = rt;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
            if (son[now][i]) q.push(son[now][i]), fail[son[now][i]] = son[fail[now]][i];
            else son[now][i] = son[fail[now]][i];
        if (id[now] == 0) id[now] = id[fail[now]];
    }
}
inline void calc(int now, char *s, int iid) {
    grid[iid][id[now] == iid ? id[fail[now]] : id[now]] = 1;
    if (*s == 0) return;
    calc(son[now][*s - 'a'], s + 1, iid);
}
int match[755], vis[755];
inline int dfs(int now) {
    vis[now] = 1;
    for (int i = 1; i <= n; i++) {
        if (grid[now][i])
            if (match[i]) {
                if (vis[match[i]]) continue;
                if (dfs(match[i])) return match[i] = now, 1;
            }
            else {
                match[i] = now;
                return 1;
            }
    }
    return 0;
}
int chs[755], unable[755];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        s[i] = buc + now;
        scanf("%s", s[i]);
        now += strlen(s[i]) + 1;
        insert(rt, s[i], i);
    }
    build();
    for (int i = 1; i <= n; i++) if (!chk[i]) calc(rt, s[i], i);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                grid[i][j] |= grid[i][k] & grid[k][j];
            }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (!chk[i]) memset(vis, 0, sizeof vis), ans += 1 ^ dfs(i);
    printf("%d\n", ans);
    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (chk[i]) continue;
        unable[match[i]] = 1;
    }
    for (int i = 1; i <= n; i++) if (!unable[i]) chs[++ans] = i;
    memset(unable, 0, sizeof unable); 
    int upd;
    do {
        for (int i = 1; i <= ans; i++)
            for (int j = 1; j <= n; j++) if (grid[chs[i]][j]) unable[j] = 1;
        upd = 0;
        for (int i = 1; i <= ans; i++) {
            while (unable[chs[i]]) chs[i] = match[chs[i]], upd = 1;
        }
    } while (upd);
    for (int i = 1; i <= ans; i++) printf("%d%c", chs[i], " \n"[i == ans]);
}