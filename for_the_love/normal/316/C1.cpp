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

int n, m, i, j, a[15][15], ans, v[15][15];
void dfs(int i, int j, int now){
    if (now >= ans) return;
    if (i > n){
        ans = now;
        return;
    }
    if (v[i][j]){
        if (j == m) dfs(i + 1, 1, now); else dfs(i, j + 1, now);
        return;
    }
    if (i < n && !v[i + 1][j]){
        v[i][j] = v[i + 1][j] = 1;
        if (j == m) dfs(i + 1, 1, now + (a[i][j] != a[i + 1][j])); else dfs(i, j + 1, now + (a[i][j] != a[i + 1][j]));
        v[i][j] = v[i + 1][j] = 0;
    }
    if (j < m && !v[i][j + 1]){
        v[i][j] = v[i][j + 1] = 1;
        if (j == m) dfs(i + 1, 1, now + (a[i][j] != a[i][j + 1])); else dfs(i, j + 1, now + (a[i][j] != a[i][j + 1]));
        v[i][j] = v[i][j + 1] = 0;
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
        scanf("%d", &a[i][j]);
    memset(v, 0, sizeof(v));
    ans = 1e9;
    dfs(1, 1, 0);
    printf("%d\n", ans);
}