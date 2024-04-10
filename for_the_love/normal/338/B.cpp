#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 111111;
const int INF = 1e9 + 7;
struct Enode{
    int y, next;
} e[N * 2];

int head[N], c[N], d[N], dp[N][2], tot, f[N], mx, a, b;




void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].next = head[y]; head[y] = tot;
}

void Dfs(int x, int par, int depth){
    int t1 = 0, t2 = 0;
    d[x] = depth;
    for (int p = head[x]; p != -1; p = e[p].next)
    if (e[p].y != par){
        Dfs(e[p].y, x, depth + 1);
        if (d[f[e[p].y]] > d[t1]){
            t2 = t1;
            t1 = f[e[p].y];
        }else if (d[f[e[p].y]] > d[t2])
            t2 = f[e[p].y];
        if (d[f[e[p].y]] > d[f[x]]) f[x] = f[e[p].y];
    }
    if (t1 && t2 && d[t1] - depth + d[t2] - depth > mx){
        mx = d[t1] - depth + d[t2] - depth;
        a = t1;
        b = t2;
    }
    if (c[x]){
        if (!f[x]) f[x] = x;
        else if (d[f[x]] - depth > mx){
            mx = d[f[x]] - depth;
            a = f[x];
            b = x;
        }
    }
}

void Dfs1(int x, int pp, int par, int d){
    dp[x][pp] = d;
    for (int p = head[x]; p != -1; p = e[p].next)
    if (e[p].y != par) Dfs1(e[p].y, pp, x, d + 1);
}
int main(){
    int n, m, D, x, y;
    scanf("%d%d%d", &n, &m, &D);
    for (int i = 1; i <= m; i++){
        scanf("%d", &x);
        c[x] = 1;
    }
    tot = -1; memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        Addedge(x, y);
    }
    if (m == 1){
        for (int i = 1; i <= n; i++)
        if (c[i]){
            Dfs1(i, 0, 0, 0);
            break;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        if (dp[i][0] <= D) ans++;
        printf("%d\n", ans);
        return 0;
    }
    d[0] = -INF;
    Dfs(1, 0, 1);
    Dfs1(a, 0, 0, 0);
    Dfs1(b, 1, 0, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    if (dp[i][0] <= D && dp[i][1] <= D) ans++;
    printf("%d\n", ans);
}