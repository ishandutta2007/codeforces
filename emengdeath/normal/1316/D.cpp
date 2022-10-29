#include <algorithm>
#include <cstdio>
using namespace std;
int n;
char s[1001][1001];
int tx[1001][1001], ty[1001][1001];
int b[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
char c[4] = {'U','D','R','L'}, d[4] = {'D','U','L','R'};
bool check(int x){
    return x > 0 && x <= n;
}
bool check(int x, int y) {
    return check(x) && check(y);
}
void dfs(int x, int y, char c, int xxx, int yyy) {
    if (s[x][y])return;
    s[x][y] = c;
    for (int i = 0; i < 4; i ++){
        int xx =x +b[i][0], yy = y + b[i][1];
        if (check(xx, yy) && tx[xx][yy] == xxx && ty[xx][yy] == yyy) {
            dfs(xx, yy, d[i], xxx, yyy);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1;j <= n; j ++)
            scanf("%d %d", &tx[i][j], &ty[i][j]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (tx[i][j] == i && j == ty[i][j]) {
                dfs(i, j, 'X', i, j);
            }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (tx[i][j] > 0 && ty[i][j] > 0 && !s[i][j]) {
                puts("INVALID");
                return 0;
            }
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            if (tx[i][j] < 0 && !s[i][j]) {
                for (int k = 0; k < 4; k ++) {
                    int x = i + b[k][0], y = j + b[k][1];
                    if (check(x, y) && tx[x][y] < 0) {
                        s[i][j] = c[k];
                        if (!s[x][y])
                            s[x][y] = d[k];
                        break;
                    }
                }
                if (!s[i][j]) {
                    puts("INVALID");
                    return 0;
                }
            }
    puts("VALID");
    for (int i = 1; i <= n; i ++, printf("\n"))
        for (int j = 1; j <= n; j ++)
            printf("%c", s[i][j]);
    return 0;
}