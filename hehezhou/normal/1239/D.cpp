#include <bits/stdc++.h>
using namespace std;
struct edge {
    int v, nxt;
} e[1000010];
int head[1000010], tot;
int dfn[1000010], low[1000010];
int id[1000010], idcnt, sta[1000010], insta[1000010], top;
inline void tarjan(int now) {
    static int dfsnow = 0;
    dfn[now] = low[now] = ++dfsnow;
    sta[++top] = now, insta[now] = 1;
    for(int i = head[now]; i; i = e[i].nxt) {
        if(!dfn[e[i].v]) tarjan(e[i].v);
        if(insta[e[i].v]) low[now] = min(low[now], low[e[i].v]);
    }
    if(low[now] == dfn[now]) {
        idcnt++;
        do {
            insta[sta[top]] = 0;
            id[sta[top]] = idcnt;
        } while(sta[top--] != now);
    }
}
inline void addedge(int u, int v) {
    e[++tot] = edge{v, head[u]};
    head[u] = tot;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        tot = idcnt = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) dfn[i] = low[i] = head[i] = insta[i] = id[i] = 0;
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        tarjan(1);
        for(int i = 1; i <= n; i++) {
            if(id[i] == 1) continue;
            int cnt = 0;
            for(int j = 1; j <= n; j++) if(id[j] == 1) cnt++;
            printf("Yes\n%d %d\n", cnt, n - cnt);
            for(int j = 1; j <= n; j++) if(id[j] == 1) printf("%d ", j);
            puts("");
            for(int j = 1; j <= n; j++) if(id[j] != 1) printf("%d ", j);
            puts("");
            goto loop;
        }
        puts("No");
        loop:;
    }
}