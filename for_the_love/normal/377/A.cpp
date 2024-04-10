/* &*#()&*#)&E*F& */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int N = 555;


int n, m, k, v[N][N];
char s[N][N];
void Dfs(int x, int y){
    v[x][y] = 1;
    k--;
    if (!k) return;
    for (int i = 0; i < 4; i++){
        int tx = x + dx[i], ty = y + dy[i];
        if (tx <= 0 || tx > n || ty <= 0 || ty > m || v[tx][ty] || s[tx][ty] == '#') continue;
        Dfs(tx, ty);
        if (!k) return;
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (s[i][j] == '.') cnt++;
    k = cnt - k;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (s[i][j] == '.'){
        Dfs(i, j);
        i = n + 1;
        break;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (s[i][j] == '.' && !v[i][j]) s[i][j] = 'X';
    for (int i = 1; i <= n; i++) printf("%s\n", s[i] + 1);
}