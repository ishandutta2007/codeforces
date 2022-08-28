#include <bits/stdc++.h>
using namespace std;
int t;
struct edge {
    int v, nxt;
} e[1000010];
int head[500010];
int du[500010];
int n, m, tot;
inline void addedge(int u, int v) {
    e[++tot] = edge{v, head[u]};
    head[u] = tot;
}
int dis[500010], pre[500010], vis[500010];
int insta[500010], sta[500010], top;
int tag;
int tmp[500010];
inline void dfs(int now, int f) {
    insta[now] = top + 1, sta[++top] = now;
    vis[now] = 1;
    int _min = 0;
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v != f && insta[e[i].v]) {
            if(_min == 0 || insta[e[i].v] > insta[_min]) _min = e[i].v;
        }
    }
    if(_min && (sta[1] != _min || top != n)) {
        puts("Yes");
        for(int j = 1; j <= n; j++) tmp[j] = 0;
        for(int j = top; sta[j] != _min; j--) tmp[sta[j]] = 1;
        tmp[_min] = 1;
        int cnt = 0;
        for(int j = 1; j <= n; j++) if(!tmp[j]) cnt++; else if(du[j] != 2) exit(1);
        printf("%d\n", cnt);
        for(int j = 1; j <= n; j++) if(!tmp[j]) printf("%d ", j);
        puts("");
        tag = 1;
        return;
    }
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == f || du[e[i].v] != 2 || insta[e[i].v]) continue;
        dfs(e[i].v, now);
        if(tag) return;
    }
    insta[now] = 0;
    top--;
}
inline void bfs(int s) {
    queue<int> q;
    q.push(s);
    dis[s] = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(du[now] != 1 || now == s) {
            for(int i = head[now]; i; i = e[i].nxt) {
                if(dis[e[i].v]) continue;
                dis[e[i].v] = dis[now] + 1;
                pre[e[i].v] = now;
                q.push(e[i].v);
            }
        }
        else {
            if(dis[now] == n) continue;
            else {
                puts("Yes");
                tag = 1;
                for(int i = 1; i <= n; i++) tmp[i] = 0;
                for(int i = now; i != s; i = pre[i]) tmp[i] = 1;
                tmp[s] = 1;
                int cnt = 0;
                for(int i = 1; i <= n; i++) if(!tmp[i]) cnt++;
                printf("%d\n", cnt);
                for(int i = 1; i <= n; i++) if(!tmp[i]) printf("%d ", i);
                puts("");
                return;
            }
        }
    }
}
int near[500010];
vector<int> ans;
int success;
inline void dfs2(int now, int f) {
    sta[++top] = now;
    vis[now] = 1;
    if(f && near[now] && !success) {
        for(int i = 1; i <= top; i++) ans.push_back(sta[i]);
        success = 1;
    }
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == f || du[e[i].v] != 2) continue;
        dfs2(e[i].v, now);
    }
    top--;
}
inline void case4() {
    for(int i = 1; i <= n; i++) vis[i] = near[i] = 0;
    ans.clear();
    int d;
    for(int i = 1; i <= n; i++) if(du[i] == 1) d = i;
    for(int i = head[d]; i; i = e[i].nxt) near[e[i].v] = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(near[i] && !vis[i]) {
            success = 0;
            top = 0;
            dfs2(i, 0);
            cnt += success;
            if(cnt == 2) break;
        }
    }
    if(cnt == 2 && ans.size() + 1 != n) {
        tag = 1;
        for(int i = 1; i <= n; i++) tmp[i] = 0;
        for(int i = 0; i < ans.size(); i++) tmp[ans[i]] = 1;
        tmp[d] = 1;
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(!tmp[i]) cnt++;
        printf("Yes\n%d\n", cnt);
        for(int i = 1; i <= n; i++) if(!tmp[i]) printf("%d ", i);
        puts("");
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) dis[i] = 0, head[i] = 0, du[i] = 0, insta[i] = 0, vis[i] = 0;
        top = tag = tot = 0;
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            du[u]++, du[v]++, addedge(u, v), addedge(v, u);
        }
        if(n <= 3) {
            puts("No");
            continue;
        }
        for(int i = 1; i <= n; i++) du[i] = du[i] % 3;
        for(int i = 1; i <= n; i++) {
            if(du[i] == 0) {
                tag = 1;
                printf("Yes\n%d\n", n - 1);
                for(int j = 1; j <= n; j++) if(i != j) printf("%d ", j);
                puts("");
                break;
            }
        }
        if(tag) continue;
        for(int i = 1; i <= n; i++) if(vis[i] == 0 && du[i] == 2) {
            dfs(i, 0);
            if(tag) break;
        }
        if(tag) continue;
        int cnt1 = 0;
        for(int i = 1; i <= n; i++) if(du[i] == 1) {
            cnt1++;
            bfs(i);
            if(tag) break;
        }
        if(tag) continue;
        if(cnt1 == 1) case4();
        if(tag) continue;
        puts("No");
    }
}