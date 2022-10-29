#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
const int N = 501;
int n, m, q;
int a[N][N][4];
int f[251][N][N];
int all(int x, int y, int k) {
    x+= k - 1, y += k- 1;
    for (int i = 0; i < 4; i ++)
        if (a[x][y][i] - a[x - k][y][i] - a[x][y - k][i] + a[x - k][y - k][i] == k * k) return i;
    return -1;
}
bool have(int x, int y, int xx, int yy, int len) {
    if (!len) return 1;
    if (x > xx || y > yy) return 0;
    return f[len][xx][yy] - f[len][x - 1][yy] - f[len][xx][y - 1] + f[len][x - 1][y - 1];
}
int main() {
    map<char, int> ff;
    ff['R'] = 0;
    ff['G'] = 1;
    ff['Y'] = 2;
    ff['B'] = 3;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n ; i ++)
        for (int j = 1; j <= m; j ++) {
            char c;
            scanf(" %c", &c);
            a[i][j][ff[c]] ++;
            for (int k = 0; k < 4; k ++)
                a[i][j][k] += a[i - 1][j][k];
        }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            for (int k = 0; k < 4; k ++)
                a[i][j][k] += a[i][j - 1][k];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            for (int k = 1; all(i, j, k) == 0 ; k ++)
                if (all(i + k, j + k, k) == 3 && all(i + k, j, k) == 2 && all(i, j + k, k) == 1) {
                    for (int l = k; l >= 1; l --)
                        f[l][i + k - l][j + k - l] = 1;
                }
    int maxn = min(n, m) / 2;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            for (int l = 1; l <= maxn; l ++)
                f[l][i][j] += f[l][i -1][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            for (int l = 1; l <= maxn; l ++)
                f[l][i][j] += f[l][i][j - 1];
    while (q --) {
        int x, y, xx, yy;
        scanf("%d %d %d %d", &x, &y, &xx, &yy);
        int l = 0, r = maxn, mid, s = 0;
        while (l <= r) {
            mid = (l+ r) / 2;
            if (have(x, y, xx - mid * 2 +1, yy - mid * 2 + 1, mid)) s= max(s, mid), l = mid+ 1;
            else
                r = mid - 1;
        }
        printf("%d\n", s * s * 4);
    }
    return 0;
}