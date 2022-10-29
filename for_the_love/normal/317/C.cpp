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
struct Enode{
    int y, next;
} e[100005];

int n, limit, m, x, y, index[305], tot, a[305], st[305], stop, b[305], v[305], u[305], z[305], top, ans[90005][3], res;
long long sum1, sum2;

void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = index[x]; index[x] = tot;
    e[++tot].y = x; e[tot].next = index[y]; index[y] = tot;
}
void get(int x){
    int p = index[x];
    sum1 += a[x];
    sum2 += b[x];
    v[x] = 1;
    z[top++] = x;
    while (p != -1){
        int y = e[p].y;
        if (!v[y]) get(y);
        p = e[p].next;
    }
}
int dfs(int x, int des){
    int p = index[x];
    u[x] = 1;
    if (x == des){
        st[stop++] = x;
        return 1;
    }
    while (p != -1){
        int y = e[p].y;
        if (!u[y] && dfs(y, des)){
            st[stop++] = x;
            return 1;
        }
        p = e[p].next;
    }
    return 0;
}
void gao(int x, int t){
    if (x == 0) return;
    if (a[st[x - 1]] + t > limit){
        if (a[st[x - 1]] >= t){
            gao(x - 1, t);
            //printf("%d %d %d\n", z[x], z[x - 1], t);
            ans[res][0] = st[x];
            ans[res][1] = st[x - 1];
            ans[res++][2] = t;
        }else{
            //printf("%d %d %d\n", z[x], z[x - 1], t - a[z[x - 1]]);
            ans[res][0] = st[x];
            ans[res][1] = st[x - 1];
            ans[res++][2] = t - a[st[x - 1]];
            
            int tmp = a[st[x - 1]];
            a[st[x - 1]] = t;
            gao(x - 1, t);
            a[st[x - 1]]= tmp;
            
            ans[res][0] = st[x];
            ans[res][1] = st[x - 1];
            ans[res++][2] = a[st[x - 1]];
        }
    }else{
        ans[res][0] = st[x];
        ans[res][1] = st[x - 1];
        ans[res++][2] = t;
        gao(x - 1, t);
    }
}
int main(){
    scanf("%d%d%d", &n, &limit, &m);
   // for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    tot = -1; memset(index, -1, sizeof(index));
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        Addedge(x, y);
    }
    for (int i = 1; i <= n; i++)
    if (!v[i]){
        get(i);
        if (sum1 != sum2){
            puts("NO");
            return 0;
        }
    }
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++)
    if (!v[i]){
        top = 0;
        get(i);
        while (1){
            x = y = 0;
        for (int j = 0; j < top; j++)
        if (a[z[j]] > b[z[j]]){
            x = z[j];
            break;
        }
        for (int j = 0; j < top; j++)
        if (a[z[j]] < b[z[j]]){
            y = z[j];
            break;
        }
        if (!x && !y) break;
        memset(u, 0, sizeof(u));
        stop = 0;
        dfs(x, y);
        int tmp = min(a[x] - b[x], b[y] - a[y]);
        gao(stop - 1, tmp);
        a[x] -= tmp;
        a[y] += tmp;
        }
    }
    printf("%d\n", res);
    for (int i = 0; i < res; i++) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);

}