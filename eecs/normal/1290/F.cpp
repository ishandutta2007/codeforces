#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n, m, f[20][20][20][20][2][2], g[20][20][20][20][2][2];
int cnx[32], cpx[32], cny[32], cpy[32];

void red(int &x) { x += x >> 31 & P; }

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, x, y; i < n; i++) {
        scanf("%d %d", &x, &y);
        x < 0 ? cnx[1 << i] -= x : cpx[1 << i] += x;
        y < 0 ? cny[1 << i] -= y : cpy[1 << i] += y;
    }
    int U = (1 << n) - 1;
    for (int i = 1; i <= U; i++) {
        auto upd = [&](int *c) { c[i] = c[i & (i - 1)] + c[i & -i]; };
        upd(cnx), upd(cpx), upd(cny), upd(cpy);
    }
    for (******f = 1; m; m >>= 1, swap(f, g)) {
        int c = m & 1;
        memset(g, 0, sizeof(g));
        for (int nx = 0; nx <= cnx[U]; nx++) for (int px = 0; px <= cpx[U]; px++) {
            for (int ny = 0; ny <= cny[U]; ny++) for (int py = 0; py <= cpy[U]; py++) {
                for (int xm : {0, 1}) for (int ym : {0, 1}) if (f[nx][px][ny][py][xm][ym]) {
                    for (int C = 0; C <= U; C++) {
                        int _nx = nx + cnx[C], _px = px + cpx[C];
                        int _ny = ny + cny[C], _py = py + cpy[C];
                        if (((_nx ^ _px) | (_ny ^ _py)) & 1) continue;
                        red(g[_nx >> 1][_px >> 1][_ny >> 1][_py >> 1][(_nx ^ c) & 1 ? !c :
                            xm][(_ny ^ c) & 1 ? !c : ym] += f[nx][px][ny][py][xm][ym] - P);
                    }
                }
            }
        }
    }
    printf("%d\n", (******f + P - 1) % P);
    return 0;
}