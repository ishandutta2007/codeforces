#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, i, t, flag, j, k, x, ans, c[105][105], e[105][105], v[105];

void dfs(int x){
    v[x] = 1;
    for (int y = 1; y <= n; y++)
    if (!v[y] && e[x][y]) dfs(y);
}

int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++){
        scanf("%d", &t);
        if (t) flag = 1;
        while (t--){
            scanf("%d", &x);
            c[i][x] = 1;
        }
    }
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    for (k = 1; k <= m; k++)
    if (i != j && c[i][k] && c[j][k]){
        e[i][j] = e[j][i] = 1;
        break;
    }
    for (i = 1; i <= n; i++)
    if (!v[i]){
        dfs(i);
        ans++;
    }
    if (!flag) printf("%d\n", n); else printf("%d\n", ans - 1);

}