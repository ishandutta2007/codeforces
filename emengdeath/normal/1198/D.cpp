#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 51;
int f[N][N][N][N];
int n;
char a[N][N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= n ; j ++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == '#')
                f[i][j][i][j] = 1;
        }
    for (int lenx = 1; lenx <= n; lenx ++)
        for (int leny = 1; leny <= n; leny ++)
            for (int x = 1; x + lenx - 1 <= n ; x ++) {
                if (lenx == 1 && leny == 1) continue;
                int xx = x + lenx - 1;
                for (int y = 1; y + leny - 1 <= n; y++) {
                    int yy = y + leny - 1;
                    f[x][y][xx][yy] = max(lenx, leny);
                    for (int mid = x; mid < xx; mid ++)
                        f[x][y][xx][yy] = min(f[x][y][xx][yy], f[x][y][mid][yy] + f[mid + 1][y][xx][yy]);
                    for (int mid = y; mid < yy; mid ++)
                        f[x][y][xx][yy] = min(f[x][y][xx][yy], f[x][y][xx][mid] + f[x][mid + 1][xx][yy]);
                }
            }
    printf("%d\n", f[1][1][n][n]);
    return 0;
}