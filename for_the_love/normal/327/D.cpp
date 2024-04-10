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
const int w[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n, m, i, j, res, h, t, ans[1000005][3], q[1000005][2], b[1000005];
char s[505][505];

void bfs(int x, int y){
    h = t; ++t; b[t] = 1;
    q[t][0] = x; q[t][1] = y;
    s[x][y] = '#';
    while (h < t){
        x = q[++h][0];
        y = q[h][1];
        for (int k = 0; k < 4; k++){
            int tx = x + w[k][0];
            int ty = y + w[k][1];
            if (tx < 1 || ty < 1 || tx > n || ty > m || s[tx][ty] == '#') continue;
            s[tx][ty] = '#';
            q[++t][0] = tx; q[t][1] = ty;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    if (s[i][j] == '.'){
        ans[++res][0] = 1;
        ans[res][1] = i;
        ans[res][2] = j;
    }
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    if (s[i][j] == '.') bfs(i, j);
    for (j = t; j >= 1; j--)
    if (!b[j]){
        ans[++res][0] = 3;
        ans[res][1] = q[j][0];
        ans[res][2] = q[j][1];
        ans[++res][0] = 2;
        ans[res][1] = q[j][0];
        ans[res][2] = q[j][1];
    }
    printf("%d\n", res);
    for (i = 1; i <= res; i++){
        if (ans[i][0] == 1) putchar('B');
        if (ans[i][0] == 2) putchar('R');
        if (ans[i][0] == 3) putchar('D');
        printf(" %d %d\n", ans[i][1], ans[i][2]);
    }
}