#include <bits/stdc++.h>
using namespace std;
const int N = 22;
const int M = 365;
int Case, n, m;
bool g[N][M][4];
bool fin, vis[N][M];
inline void Dfs(int r, int theta) {
    if (r == 20) fin = 1;//, printf("* %d %d\n", r, theta);
    if (fin) return;
    if (vis[r][theta]) return;
    vis[r][theta] = 1;
    if (g[r][theta][0]) Dfs(r + 1, theta);
    if (r && g[r][theta][1]) Dfs(r - 1, theta);
    if (g[r][theta][2]) Dfs(r, (theta + 1) % 360);
    if (g[r][theta][3]) Dfs(r, (theta + 359) % 360);
}
int main() {
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        memset(g, 1, sizeof g);
        memset(vis, 0, sizeof vis);
        for (int i = 1, x, y, z; i <= n; ++i) {
            static char s[4];
            scanf("%s%d%d%d", s, &x, &y, &z);
            if (*s == 'C') {
                while (y != z) {
                    g[x - 1][y][0] = 0;
                    g[x][y][1] = 0;
                    ++y; if (y == 360) y = 0;
                }
            } else {
                int lz = z - 1;
                if (lz < 0) lz = 359;
                while (x != y) {
                    g[x][lz][2] = 0;
                    g[x][z][3] = 0;
                    ++x;
                }
            }
        }
        fin = 0;
        Dfs(0, 0);
        puts(fin ? "YES" : "NO");
    }
    return 0;
}