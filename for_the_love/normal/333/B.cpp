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



int v[1005][1005], used[1005][1005], a[15], b[15], cnt, now, n, res, h[1005], s[1005];
void add(int x, int y){
    if (v[x][y]) return;
    a[++cnt] = x;
    b[cnt] = y;
    v[x][y] = 1;
}


int check(int x, int y){
    if (y == 1){
        if (used[1][x]) return 0;
        if (used[n][n - x + 1]) return 0;
    }
    if (y == n){
        if (used[1][n - x + 1]) return 0;
        if (used[n][x]) return 0;
    }
    if (x == 1){
        if (used[y][1]) return 0;
        if (used[n - y + 1][n]) return 0;
    }
    if (x == n){
        if (used[y][n]) return 0;
        if (used[n - y + 1][1]) return 0;
    }
    return 1;
}
void dfs(int k){
    if (now > res) res = now;
    if (k > cnt) return;
    if ((((b[k] == 1 || b[k] == n) &&! h[a[k]]) || ((a[k] == 1 || a[k] == n) && !s[b[k]])) && check(a[k], b[k])){
        h[a[k]] = 1;
        s[b[k]] = 1;
        used[a[k]][b[k]] = 1;
        now++;
        dfs(k + 1);
        used[a[k]][b[k]] = 0;
        now--;
        s[b[k]] = 0;
        h[a[k]] = 0;
    }
    dfs(k + 1);
}
int main(){
    int m, x, y, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        h[x] = 1;
        s[y] = 1;
        v[x][y] = 1;
    }
    for (int i = 2; i <= n - 1; i++){
        cnt = 0;
        add(i, 1);
        add(1, i);
        add(i, n);
        add(n, i);
        add(1, n - i + 1);
        add(n, n - i + 1);
        add(n - i + 1, 1);
        add(n - i + 1, n);
        now = 0;
        res = 0;
        dfs(1);
        ans += res;
    }
    printf("%d\n", ans);
}