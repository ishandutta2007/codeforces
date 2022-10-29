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


const int N = 333;

int e1[N * N], e2[N * N], a[N], v[N], e[333][333], n, cnt;
void Dfs(int x){
    v[x] = 1;
    for (int i = 1; i <= n; i++)
    if (e[x][i] && i != x && !v[i]){
        e[x][i] = e[i][x] = 0;
        e1[++cnt] = x; e2[cnt] = i;
        Dfs(i);
    }
}
int main(){
    int k, m;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++){
        scanf("%d", &a[i]);
        v[a[i]] = 1;
    }
    int x = 0, l, r;
    for (int i = 1; i <= n; i++)
    if (!v[i]){
        x = i;
        break;
    }
    if (!x){puts("-1");return 0;}
    l = a[1], r = a[2];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        e[i][j] = 1;
    e[l][r] = e[r][l] = 0;
    for (int i = 1; i <= n; i++)
    if (i != x && i != l && i != r && v[i]) e[l][i] = e[i][l] = 0;

    cnt = 0;
    memset(v, 0, sizeof(v));
    Dfs(1);
    if (cnt != n - 1) puts("-1");
    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
    if (e[i][j]){
        e1[++cnt] = i;
        e2[cnt] = j;
    }
    if (cnt < m){puts("-1");return 0;}
    for (int i = 1; i <= m; i++)
    printf("%d %d\n", e1[i], e2[i]);

}