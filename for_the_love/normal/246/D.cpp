#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Enode{
    int y, next;
} e[3000000];
int n, m, tot, top, ans;
int s[1000000], c[1000000], a[1000000], v[1000000], z[1000000];
void addedge(int x, int y){
    e[++tot].y = y; e[tot].next = a[x]; a[x] = tot;
    e[++tot].y = x; e[tot].next = a[y]; a[y] = tot;
}
void calc(int k){
    int p;
    p = a[k];
    while (p != -1){
        if (c[e[p].y] && c[e[p].y] != c[k] && !v[c[e[p].y]]){
            z[++top] = c[e[p].y];
            v[z[top]] = 1;
        }
        p = e[p].next;
    }
}
int main(){
    int i, p, x, y;
    scanf("%d%d", &n, &m);
    memset(a, -1, sizeof(a)); tot = -1;
    for (i = 1; i <= n; i++){
        scanf("%d", &c[i]);
        if (!v[c[i]]){
            v[c[i]] = 1;
            s[c[i]] = i;
        }
        addedge(s[c[i]] + n, i);
    }
    for (i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        addedge(x, y);
    }
    int res = 10000000;
    memset(v, 0 ,sizeof(v));
    for (i = 1; i <= n; i++)
    if (s[c[i]] == i){
        top = 0;
        p = a[i + n];
        while (p != -1){
            calc(e[p].y);
            p = e[p].next;
        }
        if (top > ans){
            res = c[i];
            ans = top;
        } else
        if (top == ans && c[i] < res){
            res = c[i];
        }
        while (top){
            v[z[top]] = 0;
            top--;
        }
    }
    printf("%d\n", res);
}