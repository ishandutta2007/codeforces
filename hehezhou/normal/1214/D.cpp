#include <bits/stdc++.h>
using namespace std;
char BUF[1000010];
char *a[1000010];
int n, m;
inline int dfs(int x, int y) {
    if(x == n || y == m) return 0;
    if(x == n - 1 && y == m - 1) return 1;
    if(a[x][y] == '#') return 0;
    if(x || y) a[x][y] = '#';
    return dfs(x + 1, y) || dfs(x, y + 1);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", BUF + i * m);
        a[i] = BUF + i * m;
    }
    return puts(dfs(0, 0) ? dfs(0, 0) ? "2" : "1" : "0");
}