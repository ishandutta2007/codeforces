#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1111;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int v[N][N], dp[N][N], s[N][N];
int n, m, found;
void Dfs(int x, int y){
    if (dp[x][y] != -1) return;
    v[x][y] = 1;
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m || (s[x][y] + 1) % 4 != s[xx][yy]) continue;
        if (v[xx][yy]){found = 1; return;}
        Dfs(xx, yy);
        if (found) return;
        dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
    }
    v[x][y] = 0;
}
char str[N];
int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++){
            if (str[j] == 'D') s[i][j] = 0;
            if (str[j] == 'I') s[i][j] = 1;
            if (str[j] == 'M') s[i][j] = 2;
            if (str[j] == 'A') s[i][j] = 3;
        }
    }
    found = 0;
    int ans = 0;
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (dp[i][j] == -1) Dfs(i, j);
    if (found){
        puts("Poor Inna!");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (!s[i][j]) ans = max(ans, dp[i][j] / 4);
    if (!ans) puts("Poor Dima!");
    else printf("%d\n", ans);


}