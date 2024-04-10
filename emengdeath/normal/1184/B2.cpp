#include <bits/stdc++.h>
#define N 107
#define S 1007
using namespace std;
int n, m, d[N][N], s, b, k, h;
struct spaceship { int x, a, f; } sp[S];
struct base { int x, d; } ba[S];
vector<int> to[S];
int c[S]; bool vis[S];
queue<int> q;
bool match(int x) {
    for(int y: to[x]) if(!vis[y]) {
        vis[y] = 1, q.push(y);
        if(!c[y] || match(c[y])) { c[y] = x; return 1; }
    }
    return 0;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j) if(i != j) d[i][j] = N;
    for(int i = 1, u, v; i <= m; ++ i) {
        scanf("%d%d", &u, &v);
        if(u == v) continue;
        d[u][v] = d[v][u] = 1;
    }
    for(int t = 1; t <= n; ++ t)
        for(int i = 1; i <= n; ++ i) if(i != t)
            for(int j = 1; j <= n; ++ j) if(j != t && j != i) d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
    scanf("%d%d%d%d", &s, &b, &k, &h);
    for(int i = 1; i <= s; ++ i) scanf("%d%d%d", &sp[i].x, &sp[i].a, &sp[i].f);
    for(int i = 1; i <= b; ++ i) scanf("%d%d", &ba[i].x, &ba[i].d);
    for(int i = 1; i <= s; ++ i)
        for(int j = 1; j <= b; ++ j)
            if(sp[i].a >= ba[j].d && d[sp[i].x][ba[j].x] < N && sp[i].f >= d[sp[i].x][ba[j].x]) to[i].push_back(j);
    int cnt = 0;
    for(int i = 1; i <= s; ++ i) {
        while(!q.empty()) vis[q.front()] = 0, q.pop();
        if(match(i)) ++ cnt;
    }
    long long ans = 1LL * cnt * k;
    for(int i = 1; i <= cnt; ++ i) ans = min(ans, 1LL * (s - cnt + i) * h + 1LL * (cnt - i) * k);
    cout << ans << endl;
}