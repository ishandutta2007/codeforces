#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 7;
struct Fnode{
    int b,pre,c,w;
} f[10005];
struct Enode{
    int y,c,w,next;
} e[100005];
int v[10005], a[10005], q[2000005], tot, st, ed, ans, flow, c[100][100];
void Addedge(int x, int y, int c, int w){
    e[++tot].y = y; e[tot].c = c; e[tot].w = w; e[tot].next = a[x]; a[x] = tot;
    e[++tot].y = x; e[tot].c = 0; e[tot].w = -w; e[tot].next = a[y]; a[y] = tot;
}
int find(){
    int h, t, p, x, y, i;
    for (i = st; i <= ed; i++){
        f[i].b = -1; f[i].pre = -1; f[i].c = 0; f[i].w = INF;
    }
    h=0;t=1;q[1]=st;f[st].c=INF;f[st].w=0;v[st]=1;
    while (h!=t){
        h++; x=q[h]; p=a[x];
        while (p!=-1){
            y=e[p].y;
            if (e[p].c>0&&f[x].w+e[p].w<f[y].w){
                f[y].w=f[x].w+e[p].w;
                if (f[x].c<e[p].c) f[y].c=f[x].c; else f[y].c=e[p].c;
                f[y].b=p; f[y].pre=x;
                if (!v[y]){
                    t++;q[t]=y;v[y]=1;
                }
            }
            p=e[p].next;
        }
        v[x]=0;
    }
    if (f[ed].w==INF) return 0;
    p=ed; ans+=f[ed].w*f[ed].c; flow+=f[ed].c;
    while (f[p].b!=-1){
        e[f[p].b].c-=f[ed].c; e[f[p].b^1].c+=f[ed].c; p=f[p].pre;
    }
}
int main(){
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
        scanf("%d", &c[i][j]);
    st = 0; ed = n * m + 1;
    tot = -1; memset(a, -1, sizeof(a));
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    if ((i + j) % 2 == 0){
        if (i > 1) Addedge((i - 1) * m + j, (i - 2) * m + j, 1, c[i][j] != c[i - 1][j]);
        if (i < n) Addedge((i - 1) * m + j, i * m + j, 1, c[i][j] != c[i + 1][j]);
        if (j > 1) Addedge((i - 1) * m + j, (i - 1) * m + j - 1, 1, c[i][j] != c[i][j - 1]);
        if (j < m) Addedge((i - 1) * m + j, (i - 1) * m + j + 1, 1, c[i][j] != c[i][j + 1]);
        Addedge(st, (i - 1) * m + j, 1, 0);
    }else Addedge((i - 1) * m + j, ed, 1, 0);
    while (find());
    printf("%d\n", ans);
}