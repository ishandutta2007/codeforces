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
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
struct Enode{
    int y, next;
} e[N + N];
int tot, head[N], deg[N], h[2], t[2], q[2][N + N], f[N], v[N], b[N];
void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = head[x]; head[x] = tot++; deg[y]++;
}

int main(){
    int n, m, x, y, st, ed;
    scanf("%d%d", &n, &m);
    tot = -1; memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        Addedge(y, x);
    }
    scanf("%d%d", &st, &ed);
    memset(f, 0x7f, sizeof(f));
    memset(v, 0, sizeof(v));
    memset(b, 0, sizeof(b));
    v[ed] = 1;
    f[ed] = 0;
    int now = 0;
    h[0] = 0; t[0] = 1;
    q[0][1] = ed;
    while (h[now] < t[now]){
        while (h[now] < t[now]){
            x = q[now][++h[now]];
            if (b[x]) continue;
            b[x] = 1;
            for (int p = head[x]; p != -1; p = e[p].next){
                if (!v[e[p].y]){
                    f[e[p].y] = f[x] + 1;
                    v[e[p].y] = 1;
                    q[now ^ 1][++t[now ^ 1]] = e[p].y;
                }
                deg[e[p].y]--;
                if (!deg[e[p].y] && f[e[p].y] > f[x]){
                    q[now][++t[now]] = e[p].y;
                    f[e[p].y] = f[x];
                }
            }
        }
        h[now] = t[now] = 0;
        now ^= 1;
    }
    if (f[st] > INF) puts("-1"); else printf("%d\n", f[st]);
}