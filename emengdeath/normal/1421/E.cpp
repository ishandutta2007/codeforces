#include <cstdio>
#include <algorithm>
using namespace std;
long long f[2][3][2][2];
int n;
void upd(long long&a, long long b) {
    a = max(a,b);
}
int main() {
    scanf("%d", &n);
    if (n == 1) {
        int x;
        scanf("%d", &x);
        printf("%d\n" , x);
        return 0;
    }
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j < 2; j ++)
            for (int k = 0; k < 2; k ++)
                f[0][i][j][k] = f[1][i][j][k] = -1e18;
    f[0][0][0][0] = 0;
    bool bz = 0, bz1 = 1;
    bool _first = 1;
    while (n --) {
        int x;
        scanf("%d", &x);
        for (int i = 0; i < 3; i ++) {
            upd(f[bz1][(i+1) % 3][1][0], f[bz][i][1][0] + x);
            upd(f[bz1][(i+2) % 3][1][0], f[bz][i][1][0] - x);

            for (int k = 0; k < 2; k++) {
                if (!_first) {
                    if (k == 0) {
                        upd(f[bz1][(i+1) % 3][1][0], f[bz][i][0][k] + x);
                        upd(f[bz1][(i+2) % 3][0][1], f[bz][i][0][k] - x);
                    } else {
                        upd(f[bz1][(i+1) % 3][0][0], f[bz][i][0][k] + x);
                        upd(f[bz1][(i+2) % 3][1][0], f[bz][i][0][k] - x);
                    }
                } else {
                    upd(f[bz1][(i+1) % 3][0][0], f[bz][i][0][k] + x);
                    upd(f[bz1][(i+2) % 3][0][1], f[bz][i][0][k] - x);
                }
                f[bz][i][0][k] = -1e18;
            }
            f[bz][i][1][0] = -1e18;
        }
        _first = 0;
        swap(bz, bz1);
    }
    printf("%lld\n", f[bz][1][1][0]);
    return 0;
}