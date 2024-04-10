#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long INF = 1e15 + 7;
const int N = 1e5 + 7;
struct enode{
    int y, next;
} e[N * 2];

int n, x, y, i, tot, a[N];
long long c[N], mx[N], mn[N];
void addedge(int x, int y){
    e[++tot].y = y; e[tot].next = a[x]; a[x] = tot;
    e[++tot].y = x; e[tot].next = a[y]; a[y] = tot;
}
void dfs(int x, int par){
    int p = a[x];
    while (p != -1){
        int y = e[p].y;
        if (y != par){
            dfs(y, x);
            if (c[y] > 0) mn[x] = max(mn[x], mn[y] + c[y]); else mn[x] = max(mn[x], mn[y]);
            if (c[y] < 0) mx[x] = max(mx[x], mx[y] - c[y]); else mx[x] = max(mx[x], mx[y]);
        }
        p = e[p].next;
    }
    c[x] = c[x] - mn[x] + mx[x];
}
int main(){
    scanf("%d", &n);
    tot = -1; memset(a, -1, sizeof(a));
    for (i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        addedge(x, y);
    }
    for (i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1, 0);
    cout << abs(c[1]) + mx[1] + mn[1] << endl;
}