#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Enode{
    int y, next;
} e[200005];
int a[100005], x, y, n, i, tot;
double ans;

void addedge(int x, int y){
    e[++tot].y = y; e[tot].next = a[x]; a[x] = tot;
    e[++tot].y = x; e[tot].next = a[y]; a[y] = tot;
}
void dfs(int x, int par, int dep){
    ans += 1.0 / dep;
    int p = a[x];
    while (p != -1){
        if (e[p].y != par) dfs(e[p].y, x, dep + 1);
        p = e[p].next;
    }
}
int main(){
    scanf("%d", &n);
    tot = -1; memset(a, -1, sizeof(a));
    for (i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        addedge(x, y);
    }
    dfs(1, 0, 1);
    printf("%lf", ans);
}