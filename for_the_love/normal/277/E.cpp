#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 405;
const int INF = 1e9 + 7;
struct Enode{
    int y, c, next;
    double w;
} e[N * N * 3];
struct Fnode{
    int b, c, pre;
    double w;
} f[N * 3];
int n, st, ed, i, j, x[N], y[N], v[N * 3], flow, tot, a[N * 3];
double ans;
queue <int> q;
void addedge(int x, int y, int c, double w){
    e[++tot].y = y; e[tot].c = c; e[tot].w = w; e[tot].next = a[x]; a[x] = tot;
    e[++tot].y = x; e[tot].c = 0; e[tot].w = -w; e[tot].next = a[y]; a[y] = tot;
}

int find(){
    int x, y, i, p;
    for (i = st; i <= ed; i++){
        f[i].b = -1; f[i].pre = -1; f[i].w = INF;
    }
    f[st].w = 0;
    f[st].c = INF;
    q.push(st);
    while (!q.empty()){
        x = q.front();
        q.pop();
        p = a[x];
        while (p != -1){
            y = e[p].y;
            if (e[p].c && f[x].w + e[p].w < f[y].w){
                f[y].w = f[x].w + e[p].w;
                f[y].b = p;
                f[y].c = min(f[x].c, e[p].c);
                f[y].pre = x;
                if (!v[y]){
                    v[y] = 1;
                    q.push(y);
                }
            }
            p = e[p].next;
        }
        v[x] = 0;
    }
    if (f[ed].w == INF) return 0;
    ans += f[ed].w * f[ed].c;
    flow += f[ed].c;
    p = ed;
    while (p != st){
        e[f[p].b].c -= f[ed].c;
        e[f[p].b ^ 1].c += f[ed].c;
        p = f[p].pre;
    }
    return 1;
}
int main(){
    scanf("%d", &n);
    st = 0; ed = n + n + 1;
    for (i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    tot = -1; memset(a, -1, sizeof(a));
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    if (y[j] < y[i]) addedge(i, j + n, 1, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
    for (i = 1; i <= n; i++){
        addedge(st, i, 2, 0);
        addedge(i + n, ed, 1, 0);
    }
    flow = 0;
    while (find());
    if (flow == n - 1) printf("%.8lf\n", ans); else printf("-1\n");
}