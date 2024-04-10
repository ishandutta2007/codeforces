#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 7;
struct Vnode{
    int a, b;
} tmp;
struct Enode{
    int y, next;
} e[N * 4];
int i, j, n, m, cnt, tot, num, flag, k, o, a[N * 2], q[N * 2], ans[N], d[N * 2], v[N * 2];
vector <Vnode> vec[N];

int cmp(Vnode a, Vnode b){return a.a < b.a;}
void addedge(int x, int y){
    e[++tot].y = y; e[tot].next = a[x]; a[x] = tot; d[y]++;
}
void bfs(int x){
    int y, p, h, t;
    h = 0; t = 1; q[1] = x;
    while (h < t){
        x = q[++h];
        v[x] = 1;
        num++;
        if (x < m) ans[o++] = x + 1;
        p = a[x];
        while (p != -1){
            y = e[p].y;
            d[y]--;
            if (!d[y]) q[++t] = y;
            p = e[p].next;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++){
        scanf("%d", &tmp.a);
        tmp.b = j;
        vec[i].push_back(tmp);
    }
    cnt = m - 1;
    tot = -1; memset(a, -1, sizeof(a));
    for (i = 0; i < n; i++){
        sort(vec[i].begin(), vec[i].end(), cmp);
        flag = 0;
        for (j = 0; j < m; j++){
            if (j && vec[i][j - 1].a != vec[i][j].a && vec[i][j - 1].a != -1){
                cnt++;
                flag = 1;
                for (k = j - 1; vec[i][k].a == vec[i][j - 1].a; k--)
                    addedge(vec[i][k].b, cnt);
            }
            if (flag) addedge(cnt, vec[i][j].b);
        }
    }
    for (i = 0; i < m; i++)
    if (!d[i] && !v[i]) bfs(i);
    if (num != cnt + 1) printf("-1\n");
    else for (i = 0; i < m; i++) printf("%d ", ans[i]);
}